#pragma once
#include "Surface3.h"
class Triangle ://三角形（基类：平面）
	public Surface3
{
public:
	Vector3 GetGravity();
	Triangle();
	~Triangle();
};

