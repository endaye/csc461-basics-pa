#include "DO_NOT_MODIFY\Timer\Timer.h"
#include "DO_NOT_MODIFY\Timer\GlobalTimer.h"
#include "DO_NOT_MODIFY\OpenGL\OpenGLInterface.h"

#include <assert.h>
#include <xmmintrin.h>
#include <smmintrin.h> 

#include "ParticleEmitter.h"
#include "Settings.h"

static const unsigned char squareColors[] =
{
	255, 255, 000, 255,
	000, 255, 255, 255,
	000, 000, 000, 000,
	255, 000, 255, 255,
};

static const float squareVertices[] =
{
	-0.015f, -0.015f,  0.0f,
	 0.015f, -0.015f,  0.0f,
	-0.015f,  0.015f,  0.0f,
	 0.015f,  0.015f,  0.0f,
};


ParticleEmitter::ParticleEmitter()
	: start_position(0.0f, 0.0f, 0.0f),
	start_velocity(0.0f, 1.0f, 0.0f),
	max_life(MAX_LIFE),
	max_particles(NUM_PARTICLES),
	randHalf(RAND_MAX / 2),
	varM(1.0f / (static_cast <float> (randHalf))),
	last_loop(globalTimer::getTimerInSec())
{
	CreateLinkedList();
}


ParticleEmitter::~ParticleEmitter()
{
	// do nothing
}

/*
tmp = scaleMatrix * transCamera * transParticle * rotParticle * scaleMatrix;

scaleMatrix(p->scale)
{	sx		0		0		0	}
{	0		sy		0		0	}
{	0		0		sz		0	}
{	0		0		0		1	}

transCamera(cameraMatrix.v3)
(   1,    0,    0,   0);
(   0,    1,    0,   0);
(   0,    0,    1,   0);
(tc.x, tc.y, tc.z,   1);

transParticle(p->position)
(   1,    0,    0,   0);
(   0,    1,    0,   0);
(   0,    0,    1,   0);
(tp.x, tp.y, tp.z,   1);

rotParticle (const float &az)
{	cos		-sin	0		0	}
{	sin		cos		0		0	}
{	0		0		1		0	}
{	0		0		0		1	}

scaleMatrix * scaleMatrix;
{	sx*sx	0		0		0	}
{	0		sy*sy	0		0	}
{	0		0		sz*sz	0	}
{	0		0		0		1	}

transCamera * transParticle
(        1,         0,         0,   0);
(        0,         1,         0,   0);
(        0,         0,         1,   0);
(tc.x+tp.x, tc.y+tp.y, tc.z+tp.z,   1);

scaleMatrix * scaleMatrix * transCamera * transParticle
{	sx*sx	    	0		    	0			    0	}
{	0		    	sy*sy	    	0			    0	}
{	0		    	0		    	sz*sz		    0	}
{	sx*sx*(tcx+tpx)	sy*sy*(tcy+tpy)	sz*sz*(tcz+tpz)	1	}

scaleMatrix * scaleMatrix * transCamera * transParticle * rotParticle
{	sx*sx*cos	    sy*sy*(-sin)    0			    0	}
{	sx*sx*sin		sy*sy*cos	    0			    0	}
{	0		    	0		    	sz*sz		    0	}
{	sx*sx*(tcx+tpx)	sy*sy*(tcy+tpy)	sz*sz*(tcz+tpz)	1	}

*/
void ParticleEmitter::TotalTransform(Matrix &out, const float &scale, const Vect4D &TrCam, const Vect4D &TrPtc, const float rot)
{
	
	float tmpSc = scale * scale;
	Vect4D tmpTrans(_mm_add_ps(TrPtc.m, TrCam.m));
	float sin = sinf(rot);
	float cos = cosf(rot);
	out.m0 = cos * tmpSc;
	out.m1 = (-sin) * tmpSc;
	out.m4 = sin * tmpSc;
	out.m5 = cos * tmpSc;
	out.m10 = tmpSc;
	out.m12 = tmpSc * tmpTrans.x;
	out.m13 = tmpSc * tmpTrans.y;
	out.m14 = tmpSc * tmpTrans.z;
}

