#include "Project3.h"



Project3::Project3()
{
}


Project3::~Project3()
{
}

Project3::Project3(vector<Vector3> p, string str/*, vector<Surface3> s*/) {
	peakTable.assign(p.begin(), p.end());
	string::size_type pos1, pos2;
	string c = ",";
	pos2 = str.find(c);
	pos1 = 0;
	bool oddeve = false;
	int i;
	Vector3* start = NULL;
	Vector3* end = NULL;
	while (string::npos != pos2)
	{
		sscanf_s(data(str.substr(pos1, pos2 - pos1)), "%d", &i);
		cout << i << endl;
		if (oddeve) {
			end = &peakTable[i];
			borderTable.push_back(Border3(start, end));
			oddeve = !oddeve;
		}
		else { start = &peakTable[i]; oddeve = !oddeve; }


		pos1 = pos2 + c.size();
		pos2 = str.find(c, pos1);
	}

}
Project3::Project3(const vector<Vector3>& p, const vector<Surface3>& s) {
	peakTable.assign(p.begin(), p.end());
	surfaceTable.assign(s.begin(), s.end());
}
void Project3::faceBlanking(const Vector3& n/*йсоРа©*/) {
	for (vector<Surface3>::iterator iter = surfaceTable.begin(); iter != surfaceTable.end(); iter++) {
		iter->blanking(n);
	}
}
void Project3::frameBlanking(const Vector3& n) {

}
void Project3::SetSurface(string str) {

}