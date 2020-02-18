#pragma once
#include <math.h>
#include <iostream>

class MyVector4
{
public:

	float	m_x;
	float	m_y;
	float	m_z;
	float	m_w;

	void	setX(float t_x);
	void	setY(float t_y);
	void	setZ(float t_z);
	void	setW(float t_w);

	MyVector4();
	MyVector4(float t_x, float t_y, float t_z, float t_w);
	~MyVector4();


	float	length();
	float	lengthSquared();
	void	normalise();


	 MyVector4	operator+(MyVector4 v1);
	 MyVector4	operator-(MyVector4 v1);
	 float		operator*(MyVector4 v1);
	 MyVector4	operator *(float k);
	// MyVector4	operator ^(MyVector4 V1);
	 MyVector4	operator - ();


	 friend MyVector4 operator+(const MyVector4& v1, const MyVector4& v2);
	 friend MyVector4 operator-(const MyVector4& v1, const MyVector4& v2);

	 void print();


	
};