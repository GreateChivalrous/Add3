#pragma once
#include"Border3.h"
#include"vector"
class Surface3
{
public:
	vector<Vector3*> surfacePeakTable;
	BOOL shouldBeShow=true;
	Surface3();
	Surface3(const vector<Vector3*>& p) { surfacePeakTable.assign(p.begin(),p.end()); }
	~Surface3();
	/*vector<Vector3>& GetVectorV3();*/
	 Vector3 GetGravity();
	/*virtual Vector3 GetIncentre();
	virtual Vector3 GetCircumcentre();*/
	//��ȡƽ�淨����
	Vector3 GetLawVector();
	//������
	void blanking(const Vector3& n/*������*/);

};

