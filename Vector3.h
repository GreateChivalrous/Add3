#pragma once
#include<math.h>
#include"iostream"
#include"Vector2.h"

using namespace std;

class Vector3
{
public:
	float x=0.0f, y=0.0f, z=0.0f;
	COLORREF color ;
	Vector3();
	Vector3(const Vector3 &a):x(a.x),y(a.y),z(a.z),color(a.color){}
	Vector3(float nx, float ny, float nz,COLORREF col=BLACK) :x(nx), y(ny), z(nz) ,color(col){}
	//三维向量转二维向量,近大远小，投影平面在Z=0平面上
	Vector2 toVector2() { 
		return Vector2(x , y ,color,z); }
	//向量复制
	Vector3& operator =(const Vector3& a) {
		x = a.x;
		y = a.y;
		z = a.z;
		color = a.color;
		return *this;
	}
	//向量相等
	bool operator ==(const Vector3& a)const {
		return x == a.x && y == a.y && z == a.z;
	}
	//向量不等
	bool operator !=(const Vector3& a)const {
		return x != a.x || y != a.y || z != a.z;
	}
	//向量各分量置零
	void zero() { x = y = z = 0.0f; }
	//负向量
	Vector3 operator - ()const { return Vector3(-x, -y, -z); }
	//重载+，向量相加
	Vector3 operator +(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}
	//重载-，向量相减
	Vector3 operator -(const Vector3& a)const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}
	//重载*
	Vector3 operator *(float a)const {
		return Vector3(x * a, y * a, z * a);
	}
	//重载 /
	Vector3 operator /(float a)const {
		float oneOverA = 1.0f / a;
		return Vector3(x * oneOverA, y * oneOverA, z * oneOverA);
	}
	//重载+=
	Vector3& operator +=(const Vector3& a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}
	//重载-=
	Vector3& operator -=(const Vector3& a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}
	//重载*=
	Vector3& operator *=(float a) {
		x *= a; y *= a; z *= a;
		return *this;
	}
	//重载/=
	Vector3& operator /=(float a) {
		float oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}
	//向量的标准化
	void normalize() {
		float magSq = x * x + y * y + z * z;
		if (magSq > 0.0f) {
			float oneOverMag = 1.0f / sqrt(magSq);
			x *= oneOverMag;
			y *= oneOverMag;
			z *= oneOverMag;
		}
	}
	//向量点乘，向量*向量=常数=向量1的模*向量2的模*cos(theta)
	float operator *(const Vector3& a)const {
		return x * a.x + y * a.y + z * a.z;
	}
	//将向量各分量信息输出到控制台
	void toString() { cout << "[" << x << "," << y << "," << z << ",Color:"<<color<<"]" << endl; }
	~Vector3();
};
//求向量的模
inline float vectorMag(const Vector3& a) {
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}
//向量的叉乘
inline Vector3 crossProduct(const Vector3& a, const Vector3& b) {
	return Vector3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}
//重载*，常数*向量=向量
inline Vector3 operator *(float k, const Vector3& v) {
	return Vector3(k * v.x, k * v.y, k * v.z);
}
//求两点之间的距离
inline float distance(const Vector3& a, const Vector3& b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
//三维零向量
extern const Vector3 kZeroVector;
