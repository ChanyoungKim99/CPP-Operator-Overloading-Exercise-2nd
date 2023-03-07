#include <iostream>
#include "MyArray.h"

int main()
{
	MyArray array1;

	array1[0] = 1;			// 클래스 자체를 배열처럼 연산할 수 있게된다.
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