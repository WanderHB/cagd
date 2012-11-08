// CP_Curve3D.h: ����CP_Curve3D��CP_LineSegment3D��CP_Circle3D��CP_Arc3D
#ifndef CP_CURVE3D_H
#define CP_CURVE3D_H

#include "CP_PointVector.h"

class CP_Curve3D
{
public:
    CP_Curve3D( ) { };
    virtual ~CP_Curve3D( ) { };
    virtual CP_Point3D mf_getStartingPoint( )=0;
    virtual CP_Point3D mf_getEndingPoint( )=0;
    virtual CP_Point3D mf_getPoint(double t) const =0;
    virtual void mf_draw( )=0;
}; // ��CP_Curve3D�������

// ��������Ϊ: C(t)=m_startingPoint+(m_endingPoint-m_startingPoint)*t
class CP_LineSegment3D : public CP_Curve3D
{
public:
    CP_Point3D m_startingPoint, m_endingPoint;
public:
    CP_LineSegment3D(double x1=0.0, double y1=0.0, double z1=0.0, double x2=1.0, double y2=0.0, double z2=0.0);
    CP_LineSegment3D(const CP_Point3D& s, const CP_Point3D& e);
    virtual~CP_LineSegment3D( ) { };
    virtual CP_Point3D mf_getStartingPoint( );
    virtual CP_Point3D mf_getEndingPoint( );
    virtual CP_Point3D mf_getPoint(double t) const; // ����tӦ������0��1֮��
    virtual void mf_draw( );
}; // ��CP_LineSegment3D�������

// ��������Ϊ: C(t)=m_center+m_axisX*(cos(t*2PI)*m_radius)+m_axisY*(sin(t*2PI)*m_radius)
// ����tӦ������0��1֮��
class CP_Circle3D : public CP_Curve3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;

    double m_radius;     // Բ�İ뾶
public:
    CP_Circle3D( );
    CP_Circle3D(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r);
    virtual~CP_Circle3D( ) { };

    virtual CP_Point3D mf_getStartingPoint( );
    virtual CP_Point3D mf_getEndingPoint( );
    virtual CP_Point3D mf_getPoint(double t) const; // ����tӦ������0��1֮��
    virtual void mf_draw( );
};

// ��������Ϊ: C(t)=m_center + m_axisX * (cos(a)*m_radius) + m_axisY * (sin(a) * m_radius),
// ����a = m_startintAngle+(m_endintAngle-m_startintAngle)*t;
// ����tӦ������0��1֮��
class CP_Arc3D : public CP_Curve3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;

    double m_radius;     // Բ�İ뾶
    double m_startintAngle, m_endintAngle; // Բ������ʼ�Ǻ���ֹ��, ��λΪ����
public:
    CP_Arc3D( );
    CP_Arc3D(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double sa, double ea);
    virtual~CP_Arc3D( ) { };

    virtual CP_Point3D mf_getStartingPoint( );
    virtual CP_Point3D mf_getEndingPoint( );
    virtual CP_Point3D mf_getPoint(double t) const; // ����tӦ������0��1֮��
    virtual void mf_draw( );
};

#endif