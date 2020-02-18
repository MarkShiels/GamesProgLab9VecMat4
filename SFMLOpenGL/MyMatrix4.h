#pragma once
#define _USE_MATH_DEFINES
#include "MyVector4.h"
#include <cmath>


class MyMatrix4
{

public:

	// The class has twleve variables, 4 rows and 4 columns
	float m_A11;
	float m_A12;
	float m_A13;
	float m_A14;
	float m_A21;
	float m_A22;
	float m_A23;
	float m_A24;
	float m_A31;
	float m_A32;
	float m_A33;
	float m_A34;
	float m_A41;
	float m_A42;
	float m_A43;
	float m_A44;

	// Constructor 1 create a zero matrix
	MyMatrix4();

	// Constructor 2 To allow 3 rows of vectors to be declared as a matrix
	MyMatrix4(MyVector4 r1, MyVector4 r2, MyVector4 r3, MyVector4 r4);

	// Constructor 3 to allow 9 floats
	MyMatrix4(float t_A11, float t_A12, float t_A13,float t_A14,
			 float t_A21, float t_A22, float t_A23,float t_A24,
			  float t_A31, float t_A32, float t_A33,float t_A34,
				float t_A41, float t_A42, float t_A43, float t_A44);

	// An overloaded operator * to return the  product of the matrix by a vector
	MyVector4 operator *(MyVector4 V1);

	// a method to transpose a given matrix
	MyMatrix4 transpose();

	// An overloaded operator + to return the  sum of two matrix 
	MyMatrix4 operator +(MyMatrix4 M1);

	// An overloaded operator * to return the  difference of two matrix
	MyMatrix4 operator -(MyMatrix4 M1);

	// An overloaded operator * to return the  product of the matrix by a scalar
	MyMatrix4 operator *(float x);

	// An overloaded operator * to return the  product of two matrix
	MyMatrix4 operator *(MyMatrix4 M1);

	// method to return the determinant of a 3x3 matrix
	float determinant();

	// a method to return as Row as MyVector4 1 == first row
	MyVector4 row(int i);

	// a method to return as column as MyVector4 1 == first column
	MyVector4 column(int i);

	// method to return the inverse of a matrix if exists else zero vector
	MyMatrix4 inverse();

	MyMatrix4 rotation(float angle);

	MyMatrix4 translate(float dx, float dy, float dz);

	MyMatrix4 Scale(float dx, float dy, float dz);
	
	MyMatrix4 operator -();
	
	MyMatrix4 rotationX(float angle);

	MyMatrix4 rotationY(float angle);

	MyMatrix4 rotationZ(float angle);

	MyMatrix4 scale3D(float dx);

};

