#include "CP_PointVector.h"
#include <vector>
using namespace std;

class DelaunayEdge
{
public:
	CP_Point2D p0, p1;
	DelaunayEdge(CP_Point2D &p0, CP_Point2D &p1);
	DelaunayEdge();
	~DelaunayEdge(){};
	
	/*
	//��set����ʱ����д�˷��������ж��ظ���setԪ��
	friend bool operator < (DelaunayEdge const &a,DelaunayEdge const &b)
	{
		bool res = (a.p0.m_x == b.p0.m_x &&
					a.p0.m_y == b.p0.m_y &&
					a.p1.m_x == b.p1.m_x &&
					a.p1.m_y == b.p1.m_y);
		if (res) return false;
		return true;
	}
	*/
};

class DelaunayTriangle
{
public:
	CP_Point2D p0, p1, p2;
	//���ԲԲ��
	CP_Point2D center;
	//���Բ�뾶
	double radius_squared,radius;
	
	DelaunayTriangle();
	DelaunayTriangle(CP_Point2D &p0, CP_Point2D &p1, CP_Point2D &p2);
	void draw();
	//ĳ���Ƿ��������Բ��
	bool includingPoint(CP_Point2D &p);
	
	~DelaunayTriangle(){};
protected:
	void calRadius();
};

//����㣬�����ʷֺ��������
vector<DelaunayTriangle> doDelaunayTriangulate(vector<CP_Point2D> points);
//���������Ĵ�������
DelaunayTriangle createBigTriangle(vector<CP_Point2D>);
