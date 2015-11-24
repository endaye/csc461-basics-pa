#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "Math\Matrix.h"
#include "Math\Vect4D.h"
#include "Particle.h"

#include <list>

class ParticleEmitter
{
public:
	ParticleEmitter();
	~ParticleEmitter();

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc) const;
	void update();
	void draw();
	void CreateLinkedList();
	
public:

	const Vect4D	start_position;
	const Vect4D	start_velocity;

	const float		max_life;
	const int		max_particles;
	const int randHalf;
	const float varM;

	float	last_loop;

	Particle *headParticle;

	Matrix cameraMatrix;
	Vect4D camPosVect;
};

#endif // PARTICLEEMITTER_H
