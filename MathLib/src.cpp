#include <iostream>
#include <myMath.h>


int main(void)
{
	uint16_t count = 0;

	Matrix m1(10,10);
	Matrix m2(1, 2);

	for (uint16_t i = 0; i < 10; i++)
	{
		for (uint16_t j = 0; j < 10; j++)
		{
			m1[i][j] = count++;
		}
	}

	std::cout << m1 << std::endl;

	m2 = m1;

	std::cout << m2 << std::endl;
}