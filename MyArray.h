#pragma once
#include <iostream>

class MyArray
{
private:
	int mArray[10];
public:
	MyArray() : mArray{}
	{
	}

	// [] 연산자를 사용한다면, 값도 바꿀 수 있어야 한다!!
	int& operator[](int index)		// 반환타입에 참조형을 사용함으로서
	{							    // mArray를 수정할 수 있게된다!
		return mArray[index];
	}
};

class Point2D
{
private:
	int mX;
	int mY;

public:
	Point2D() : mX{ 0 }, mY{ 0 }
	{
	}

	Point2D(int x, int y) : mX{ x }, mY{ y }
	{
	}

	void Print()
	{
		std::cout << "(" << mX << ", " << mY << ")" << std::endl;
	}


	// 형변환 연산자
	operator float()		// 형변환이 그대로 반환되기 때문에 반환타입 안씀
	{
		return float(sqrt(mX * mX + mY * mY));
	}			// sqrt함수의 반환값이 double이므로 float로 형변환


	// 함수 연산자
	void operator() ()
	{
		mX = 0;
		mY = 0;
	}

	void operator() (int x, int y)
	{
		mX = x;
		mY = y;
	}


	// 스트림 삽입 연산자		마치 Print() 처럼 작동하게 하기

	// std::cout << pt1 이라고 할때,
	// std::cout를 클래스 안에 멤버함수로 표현할 수 없기 때문에
	// 전역함수로만 가능하다

	// cout = ostream 타입의 전역 객체, ostream은 std 안에 들어있음
	friend std::ostream& operator << (std::ostream& os, const Point2D& point)
	{					// 전역 객체이므로 반드시 참조형!
						// std::cout << std::endl; 같이 작동을 하려면
						// 반환타입 역시 std::ostream&이 나와야한다.

		os << "(" << point.mX << ", " << point.mY << ")";
		return os;
	}

};