void ParticleEmitter::Execute(Vect4D& pos, Vect4D& vel, float& sc) const
{
	// Add some randomness...
	float var0 = static_cast <float> (rand() - this->randHalf) * this->varM;
	float var1 = static_cast <float> (rand() - this->randHalf) * this->varM;
	float var2 = static_cast <float> (rand() - this->randHalf) * this->varM;
	pos.x += var0;
	pos.y += var1;
	pos.z += var2;
	//pos += Vect4D(var0, var1, var2, 0.0f);
	var0 = static_cast <float> (rand() - this->randHalf) * this->varM;				// * 1.0f
	var1 = static_cast <float> ((rand() - this->randHalf) * 4) * this->varM;		// * 4.0f
	var2 = static_cast <float> (rand() - this->randHalf) * this->varM * 0.4f;		// * 0.4f
	vel.x += var0;
	vel.y += var1;
	vel.z += var2;
	//vel += Vect4D(var0, var1, var2, 0.0f);
	sc = static_cast <float> ((rand() - this->randHalf) * 2) * this->varM;
}

void ParticleEmitter::update()
{
	// get current time
	float current_time = globalTimer::getTimerInSec();

	float time_elapsed = current_time - last_loop;

	Particle *p = this->headParticle;

	while (p != 0)
	{
		// call every particle and update its position 
		
		if (p->life < max_life)
		{
			p->Update(time_elapsed);
		}
		else
		{
			p->life = 0.0f;
			p->position = start_position;
			p->velocity = start_velocity;
			p->scale = 1.0f;
			this->Execute(p->position, p->velocity, p->scale);
		}
		p = p->next;
	}

	//move a copy to vector for faster iterations in draw
	p = this->headParticle;


	// make sure the counts track (asserts go away in release - relax Christos)
	last_loop = current_time;
}

void ParticleEmitter::draw()
{
	// get the camera matrix from OpenGL
	// need to get the position
	Matrix cameraMatrix;

	// get the camera matrix from OpenGL
	glGetFloatv(GL_MODELVIEW_MATRIX, reinterpret_cast<float*>(&cameraMatrix));

	// OpenGL goo... don't worrry about this
	glVertexPointer(3, GL_FLOAT, 0, squareVertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_UNSIGNED_BYTE, 0, squareColors);
	glEnableClientState(GL_COLOR_ARRAY);

	// camera position: setTransMatrix(const Vect4D &t)
	// particle position
	// rotation matrix
	// scale Matrix	
	Matrix tmp;
	tmp.setIdentMatrix2();

	// iterate throught the list of particles
	Particle *p = this->headParticle;
	while (p != 0)
	{
		// particle position: setTransMatrix(const Vect4D &t)

		//tmp = scaleMatrix * scaleMatrix * transCamera * transParticle * rotParticle;
		TotalTransform(tmp, p->scale, cameraMatrix.v3, p->position, p->rotation);

		// squirrel away matrix for next update
		//tmp.get(p->curr_Row0, p->curr_Row1, p->curr_Row2, p->curr_Row3);

		// set the transformation matrix
		glLoadMatrixf(reinterpret_cast<float*>(&(tmp)));
		// draw the trangle strip
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		
		// clears or flushes some internal setting, used in debug, but is need for performance reasons
		// magic...  really it's magic.
		GLenum glError = glGetError();
		glError;

		p = p->next;
	}
}


void ParticleEmitter::CreateLinkedList()
{
	// initialize it NULL
	headParticle = 0;

	// create the space
	Particle *p = (Particle*)_aligned_malloc(sizeof(Particle) * max_particles, 16);

	// head
	headParticle = p;

	// some markers...
	Particle *pFirst = p;
	Particle *pLast = p + max_particles - 1;
	Particle *pCurr = pFirst;

	// initialize the all nodes
	for (int i = 0; i < max_particles; ++i)
	{
		pCurr->setNext(pCurr + 1);
		pCurr->life = 0.0f;
		pCurr->scale = 1.0f;
		pCurr->position = start_position;
		pCurr->velocity = start_velocity;
		// apply the variance
		this->Execute(pCurr->position, pCurr->velocity, pCurr->scale);
		pCurr++;
	}

	// fix up the first and last node
	pLast->setNext(0);
}


// End of file