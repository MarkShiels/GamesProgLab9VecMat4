#include "MyMatrix4.h"


// Constructor 1 create a zero matrix
MyMatrix4::MyMatrix4()
{
	m_A11 = 0.0f;
	m_A12 = 0.0f;
	m_A13 = 0.0f;
	m_A14 = 0.0f;
	m_A21 = 0.0f;
	m_A22 = 0.0f;
	m_A23 = 0.0f;
	m_A24 = 0.0f;
	m_A31 = 0.0f;
	m_A32 = 0.0f;
	m_A33 = 0.0f;
	m_A34 = 0.0f;
	m_A41 = 0.0f;
	m_A42 = 0.0f;
	m_A43 = 0.0f;
	m_A44 = 0.0f;
	
}

// Constructor 2 To allow 3 rows of vectors to be declared as a matrix
MyMatrix4::MyMatrix4(MyVector4 r1, MyVector4 r2, MyVector4 r3, MyVector4 r4)
{
	m_A11 = r1.m_x;
	m_A12 = r1.m_y;
	m_A13 = r1.m_z;
	m_A14 = r1.m_w;
	m_A21 = r2.m_x;
	m_A22 = r2.m_y;
	m_A23 = r2.m_z;
	m_A24 = r2.m_w;
	m_A31 = r3.m_x;
	m_A32 = r3.m_y;
	m_A33 = r3.m_z;
	m_A34 = r3.m_w;
	m_A41 = r4.m_x;
	m_A42 = r4.m_y;
	m_A43 = r4.m_z;
	m_A44 = r4.m_w;
}

// Constructor 3 to allow nine float values
MyMatrix4:: MyMatrix4(float t_A11, float t_A12, float t_A13, float t_A14,
	float t_A21, float t_A22, float t_A23, float t_A24,
	float t_A31, float t_A32, float t_A33, float t_A34,
	float t_A41, float t_A42, float t_A43, float t_A44)
{
	m_A11 = t_A11;
	m_A12 = t_A12;
	m_A13 = t_A13;
	m_A14 = t_A14;
	m_A21 = t_A21;
	m_A22 = t_A22;
	m_A23 = t_A23;
	m_A24 = t_A24;
	m_A31 = t_A31;
	m_A32 = t_A32;
	m_A33 = t_A33;
	m_A34 = t_A34;
	m_A41 = t_A41;
	m_A42 = t_A42;
	m_A43 = t_A43;
	m_A44 = t_A44;
	
}

// An overloaded operator * to return the  product of the matrix by a vector
MyVector4 MyMatrix4::operator *(MyVector4 V1)
{
	return MyVector4( (m_A11 * V1.m_x) + (m_A12 * V1.m_y) + (m_A13 * V1.m_z) + (m_A14 * V1.m_w),
					(m_A21 * V1.m_x) + (m_A22 * V1.m_y) + (m_A23 * V1.m_z) + (m_A24 * V1.m_w),
					(m_A31 * V1.m_x) + (m_A32 * V1.m_y) + (m_A33 * V1.m_z) + (m_A34 * V1.m_w),
					(m_A41 * V1.m_x) + (m_A42 * V1.m_y) + (m_A43 * V1.m_z) + (m_A44 * V1.m_w));
}

// a method to transpose a given matrix
MyMatrix4 MyMatrix4::transpose()
{
	return MyMatrix4(m_A11, m_A21, m_A31,m_A14,
					m_A12, m_A22, m_A32,m_A24,
					m_A13, m_A23, m_A33, m_A34,
					m_A43, m_A43, m_A43, m_A44);
}

// An overloaded operator + to return the  sum of two matrix 
MyMatrix4 MyMatrix4::operator +(MyMatrix4 M1)
{
	return MyMatrix4(m_A11 + M1.m_A11, m_A12 + M1.m_A12, m_A13 + M1.m_A13,m_A14 + M1.m_A14,
					 m_A21 + M1.m_A21, m_A22 + M1.m_A22, m_A23 + M1.m_A23, m_A24 + M1.m_A24,
					 m_A31 + M1.m_A31, m_A32 + M1.m_A32, m_A33 + M1.m_A33, m_A34 + M1.m_A34,
					 m_A41 + M1.m_A41, m_A42 + M1.m_A42, m_A43 + M1.m_A43, m_A44 + M1.m_A44);
}

