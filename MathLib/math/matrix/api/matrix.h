#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
private:
	uint16_t Row;
	uint16_t Col;
	double** MatrixBase;

	void Allocate_Mem(uint16_t row, uint16_t col);
	void De_Allocate_Mem(void);

public:
	Matrix(uint16_t row, uint16_t col);
	~Matrix();
	double* operator[] (uint16_t index);
	void operator = (Matrix& obj);
	friend std::ostream& operator << (std::ostream& out, Matrix& obj);
	friend Matrix& operator + (Matrix& ls, Matrix& rs);
	friend Matrix& operator - (Matrix& ls, Matrix& rs);
	friend Matrix& operator * (Matrix& ls, Matrix& rs);
	friend Matrix& operator / (Matrix& ls, Matrix& rs);
};

#endif
