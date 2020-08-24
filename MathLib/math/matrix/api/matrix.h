#ifndef __MATRIX_H__
#define __MATRIX_H__

//#include <ostream>

namespace MyMath
{
	class Matrix
	{
	private:
		uint16_t Row = 0;
		uint16_t Col = 0;
		double** MatrixBase = NULL;

		void Allocate_Mem(uint16_t row, uint16_t col);

	public:
		Matrix();
		Matrix(uint16_t row, uint16_t col);
		~Matrix();

		void Create(uint16_t row, uint16_t col);
		void Delete(void);
		uint8_t Is_Empty(void);

		double* operator[] (uint16_t index);
		Matrix& operator = (const Matrix& obj);
		friend std::ostream& operator << (std::ostream& out, MyMath::Matrix& obj);
		friend Matrix operator + (const MyMath::Matrix& l, const MyMath::Matrix& r);
		friend Matrix operator - (const MyMath::Matrix& l, const MyMath::Matrix& r);
		friend Matrix operator * (const MyMath::Matrix& l, const MyMath::Matrix& r);
		friend Matrix operator * (double Val, const MyMath::Matrix& lhs);
	};
}

#endif