MyMatrix4 MyMatrix4::operator -(MyMatrix4 M1)
{// An overloaded operator * to return the  difference of two matrix
	return MyMatrix4(m_A11 - M1.m_A11, m_A12 - M1.m_A12, m_A13 - M1.m_A13, m_A14 - M1.m_A14,
		m_A21 - M1.m_A21, m_A22 - M1.m_A22, m_A23 - M1.m_A23, m_A24 - M1.m_A24,
		m_A31 - M1.m_A31, m_A32 - M1.m_A32, m_A33 - M1.m_A33, m_A34 - M1.m_A34,
		m_A41 - M1.m_A41, m_A42 - M1.m_A42, m_A43 - M1.m_A43, m_A44 - M1.m_A44);
}

// An overloaded operator * to return the  product of the matrix by a scalar
MyMatrix4 MyMatrix4::operator *(float x)
{
	MyMatrix4 answer;

	answer.m_A11 = m_A11 * x;
	answer.m_A12 = m_A12 * x;
	answer.m_A13 = m_A13 * x;
	answer.m_A14 = m_A14 * x;

	answer.m_A21 = m_A21 * x;
	answer.m_A22 = m_A22 * x;
	answer.m_A23 = m_A23 * x;
	answer.m_A24 = m_A24 * x;

	answer.m_A31 = m_A31 * x;
	answer.m_A32 = m_A32 * x;
	answer.m_A33 = m_A33 * x;
	answer.m_A34 = m_A34 * x;

	answer.m_A41 = m_A41 * x;
	answer.m_A42 = m_A42 * x;
	answer.m_A43 = m_A43 * x;
	answer.m_A44 = m_A44 * x;

	return answer;
}

// An overloaded operator * to return the  product of two matrix
MyMatrix4 MyMatrix4::operator *(MyMatrix4 M1)
{
	MyMatrix4 answer;

	answer.m_A11 = (m_A11 * M1.m_A11) + (m_A12 * M1.m_A21) + (m_A13 * M1.m_A31) + (m_A14 * M1.m_A41);
	answer.m_A12 = (m_A11 * M1.m_A12) + (m_A12 * M1.m_A22) + (m_A13 * M1.m_A32) + (m_A14 * M1.m_A42);
	answer.m_A13 = (m_A11 * M1.m_A13) + (m_A12 * M1.m_A23) + (m_A13 * M1.m_A33) + (m_A14 * M1.m_A43);
	answer.m_A14 = (m_A11 * M1.m_A14) + (m_A12 * M1.m_A24) + (m_A13 * M1.m_A34) + (m_A14 * M1.m_A44);

	answer.m_A21 = (m_A21 * M1.m_A11) + (m_A22 * M1.m_A21) + (m_A23 * M1.m_A31) + (m_A24 * M1.m_A41);
	answer.m_A22 = (m_A21 * M1.m_A12) + (m_A22 * M1.m_A22) + (m_A23 * M1.m_A32) + (m_A24 * M1.m_A42);
	answer.m_A23 = (m_A21 * M1.m_A13) + (m_A22 * M1.m_A23) + (m_A23 * M1.m_A33) + (m_A24 * M1.m_A43);
	answer.m_A24 = (m_A21 * M1.m_A14) + (m_A22 * M1.m_A24) + (m_A23 * M1.m_A34) + (m_A24 * M1.m_A44);

	answer.m_A31 = (m_A31 * M1.m_A11) + (m_A32 * M1.m_A21) + (m_A33 * M1.m_A31) + (m_A34 * M1.m_A41);
	answer.m_A32 = (m_A31 * M1.m_A12) + (m_A32 * M1.m_A22) + (m_A33 * M1.m_A32) + (m_A34 * M1.m_A42);
	answer.m_A33 = (m_A31 * M1.m_A13) + (m_A32 * M1.m_A23) + (m_A33 * M1.m_A33) + (m_A34 * M1.m_A43);
	answer.m_A34 = (m_A31 * M1.m_A14) + (m_A32 * M1.m_A24) + (m_A33 * M1.m_A34) + (m_A34 * M1.m_A44);

	answer.m_A41 = (m_A41 * M1.m_A11) + (m_A42 * M1.m_A21) + (m_A43 * M1.m_A31) + (m_A44 * M1.m_A41);
	answer.m_A42 = (m_A41 * M1.m_A12) + (m_A42 * M1.m_A22) + (m_A43 * M1.m_A32) + (m_A44 * M1.m_A42);
	answer.m_A43 = (m_A41 * M1.m_A13) + (m_A42 * M1.m_A23) + (m_A43 * M1.m_A33) + (m_A44 * M1.m_A43);
	answer.m_A44 = (m_A41 * M1.m_A14) + (m_A42 * M1.m_A24) + (m_A43 * M1.m_A34) + (m_A44 * M1.m_A44);

	return answer;
}

