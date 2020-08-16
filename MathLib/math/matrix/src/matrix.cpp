#include <iostream>
#include <myMath.h>


Matrix::Matrix(uint16_t row, uint16_t col) : Row(row), Col(col), MatrixBase(NULL)
{
	if (col != 0)
	{
		Allocate_Mem(row, col);
	}
	else
	{
		std::cout << "Matrix creation failed invalid column value!" << std::endl;
	}
}

Matrix::~Matrix()
{
	De_Allocate_Mem();
}

void Matrix::Allocate_Mem(uint16_t row, uint16_t col)
{
	MatrixBase = new double* [row];

	for (uint16_t r = 0; r < row; r++)
	{
		MatrixBase[r] = new double[col];
	}
}

void Matrix::De_Allocate_Mem(void)
{
	if (MatrixBase != NULL)
	{
		for (uint16_t r = 0; r < Row; r++)
		{
			delete MatrixBase[r];
		}

		delete MatrixBase;

		MatrixBase = NULL;
	}
}

double* Matrix::operator[] (uint16_t index)
{
	return MatrixBase[index];
}

std::ostream& operator << (std::ostream& out, Matrix &obj)
{
	uint16_t i, j;

	for (i = 0; i < obj.Row; i++)
	{
		for (j = 0; j < obj.Col; j++)
		{
			std::cout << obj[i][j] << " ";
		}
		out << std::endl;
	}

	return out;
}

void Matrix::operator = (Matrix& rhs)
{
	De_Allocate_Mem();

	this->Row = rhs.Row;
	this->Col = rhs.Col;

	Allocate_Mem(this->Row, this->Col);

	for (uint16_t i = 0; i < this->Row; i++)
	{
		memcpy(this->MatrixBase[i],rhs.MatrixBase[i],(sizeof(double) * this->Col));
	}
}

Matrix& operator + (Matrix& ls, Matrix& rs)
{

}