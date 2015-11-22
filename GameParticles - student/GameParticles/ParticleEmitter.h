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

	void SpawnParticle();
	void update();
	void draw();

	void addParticleToList(Particle *p);
	void removeParticleFromList(Particle *p);

	void Execute(Vect4D& pos, Vect4D& vel, Vect4D& sc);

public:

	const Vect4D	start_position;
	const Vect4D	start_velocity;

	const float		max_life;
	const int		max_particles;
	const float		spawn_frequency;
	const int randHalf;
	const float varM;

	float	last_spawn;
	float	last_loop;
	int		last_active_particle;


	// added for speed efficiency
	int bufferCount;
	float	scale_variance;
	std::list<Particle> drawBuffer;
	Particle *headParticle;
	std::list<Particle> particle_list;
	Matrix cameraMatrix;
	Vect4D camPosVect;
};

#endif // PARTICLEEMITTER_H
