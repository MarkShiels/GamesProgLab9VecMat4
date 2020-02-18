#include "MyVector4.h"

void MyVector4::setX(float t_x)
{
	m_x = t_x;
}

void MyVector4::setY(float t_y)
{
	m_y = t_y;
}

void MyVector4::setZ(float t_z)
{
	m_z = t_z;
}

void MyVector4::setW(float t_w)
{
	m_w = t_w;
}

MyVector4::MyVector4()
{
	setX(0.0f);
	setY(0.0f);
	setZ(0.0f);
	setW(0.0f);
}

MyVector4::MyVector4(float t_x, float t_y, float t_z, float t_w)
{
	setX(t_x);
	setY(t_y);
	setZ(t_z);
	setW(t_w);
}

MyVector4::~MyVector4()
{
}

float MyVector4::length()
{
	// A method to return the length of the vector
	//return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));

	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));
}

float MyVector4::lengthSquared()
{
	// A method to return the length squared of the vector
	//return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);

	return (m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w);
}

void MyVector4::normalise()
{
	// A method to reduce the length of the vector to 1.0 
	// keeping the direction the same
		/*if (length() > 0.0)
		{  // Check for divide by zero
			float magnitude = length();
			m_x /= magnitude;
			m_y /= magnitude;
			m_z /= magnitude;
		}*/

	if (length() > 0.0)
	{  // Check for divide by zero
		float magnitude = length();
		m_x /= magnitude;
		m_y /= magnitude;
		m_z /= magnitude;
		m_w /= magnitude;
	}
}

MyVector4 MyVector4::operator+(MyVector4 v1)
{
	return MyVector4(m_x + v1.m_x, m_y + v1.m_y, m_z + v1.m_z, m_w + v1.m_w);
}

MyVector4 MyVector4::operator-(MyVector4 v1)
{
	return MyVector4(m_x - v1.m_x, m_y - v1.m_y, m_z - v1.m_z, m_w - v1.m_w);
}

float MyVector4::operator*(MyVector4 v1)
{
	return float(m_x * v1.m_x + m_y * v1.m_y + m_z * v1.m_z + m_w * v1.m_w);
}

 MyVector4 operator+(const MyVector4& v1, const MyVector4& v2)
{
	// An overloaded operator + to return the sum of 2 vectors
	return MyVector4(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z, v1.m_w + v2.m_w);
}

 MyVector4 operator-(const MyVector4& v1, const MyVector4& v2)
 {
	 // An overloaded operator - to return the difference of 2 vectors
	 return MyVector4(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z, v1.m_w - v2.m_w);
 }

 MyVector4 MyVector4::operator - ()
 {
	 // An overloaded operator - to return the negation of a single vector
	 return MyVector4(m_x = -m_x, m_y = -m_y, m_z = -m_z, m_w);
 }

MyVector4 MyVector4::operator *(float k)
 {
	// An overloaded operator * to return the product of a scalar by a vector
	 return MyVector4(m_x * k, m_y * k, m_z * k, m_w);
 }

//MyVector4 MyVector4::operator ^(MyVector4 V1)
//{
//	// An overloaded operator ^ to return the vector product of 2 vectors
//	return MyVector4((m_y * V1.m_z - m_z * V1.m_y), -(m_x * V1.m_z - m_z * V1.m_x), (m_x * V1.m_y - m_y * V1.m_x));
//}

void MyVector4::print()
{
	std::cout << " " << m_x << " " << m_y << " " << m_z <<  " " << m_w << std::endl;
}