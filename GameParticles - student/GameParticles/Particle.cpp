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
}


Particle::~Particle()
{
	// nothing to do
}

void Particle::Update(const float& time_elapsed)
{
	Vect4D tmp_Row;
	tmp_Row = curr_Row0;
	prev_Row0 = tmp_Row;

	tmp_Row = curr_Row1;
	prev_Row1 = tmp_Row;

	tmp_Row = curr_Row2;
	prev_Row2 = tmp_Row;

	tmp_Row = curr_Row3;
	prev_Row3 = tmp_Row;

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

	rotation += scale + 0.5f * time_elapsed * 2.01f;
}


// End of file


