#include "Pyramid.h"



Pyramid::Pyramid()
{
}

Pyramid::Pyramid(Surface3 underSider/*����*/, float height/*׶��߶�*/, int mode/*׶��ģʽ*/, string areal/*��������*/){
	Vector3 underSiderCenter;//׶�������׶�Ĵ�ֱ�ĵ�
	Vector3 TapWeb;//��׶���׶�ĵ�
	Vector3 LawVector;//׶�����ķ�ʸ��
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
