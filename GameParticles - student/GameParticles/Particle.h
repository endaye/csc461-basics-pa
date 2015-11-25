#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class __declspec(align(16)) Particle
{
public:
	friend class ParticleEmitter;
	
	Particle();	
	~Particle();
	void setNext(Particle * n);
	void Update(const float& time_elapsed);
	void updatePos(Vect4D &pos, const Vect4D &vect, const float time_elapsed) const;
public:
	Vect4D	position;
	Vect4D	velocity;
	Particle *next;
	float	life;
	float	scale;
	float	rotation;
};

#endif //PARTICLE_H
