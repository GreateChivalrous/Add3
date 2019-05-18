#ifndef __MATRIX4X3_H_INCLUDED__
#define __MATRIX4X3_H_INCLUDED__


class Vector3;
class EulerAngles;
class Quaternion;
class RotationMatrix;

class Matrix4x3 {
public:
	float m11, m12, m13;
	float m14 = 0.0f;
	float m21, m22, m23;
	float m24 = 0.0f;
	float m31, m32, m33;
	float m34 = 0.0f;
	float tx, ty, tz;
	float t = 1.0f;

	void identity();

	void zeroTranslation();
	void setTranslation(const Vector3& d);
	void setupTranslation(const Vector3& d);

	void setupLocalToParent(const Vector3& pos, const EulerAngles& orient);
	void setupLocalToParent(const Vector3& pos, const RotationMatrix& orient);
	void setupParentToLocal(const Vector3& pos, const EulerAngles& orient);
	void setupParentToLocal(const Vector3& pos, const RotationMatrix& orient);

	void setupRotate(int axis, float theta);
	void setupRotate(const Vector3& axis, float theta);
	void setupScale(const Vector3& s);
	void fromQuaternion(const Quaternion& q);
	void setupScaleAlongAxis(const Vector3& axis, float k);
	void setupProject(const Vector3& n);
	//透视投影（一点透视）
	void setupPerspectiveProject1(float R/*视径*/,float d/*视距*/);
	//透视投影（二点透视）
	void setupPerspectiveProject2(float R/*视径*/, float d/*视距*/);
	//透视投影（三点透视）
	void setupPerspectiveProject3(float R/*视径*/, float d/*视距*/);
	void setupShear(int aixs, float s, float t);
	void setupReflect(int axis, float k = 0.0f);
	void setupReflect(const Vector3& n);
};

Vector3 operator *(const Vector3& p, const Matrix4x3& m);
Matrix4x3& operator *=(const Matrix4x3& a, const Matrix4x3& m);

float determinant(const Matrix4x3& m);
Matrix4x3 inverse(const Matrix4x3& m);
Vector3 getTranslation(const Matrix4x3& m);
Vector3 getPositionFromParentToLocalMatrix(const Matrix4x3& m);
Vector3 getPositionFromLocalToParentMatrix(const Matrix4x3& m);
#endif