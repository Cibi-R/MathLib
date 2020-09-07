#include <iostream>
#include <vector>
#include <myMath.h>


void Matrix_VectorAssignment(void)
{
	std::vector<std::vector<double>> vector1 = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	MyMath::Matrix temp1;

	temp1 = vector1;

	std::cout << temp1 << std::endl;
}


void Matrix_Multiplication(void)
{
	//MyMath::Matrix m1(2, 3);
	//m1[0][0] = 1; m1[0][1] = 2; m1[0][2] = 3;
	//m1[1][0] = 4; m1[1][1] = 5; m1[1][2] = 6;

	//MyMath::Matrix m2(3, 2);
	//m2[0][0] = 10; m2[0][1] = 11;
	//m2[1][0] = 20; m2[1][1] = 21;
	//m2[2][0] = 30; m2[2][1] = 31;

	//MyMath::Matrix m3 = m1 * m2;

	//std::cout << m3 << std::endl;

	MyMath::Matrix m1(2, 3);
	m1[0][0] = 2; m1[0][1] = 1; m1[0][2] = 4;
	m1[1][0] = 0; m1[1][1] = 1; m1[1][2] = 1;

	MyMath::Matrix m2(3, 4);
	m2[0][0] = 6;  m2[0][1] = 3; m2[0][2] = -1; m2[0][3] = 0;
	m2[1][0] = 1;  m2[1][1] = 1; m2[1][2] = 0;  m2[1][3] = 4;
	m2[2][0] = -2; m2[2][1] = 5; m2[2][2] = 0;  m2[2][3] = 2;

	MyMath::Matrix m3 = m1 * m2;

	std::cout << m3 << std::endl;
}


void Test_Operator_Equal(void)
{
	MyMath::Matrix m1(2, 1); m1[0][0] = -2; m1[1][0] = 3;
	MyMath::Matrix m2(2, 1); m2[0][0] = 4;  m2[1][0] = -1;
	MyMath::Matrix m3;

	m3 = m1 = m2 = m1;  // Chain operation

	m3 = ((m1 + m2) + (m1 + m2));

	std::cout << m3 << std::endl;
}

void Test_Vector_Function(void)
{
	uint16_t count = 0;

	MyMath::Matrix m1(2, 1); m1[0][0] = -2; m1[1][0] = 3;
	MyMath::Matrix m2(2, 1); m2[0][0] = 4;  m2[1][0] = -1;
	MyMath::Matrix m3(2, 1); m3[0][0] = -1;  m3[1][0] = 1;
	MyMath::Matrix m4(2, 1); m4[0][0] = 3;  m4[1][0] = -2;
	MyMath::Matrix res;

	res = (2 * m3) + (3 * m1) - m3 + (4 * m2);

	std::cout << res << std::endl;
}