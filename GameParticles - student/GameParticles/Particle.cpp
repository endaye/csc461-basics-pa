#include "Particle.h"
#include "Matrix.h"

Particle::Particle()
{
	// construtor
	this->life = 0.0f;
	this->scale = 1.0f;
	this->position.set(0.0f);
	this->velocity.set(0.0f);
	this->rotation = 0.0f;
}


Particle::~Particle()
{
	// nothing to do
}

void Particle::setNext(Particle * n)
{
	this->next = n;
}

void Particle::updatePos(Vect4D &pos, const Vect4D &vel, const float time_elapsed) const
{
	pos.m = _mm_add_ps(pos.m, _mm_mul_ps(vel.m, _mm_set1_ps(time_elapsed)));
}

void Particle::Update(const float& time_elapsed)
{
	// serious math below - magic secret sauce
	life += time_elapsed;
	updatePos(position, velocity, time_elapsed);
	position.updatePos(life);
	rotation += 1.0f + 0.5f * time_elapsed * 2.01f;
}

// End of file


