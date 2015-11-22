#include "Particle.h"
#include "Matrix.h"

Particle::Particle()
{
	// construtor
	this->life = 0.0f;
	this->position.set(0.0f, 0.0f, 0.0f);
	this->velocity.set(0.0f, 0.0f, 0.0f);
	this->scale.set(1.0f, 1.0f, 1.0f);
	this->rotation = 0.0f;
	this->rotation_velocity = 0.5f;

}


Particle::~Particle()
{
	// nothing to do
}

void Particle::CopyDataOnly(Particle *p)
{
	// copy the data only
	// this way of copying data is more efficient that element by element
	this->position = p->position;
	this->velocity = p->velocity;
	this->scale = p->scale;
	this->rotation = p->rotation;
	this->rotation_velocity = p->rotation_velocity;
	this->life = p->life;
}

void Particle::Update(const float& time_elapsed)
{
	// Rotate the matrices
	Vect4D tmp_Row0;
	tmp_Row0 = curr_Row0;
	prev_Row0 = tmp_Row0;

	Vect4D tmp_Row1;
	tmp_Row1 = curr_Row1;
	prev_Row1 = tmp_Row1;

	Vect4D tmp_Row2;
	tmp_Row2 = curr_Row2;
	prev_Row2 = tmp_Row2;

	Vect4D tmp_Row3;
	tmp_Row3 = curr_Row3;
	prev_Row3 = tmp_Row3;

	Matrix tmp;

	tmp.set(Matrix::MATRIX_ROW_0, this->diff_Row0);
	tmp.set(Matrix::MATRIX_ROW_1, this->diff_Row1);
	tmp.set(Matrix::MATRIX_ROW_2, this->diff_Row2);
	tmp.set(Matrix::MATRIX_ROW_3, this->diff_Row3);

	float scale = tmp.Determinant();

	// serious math below - magic secret sauce
	life += time_elapsed;
	position = position + (velocity * time_elapsed);
	//Vect4D z_axis(0.0f, -0.25f, 1.0f);
	//Vect4D v(3.0f, 4.0f, 0.0f);
	//Vect4D v;
	//position.Cross(z_axis, v);
	//v.norm(v);
	//position += v * (0.05f * life);
	position.updatePos(life);
	if (scale > 1.0f)
	{
		scale = 1.0f / scale;
	};

	rotation = rotation + scale + rotation_velocity * time_elapsed * 2.01f;
}


// End of file