// method to return the determinant of a 3x3 matrix
/*float MyMatrix4::determinant()
{
	//                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return (m_A11 * m_A22 * m_A33 - m_A11 * m_A32 * m_A23) + (m_A21 * m_A32 * m_A13 - m_A31 * m_A22 * m_A13) + (m_A31 * m_A12 * m_A23 - m_A21 * m_A12 * m_A33);
}*/


// a method to return as Row as MyVector4 0 == first row, default == last row
MyVector4 MyMatrix4::row(int i)
{
	switch (i)
	{
	case 1:
		return MyVector4(m_A11, m_A12, m_A13, m_A14);
	case 2:
		return MyVector4(m_A21, m_A22, m_A23, m_A24);
	case 3:
		return MyVector4(m_A31, m_A32, m_A33, m_A34);
	case 4:
		return MyVector4(m_A41, m_A42, m_A43, m_A44);
	default:
		break;
	}
}

// a method to return as column as MyVector4 1 == first column
MyVector4 MyMatrix4::column(int i)
{
	switch (i)
	{
	case 1:
		return MyVector4(m_A11, m_A21, m_A31, m_A41);
	case 2:
		return MyVector4(m_A12, m_A22, m_A32, m_A42);
	case 3:
		return MyVector4(m_A13, m_A23, m_A33, m_A43);
	case 4:
		return MyVector4(m_A14, m_A24, m_A34, m_A44);
	default:
		break;
	}
}

/*MyMatrix4 MyMatrix4::inverse()
{
	float det = determinant();
	if (det == 0)
		return MyMatrix4();
	else
	{
		float scale = 1 / det;
		MyMatrix4 answer = MyMatrix4();
		answer.m_A11 = scale * (m_A22 * m_A33 - m_A23 * m_A32); // ei-fh
		answer.m_A12 = scale * (m_A13 * m_A32 - m_A12 * m_A33); // ch-bi
		answer.m_A13 = scale * (m_A12 * m_A23 - m_A13 * m_A22); // ch-bi

		answer.m_A21 = scale * (m_A23 * m_A31 - m_A21 * m_A33); // fg-di
		answer.m_A22 = scale * (m_A11 * m_A33 - m_A13 * m_A31); // ai-cg
		answer.m_A23 = scale * (m_A13 * m_A21 - m_A11 * m_A23); // cd-af

		answer.m_A31 = scale * (m_A21 * m_A32 - m_A22 * m_A31); // dh-eg
		answer.m_A32 = scale * (m_A12 * m_A31 - m_A11 * m_A32); // bg-ah
		answer.m_A33 = scale * (m_A11 * m_A22 - m_A12 * m_A21); // ae-bd

		return answer;
	}

}*/

