#ifndef PARTICLE_H
#define PARTICLE_H

// include
#include "Vect4D.h"

class Particle
{
public:
	friend class ParticleEmitter;
	
	Particle();	
	~Particle();
	void Update(const double& time_elapsed);
	void CopyDataOnly( Particle *p );
private:
	Particle *next;
	Particle *prev;

	Vect4D	prev_Row0;
	Vect4D	prev_Row1;
	Vect4D  prev_Row2;
	Vect4D  prev_Row3;

	Vect4D	position;
	double	life;
	Vect4D	velocity;
	Vect4D	scale;
	double	rotation;
	Vect4D  diff_Row0;
	Vect4D  diff_Row1;
	Vect4D  diff_Row2;
	Vect4D  diff_Row3;
	double	rotation_velocity;
	
	Vect4D	curr_Row0;
	Vect4D	curr_Row1;
	Vect4D  curr_Row2;
	Vect4D  curr_Row3;
};


#endif //PARTICLE_H
