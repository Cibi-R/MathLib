#include <iostream>
#include <vector>
#include "../api/matrix.h"

namespace MyMath
{
	void Matrix::Allocate_Mem(void)
	{
		MatrixBase = new double* [Row];

		for (uint16_t r = 0; r < Row; r++)
		{
			MatrixBase[r] = new double[Col];
		}
	}

	void Matrix::Delete(void)
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

	Matrix::Matrix() : Row(0), Col(0), MatrixBase(NULL)
	{

	}

	Matrix::Matrix(uint16_t row, uint16_t col) : MatrixBase(NULL)
	{
		if ((0 < row) && (0 < col))
		{
			Row = row;
			Col = col;

			Allocate_Mem();
		}
	}

	Matrix::~Matrix()
	{
		/* DO NOTHING */
	}

	void Matrix::Create(uint16_t row, uint16_t col)
	{
		if ((0 < row) && (0 < col))
		{
			if (MatrixBase != NULL)
			{
				Delete();
			}

			Row = row;
			Col = col;

			Allocate_Mem();
		}
	}

	uint8_t Matrix::ResetTo(double val)
	{
		uint8_t RetVal = 0;

		if (MatrixBase != NULL)
		{
			for (uint16_t i = 0; i < Row; i++)
			{
				for (uint16_t j = 0; j < Col; j++)
				{
					MatrixBase[i][j] = val;
				}
			}

			RetVal = 1;
		}

		return RetVal;
	}

	uint8_t Matrix::Is_Empty(void)
	{
		return MatrixBase == NULL;
	}

	uint8_t Matrix::Sigmoid(Matrix& mat)
	{
		uint8_t RetVal = 1;

		if (mat.MatrixBase != NULL)
		{
			mat.Delete();
		}

		mat = *this;

		if ((0 < mat.Col) && (0 < mat.Row))
		{
			for (uint16_t i = 0; i < mat.Row; i++)
			{
				for (uint16_t j = 0; j < mat.Col; j++)
				{
					mat[i][j] = ((1) / (1 + exp(-mat[i][j])));
				}
			}
		}

		else
		{
			RetVal = 0;
		}

		return RetVal;
	}

	void Matrix::Sigmoid(void)
	{
		if (this->MatrixBase != NULL)
		{
			for (uint16_t i = 0; i < this->Row; i++)
			{
				for (uint16_t j = 0; j < this->Col; j++)
				{
					(*this)[i][j] = ((1) / (1 + exp((*this)[i][j])));
				}
			}
		}
	}

	double* Matrix::operator[] (uint16_t index)
	{
		return MatrixBase[index];
	}

	Matrix& Matrix::operator = (const Matrix& rhs)
	{
		if (MatrixBase != NULL)
		{
			Delete();
		}

		Row = rhs.Row;
		Col = rhs.Col;

		if ((0 < Row) && (0 < Col))
		{
			Allocate_Mem();

			for (uint16_t i = 0; i < this->Row; i++)
			{
				memcpy(this->MatrixBase[i], rhs.MatrixBase[i], (sizeof(double) * this->Col));
			}
		}

		return *this;
	}

	Matrix& Matrix::operator = (const std::vector<std::vector<double>>& obj)
	{
		if (MatrixBase != NULL)
		{
			Delete();
		}

		if (!obj.empty())
		{
			Row = static_cast<uint16_t> (obj.size());
			Col = static_cast<uint16_t> (obj[0].size());

			Allocate_Mem();

			for (uint16_t i = 0; i < Row; i++)
			{
				for (uint16_t j = 0; j < Col; j++)
				{
					(*this)[i][j] = obj[i][j];
				}
			}
		}

		return *this;
	}

	std::ostream& operator << (std::ostream& out, Matrix& obj)
	{
		if (obj.MatrixBase != NULL)
		{
			for (uint16_t i = 0; i < obj.Row; i++)
			{
				for (uint16_t j = 0; j < obj.Col; j++)
				{
					std::cout << obj[i][j] << " ";
				}
				std::cout << std::endl;
			}
		}

		return out;
	}

	Matrix operator + (const Matrix& l, const Matrix& r)
	{
		Matrix temp;

		/*< Should be removed */
		Matrix lhs = l;
		Matrix rhs = r;

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

	Matrix operator - (const Matrix& l, const Matrix& r)
	{
		Matrix temp;

		/*< Should be removed */
		Matrix lhs = l;
		Matrix rhs = r;

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

	Matrix operator * (const Matrix& l, const Matrix& r)
	{
		Matrix temp;

		/*< Should be removed */
		Matrix lhs = l;
		Matrix rhs = r;

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

	Matrix operator * (double Val, const Matrix& lhs)
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

	Matrix operator * (const Matrix& obj, double rhs)
	{
		return (rhs * obj);
	}
}