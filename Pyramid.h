#pragma once
#include "Project3.h"
#define MODE_CUSTOM 0 //�Զ���
#define MODE_GRAVITY 1//����
#define MODE_INCENTRE 2//����
#define MODE_CIRCUMCENTER 3//����
class Pyramid ://׶��
	public Project3
{
public:

	Pyramid();
	Pyramid(Surface3 underSider/*����*/,float height/*׶��߶�*/,int mode/*׶��ģʽ*/,string areal/*��������*/);
	~Pyramid();
};

