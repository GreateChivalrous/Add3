#include "Surface3.h"



Surface3::Surface3()
{
}


Surface3::~Surface3()
{
}
Vector3 Surface3::GetGravity() {//求平面重心
	float x = 0.0f; float y = 0.0f; float z = 0.0f;
	int i = 0;
	for (vector<Vector3*>::iterator iter = surfacePeakTable.begin(); iter != surfacePeakTable.end(); iter++) {
		x += (**iter).x;
		y += (**iter).y;
		z += (**iter).z;
		i++;
	}
	x = x / i;
	y = y / i;
	z = z / i;
	return Vector3(x,y,z);
}
Vector3 Surface3::GetLawVector() {//求平面法向量
	Vector3 v1 = *surfacePeakTable[1] - *surfacePeakTable[0];
	Vector3 v2 = *surfacePeakTable[2] - *surfacePeakTable[1];
	Vector3 vc = crossProduct(v1,v2);
	vc.normalize();
	Vector3 vg=GetGravity();
	return Vector3(vg+vc);
}
void Surface3::blanking(const Vector3& n/*视向量*/) {
	Vector3 lv=this->GetLawVector();
	float result = lv * n;
	if (result < 0) {
		shouldBeShow = true;
	}
	else {
		shouldBeShow = false;
	}
}