/*MyMatrix4 MyMatrix4::rotation(float angle)
{
	float radians = M_PI / 180 * angle;
	MyMatrix4 answer = MyMatrix4();

	answer.m_A11 = cos(radians);
	answer.m_A12 = sin(radians);
	answer.m_A13 = 0;
	answer.m_A21 = -sin(radians);
	answer.m_A22 = cos(radians);
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;

	return answer;
}*/

MyMatrix4 MyMatrix4::translate(float dx, float dy, float dz)
{
	MyMatrix4 answer = MyMatrix4();
	answer.m_A11 = 1;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A14 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = 1;
	answer.m_A23 = 0;
	answer.m_A24 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;
	answer.m_A34 = 0;
	answer.m_A41 = dx;
	answer.m_A42 = dy;
	answer.m_A43 = dz;
	answer.m_A44 = 1;

	return answer;
}

MyMatrix4 MyMatrix4::Scale(float dx, float dy, float dz)
{
	MyMatrix4 answer = MyMatrix4();
	answer.m_A11 = dx;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A14 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = dy;
	answer.m_A23 = 0;
	answer.m_A24 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = dz;
	answer.m_A34 = 0;
	answer.m_A41 = 0;
	answer.m_A42 = 0;
	answer.m_A43 = 0;
	answer.m_A44 = 1;

	return answer;
}

MyMatrix4 MyMatrix4::operator -()
{
	return operator*(-1);
}

MyMatrix4 MyMatrix4::rotationX(float angle)
{
	float radians = M_PI / 180 * angle;
	MyMatrix4 answer = MyMatrix4();

	answer.m_A11 = 1;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A14 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = cos(radians);
	answer.m_A23 = -sin(radians);
	answer.m_A24 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = sin(radians);
	answer.m_A33 = cos(radians);
	answer.m_A34 = 0;
	answer.m_A41 = 0;
	answer.m_A42 = 0;
	answer.m_A43 = 0;
	answer.m_A44 = 1;

	return answer;
}

MyMatrix4 MyMatrix4::rotationY(float angle)
{
	float radians = M_PI / 180 * angle;
	MyMatrix4 answer = MyMatrix4();

	answer.m_A11 = cos(radians);
	answer.m_A12 = 0;
	answer.m_A13 = sin(radians);
	answer.m_A14 = 0;
	answer.m_A21 = 1;
	answer.m_A22 = 0;
	answer.m_A23 = 0;
	answer.m_A24 = 0;
	answer.m_A31 = -sin(radians);
	answer.m_A32 = 0;
	answer.m_A33 = cos(radians);
	answer.m_A34 = 0;
	answer.m_A41 = 0;
	answer.m_A42 = 0;
	answer.m_A43 = 0;
	answer.m_A44 = 1;

	return answer;
}

MyMatrix4 MyMatrix4::rotationZ(float angle)
{
	float radians = M_PI / 180 * angle;
	MyMatrix4 answer = MyMatrix4();
	
	answer.m_A11 = cos(radians);
	answer.m_A12 = -sin(radians);
	answer.m_A13 = 0;
	answer.m_A14 = 0;
	answer.m_A21 = sin(radians);
	answer.m_A22 = cos(radians);
	answer.m_A23 = 0;
	answer.m_A24 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = 1;
	answer.m_A34 = 0;
	answer.m_A41 = 0;
	answer.m_A42 = 0;
	answer.m_A43 = 0;
	answer.m_A44 = 1;

	return answer;
}

MyMatrix4 MyMatrix4::scale3D(float dx)
{
	MyMatrix4 answer = MyMatrix4();
	answer.m_A11 = dx / 100;
	answer.m_A12 = 0;
	answer.m_A13 = 0;
	answer.m_A21 = 0;
	answer.m_A22 = dx / 100;
	answer.m_A23 = 0;
	answer.m_A31 = 0;
	answer.m_A32 = 0;
	answer.m_A33 = dx / 100;

	return answer;
}