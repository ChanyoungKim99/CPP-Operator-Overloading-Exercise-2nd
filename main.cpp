#include <iostream>
#include "MyArray.h"

int main()
{
	MyArray array1;

	array1[0] = 1;			// Ŭ���� ��ü�� �迭ó�� ������ �� �ְԵȴ�.
	std::cout << array1[0] << std::endl;


	Point2D pt1(2, 4);
	float distance{ pt1 };
	std::cout << distance << std::endl;

	Point2D pt2(1, 2);
	pt2();
	pt2.Print();

	pt2(3, 4);
	pt2.Print();

	std::cout << pt2;
}