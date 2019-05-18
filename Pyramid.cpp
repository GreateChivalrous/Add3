#include "Pyramid.h"



Pyramid::Pyramid()
{
}

Pyramid::Pyramid(Surface3 underSider/*底面*/, float height/*锥体高度*/, int mode/*锥点模式*/, string areal/*重心坐标*/){
	Vector3 underSiderCenter;//锥体底面与锥心垂直的点
	Vector3 TapWeb;//该锥体的锥心点
	Vector3 LawVector;//锥体底面的法矢量
	switch (mode) {
	case MODE_CUSTOM:
		break;
	case MODE_GRAVITY:
		underSiderCenter = underSider.GetGravity();
		break;
	case MODE_INCENTRE:
		underSiderCenter = underSider.GetIncentre();
		break;
	case MODE_CIRCUMCENTER:
		underSiderCenter = underSider.GetCircumcentre();
		break;
	default:
		break;
	}
	TapWeb = underSiderCenter + LawVector * height; 
	vector<Vector3> v = underSider.GetVectorV3();
	v.push_back(TapWeb);
	Project3(v);
}
Pyramid::~Pyramid()
{
}
