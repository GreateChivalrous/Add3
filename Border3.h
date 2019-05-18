#pragma once
#include"Vector3.h"


class Border3
{
public:
	Vector3* start;
	Vector3* end;
	BOOL shouldBeShow;
	Border3();
	Border3(Vector3* s, Vector3* e, BOOL sbs = true) { start = s; end = e; shouldBeShow = sbs; }
	
	~Border3();
};

