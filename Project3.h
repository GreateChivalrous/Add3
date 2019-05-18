#pragma once
#include"Surface3.h"
#include"vector"
#include"Matrix4x3.h"
#include"iostream"
using namespace std;
#define WIREFRAME 0
#define SURFACE 1
#define ENTITY 2
class Project3
{
public:
	vector<Vector3> peakTable;
	vector<Border3> borderTable;
	vector<Surface3> surfaceTable;

	Project3();
	
	Project3(vector<Vector3> p, string str/*, vector<Surface3> s*/);
	Project3(const vector<Vector3>& p, const vector<Surface3>& s);
	~Project3();
	void SetSurface(string str);
	void transWithMatrix(Matrix4x3& m) {
		for (vector<Vector3>::iterator iter = peakTable.begin(); iter != peakTable.end(); ++iter) {
			*(iter) = *(iter) * m;
		}
		
	}
	//三维物体消隐(面消隐)
	void faceBlanking(const Vector3& n/*视向量*/);
	//线框模型消隐
	void frameBlanking(const Vector3& n);
	void outputPeak() { for (unsigned int i = 0; i < peakTable.size(); i++) {
		peakTable[i].toString();
	} }
};
