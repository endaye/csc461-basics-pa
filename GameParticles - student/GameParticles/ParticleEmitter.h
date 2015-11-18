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

private:

	Vect4D	start_position;
	Vect4D	start_velocity;

	float	max_life;
	int		max_particles;
	float	spawn_frequency;
	float	last_spawn;
	float	last_loop;
	int		last_active_particle;

	// added for speed efficiency
	int bufferCount;
	Vect4D	vel_variance;
	Vect4D	pos_variance;
	float	scale_variance;
	std::list<Particle> drawBuffer;
	Particle *headParticle;
	std::list<Particle> particle_list;

};

#endif // PARTICLEEMITTER_H
