#include "Vector3.h"
Vector3::Vector3()
{
}


Vector3::~Vector3()
{
}
void main() {
	Vector3 v(1.0,2,3.2);
	Vector3 vv;
	vv = v;
	Vector3 v1(2,5.3,2.1);
	vv.toString();
	if (vv == v) {
		cout << "==²âÊÔÍ¨¹ý" << endl;
	}
	else {
		cout << "²âÊÔÊ§°Ü" << endl;
	}
	if (v1 != v) {
		cout << "£¡=²âÊÔÍ¨¹ý" << endl;
	}
	else {
		cout << "²âÊÔÊ§°Ü" << endl;
	}
	vv.zero();
	vv.toString();
	vv = -v1;
	vv.toString();
	vv = vv + v1;
	vv.toString();
	vv = vv - v1-v;
	vv.toString();
	vv = vv * 3;
	vv.toString();
	vv = vv / 3;
	vv.toString();
	for(int i =0;i<=2;i++){
	vv += v1;
	vv.toString();
	}
	vv.normalize();
	vv.toString();
	double x = vv * v1;
	cout << x << endl;
	cout << vectorMag(vv) << endl;
	Vector3 v2=crossProduct(vv, v1);
	v2.toString();
	cout<<distance(v1, v2)<<endl;
	
}