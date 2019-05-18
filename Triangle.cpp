#include "Triangle.h"



Triangle::Triangle()
{
}


Triangle::~Triangle()
{
}
Vector3 Triangle::GetGravity() {
	float x = 0.0f; float y = 0.0f; float z = 0.0f;
	vector<Vector3*>::iterator iter = surfacePeakTable.begin();
	int i = 0;
	for (; iter != surfacePeakTable.end(); iter++) {
		x += *(iter)->x;
		y += *(iter)->y;
		z += *(iter)->z;
		i += 1;
	}
	return Vector3(x/i,y/i,z/i);
}
