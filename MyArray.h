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

	// [] �����ڸ� ����Ѵٸ�, ���� �ٲ� �� �־�� �Ѵ�!!
	int& operator[](int index)		// ��ȯŸ�Կ� �������� ��������μ�
	{							    // mArray�� ������ �� �ְԵȴ�!
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


	// ����ȯ ������
	operator float()		// ����ȯ�� �״�� ��ȯ�Ǳ� ������ ��ȯŸ�� �Ⱦ�
	{
		return float(sqrt(mX * mX + mY * mY));
	}			// sqrt�Լ��� ��ȯ���� double�̹Ƿ� float�� ����ȯ


	// �Լ� ������
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


	// ��Ʈ�� ���� ������		��ġ Print() ó�� �۵��ϰ� �ϱ�

	// std::cout << pt1 �̶�� �Ҷ�,
	// std::cout�� Ŭ���� �ȿ� ����Լ��� ǥ���� �� ���� ������
	// �����Լ��θ� �����ϴ�

	// cout = ostream Ÿ���� ���� ��ü, ostream�� std �ȿ� �������
	friend std::ostream& operator << (std::ostream& os, const Point2D& point)
	{					// ���� ��ü�̹Ƿ� �ݵ�� ������!
						// std::cout << std::endl; ���� �۵��� �Ϸ���
						// ��ȯŸ�� ���� std::ostream&�� ���;��Ѵ�.

		os << "(" << point.mX << ", " << point.mY << ")";
		return os;
	}

};
