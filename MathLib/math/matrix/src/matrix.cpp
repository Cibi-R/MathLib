#include <iostream>
#include <myMath.h>


void MyMath::Matrix::Allocate_Mem(uint16_t row, uint16_t col)
{
	MatrixBase = new double* [row];

	for (uint16_t r = 0; r < row; r++)
	{
		MatrixBase[r] = new double[col];
	}
}

void MyMath::Matrix::Delete(void)
{
	if (MatrixBase != NULL)
	{
		for (uint16_t r = 0; r < Row; r++)
		{
			delete MatrixBase[r];
		}

		delete MatrixBase;

		Row = 0;
		Col = 0;

		MatrixBase = NULL;
	}
}

MyMath::Matrix::Matrix() : Row(0), Col(0), MatrixBase(NULL)
{

}

MyMath::Matrix::Matrix(uint16_t row, uint16_t col) : MatrixBase(NULL)
{
	if ((0 < row) && (0 < col))
	{
		Row = row;
		Col = col;

		Allocate_Mem(row, col);
	}
}

MyMath::Matrix::~Matrix()
{
	/* DO NOTHING */
}

void MyMath::Matrix::Create(uint16_t row, uint16_t col)
{
	if ((0 < row) && (0 < col))
	{
		if (MatrixBase != NULL)
		{
			Delete();
		}

		this->Row = row;
		this->Col = col;

		Allocate_Mem(row, col);
	}
}

uint8_t MyMath::Matrix::Is_Empty(void)
{
	return MatrixBase == NULL;
}

double* MyMath::Matrix::operator[] (uint16_t index)
{
	return MatrixBase[index];
}

MyMath::Matrix& MyMath::Matrix::operator = (const Matrix& rhs)
{
	if (this->MatrixBase != NULL)
	{
		Delete();
	}

	this->Row = rhs.Row;
	this->Col = rhs.Col;

	//std::cout << "Base Address : " << rhs.MatrixBase << std::endl;

	if ((0 < this->Row) && (0 < this->Col))
	{
		Allocate_Mem(this->Row, this->Col);

		for (uint16_t i = 0; i < this->Row; i++)
		{
			memcpy(this->MatrixBase[i], rhs.MatrixBase[i], (sizeof(double) * this->Col));
		}
	}

	return *this;
}

std::ostream& MyMath::operator<<(std::ostream& out, MyMath::Matrix& obj)
{
	return out;
}


MyMath::Matrix MyMath::operator + (const MyMath::Matrix& l, const MyMath::Matrix& r)
{
	MyMath::Matrix temp;

	/*< Should be removed */
	MyMath::Matrix lhs = l;
	MyMath::Matrix rhs = r;

	if (lhs.MatrixBase == NULL)
	{
		/*< if lhs matrix is empty, then we can consider this as a matrix with all zeros, so we are assigning it direclty. */
		lhs = rhs;
	}

	else if (rhs.MatrixBase == NULL)
	{
		/*< Same logic applies for this condition */
		rhs = lhs;
	}

	else if ((lhs.Row == rhs.Row) && (lhs.Col == rhs.Col))
	{
		temp.Create(lhs.Row, lhs.Col);

		for (uint16_t i = 0; i < lhs.Row; i++)
		{
			for (uint16_t j = 0; j < lhs.Col; j++)
			{
				temp[i][j] = lhs[i][j] + rhs[i][j];
			}
		}
	}

	else
	{
		/*< If the row and column value is not equal then return empty array */
		std::cout << "Row, Col mis-match! operator : +" << std::endl;
	}

	return temp;
}

MyMath::Matrix MyMath::operator - (const MyMath::Matrix& l, const MyMath::Matrix& r)
{
	MyMath::Matrix temp;

	/*< Should be removed */
	MyMath::Matrix lhs = l;
	MyMath::Matrix rhs = r;

	if (lhs.MatrixBase == NULL)
	{
		/*< if lhs matrix is empty, then we can consider this as a matrix with all zeros, so we are assigning it direclty. */
		lhs = rhs;
	}

	else if (rhs.MatrixBase == NULL)
	{
		/*< Same logic applies for this condition */
		rhs = lhs;
	}

	else if ((lhs.Row == rhs.Row) && (lhs.Col == rhs.Col))
	{
		temp.Create(lhs.Row, lhs.Col);

		for (uint16_t i = 0; i < lhs.Row; i++)
		{
			for (uint16_t j = 0; j < lhs.Col; j++)
			{
				temp[i][j] = lhs[i][j] - rhs[i][j];
			}
		}
	}

	else
	{
		/*< If the row and column value is not equal then return empty array */
		std::cout << "Row, Col mis-match! operator : -" << std::endl;
	}

	return temp;
}

MyMath::Matrix MyMath::operator * (const MyMath::Matrix& l,const MyMath::Matrix& r)
{
	MyMath::Matrix temp;

	/*< Should be removed */
	MyMath::Matrix lhs = l;
	MyMath::Matrix rhs = r;

	if (lhs.MatrixBase == NULL)
	{
		/*< if lhs matrix is empty, then we can consider this as a matrix with all 1s, so we are assigning it direclty. */
		lhs = rhs;
	}

	else if (rhs.MatrixBase == NULL)
	{
		/*< Same logic applies for this condition */
		rhs = lhs;
	}

	else if (lhs.Col == rhs.Row)
	{
		double Val = 0.00;

		temp.Create(lhs.Row, rhs.Col);

		for (uint16_t i = 0; i < lhs.Row; i++)
		{
			for (uint16_t j = 0; j < rhs.Col; j++)
			{
				for (uint16_t k = 0; k < lhs.Col; k++) //lhs.col is equal to rhs.row
				{
					Val += (lhs[i][k] * rhs[k][j]);
				}

				temp[i][j] = Val;
				Val = 0;
			}
		}
	}

	else
	{
		/*< If the row and column value is not equal then return empty array */
		std::cout << "Row, Col mis-match! operator : *" << std::endl;
	}
	
	return temp;
}

MyMath::Matrix MyMath::operator * (double Val, const MyMath::Matrix& lhs)
{
	Matrix Obj = lhs;

	if (Obj.MatrixBase != NULL)
	{
		for (uint16_t i = 0; i < Obj.Row; i++)
		{
			for (uint16_t j = 0; j < Obj.Col; j++)
			{
				Obj[i][j] *= Val;
			}
		}
	}

	return Obj;
}
