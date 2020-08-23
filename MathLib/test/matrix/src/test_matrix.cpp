#include <iostream>
#include <myMath.h>


void Test_Operator_Equal(void)
{
	Matrix m1(2, 1); m1[0][0] = -2; m1[1][0] = 3;
	Matrix m2(2, 1); m2[0][0] = 4;  m2[1][0] = -1;
	Matrix m3;

	m3 = m1 = m2 = m1;  // Chain operation

	m3 = ((m1 + m2) + (m1 + m2));

	std::cout << m3 << std::endl;
}

void Test_Vector_Function(void)
{
	uint16_t count = 0;

	Matrix m1(2, 1); m1[0][0] = -2; m1[1][0] = 3;
	Matrix m2(2, 1); m2[0][0] = 4;  m2[1][0] = -1;
	Matrix m3(2, 1); m3[0][0] = -1;  m3[1][0] = 1;
	Matrix m4(2, 1); m4[0][0] = 3;  m4[1][0] = -2;
	Matrix res;

	res = (2 * m3) + (3 * m1) - m3 + (4 * m2);

	std::cout << res << std::endl;
}