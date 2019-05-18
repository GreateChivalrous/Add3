#pragma once
#include "Project3.h"
#define MODE_CUSTOM 0 //自定义
#define MODE_GRAVITY 1//重心
#define MODE_INCENTRE 2//内心
#define MODE_CIRCUMCENTER 3//外心
class Pyramid ://锥体
	public Project3
{
public:

	Pyramid();
	Pyramid(Surface3 underSider/*底面*/,float height/*锥体高度*/,int mode/*锥点模式*/,string areal/*重心坐标*/);
	~Pyramid();
};

