#pragma once

#include"atltypes.h"
#include<math.h>
#include"MyColor.h"
#ifndef Round(d)
#define Round(d) (int)floor(d+0.5)
#endif // !Round(x)
class Vector2
{
public:
	float x=0.0f;
	float y=0.0f;
	COLORREF color2;
	float depth;//三维转二维时的深度信息
	Vector2();
	Vector2(float x1, float y1,COLORREF col,float d=0.0f) :x(x1), y(y1),color2(col),depth(d) {}
	Vector2(const Vector2& v):x(v.x),y(v.y),color2(v.color2) ,depth(v.depth){}
	CPoint toCPoint() { return CPoint(Round(x),Round(y)); }
	Vector2& operator =(const Vector2& v) { x = v.x; y = v.y; color2 = v.color2; return *this; }
	~Vector2();
};


