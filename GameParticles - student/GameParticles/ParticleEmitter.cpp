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
	// nothing to do
}


ParticleEmitter::~ParticleEmitter()
{
	// do nothing
}


void ParticleEmitter::Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc)
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
	var2 = static_cast <float> (rand() - this->randHalf) * this->varM * 0.4f;	// * 0.4f
	vel.x += var0;
	vel.y += var1;
	vel.z += var2;
	//vel += Vect4D(var0, var1, var2, 0.0f);
	var0 = static_cast <float> ((rand() - this->randHalf) * 2) * this->varM;
	sc *= var0;
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
			p->scale.set(1.0f);
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

	// get the position from this matrix
	Vect4D camPosVect;
	cameraMatrix.get(Matrix::MATRIX_ROW_3, camPosVect);

	// camera position
	Matrix transCamera;
	transCamera.setTransMatrix(camPosVect);

	// particle position
	Matrix transParticle;

	// rotation matrix
	Matrix rotParticle;

	// pivot Point
	Matrix pivotParticle;
	Vect4D pivotVect;

	// scale Matrix
	Matrix scaleMatrix;

	//Temporary matrix
	Matrix tmp;

	// iterate throught the list of particles

	Particle *p = this->headParticle;
	int cnt = 0;
	while (cnt < max_particles)
	{
		// particle position
		transParticle.setTransMatrix(p->position);

		// rotation matrix
		rotParticle.setRotZMatrix(p->rotation);

		// pivot Point
		pivotVect.set(1.0f, 0.0f, 50.0f);
		pivotVect *= (20.0f * p->life);
		pivotParticle.setTransMatrix(pivotVect);

		// scale Matrix
		scaleMatrix.setScaleMatrix(p->scale);

		// total transformation of particle
		tmp = scaleMatrix * transCamera * transParticle * rotParticle * scaleMatrix;

		// squirrel away matrix for next update
		tmp.get(p->curr_Row0, p->curr_Row1, p->curr_Row2, p->curr_Row3);

		// set the transformation matrix
		glLoadMatrixf(reinterpret_cast<float*>(&(tmp)));
		// draw the trangle strip
		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
		
		// difference vector
		p->diff_Row0 = p->curr_Row0 - p->prev_Row0;
		p->diff_Row1 = p->curr_Row1 - p->prev_Row1;
		p->diff_Row2 = p->curr_Row2 - p->prev_Row2;
		p->diff_Row3 = p->curr_Row3 - p->prev_Row3;

		// clears or flushes some internal setting, used in debug, but is need for performance reasons
		// magic...  really it's magic.
		GLenum glError = glGetError();
		glError;

		p = p->next;
		cnt++;
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
		pCurr->setPrev(pCurr - 1);
		pCurr->life = 0.0f;
		pCurr->position = start_position;
		pCurr->velocity = start_velocity;
		pCurr->scale.set(1.0f, 1.0f, 1.0f, 1.0f);

		// apply the variance
		this->Execute(pCurr->position, pCurr->velocity, pCurr->scale);
		pCurr++;
	}

	// fix up the first and last node
	pLast->setNext(0);
	pFirst->setPrev(0);
}


// End of file