#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class __declspec(align(16)) Particle
{
public:
	friend class ParticleEmitter;
	
	Particle();	
	//Particle(const Particle &tmp);
	~Particle();
	void Update(const float& time_elapsed);
public:
	Vect4D	prev_Row0;
	Vect4D	prev_Row1;
	Vect4D  prev_Row2;
	Vect4D  prev_Row3;

	Vect4D  diff_Row0;
	Vect4D  diff_Row1;
	Vect4D  diff_Row2;
	Vect4D  diff_Row3;
	
	Vect4D	curr_Row0;
	Vect4D	curr_Row1;
	Vect4D  curr_Row2;
	Vect4D  curr_Row3;

	Vect4D	position;
	Vect4D	velocity;
	Vect4D	scale;

	float	life;
	float	rotation;

	Particle *next;
	Particle *prev;
};

#endif //PARTICLE_H
