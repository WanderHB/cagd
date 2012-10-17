// CP_Surface3D.h: ����CP_Surface3D��CP_Sphere
#ifndef CP_SURFACE3D_H
#define CP_SURFACE3D_H

#include "CP_PointVector.h"

class CP_Surface3D
{
public:
    CP_Surface3D( ) { };
    virtual ~CP_Surface3D( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const=0;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const=0;
    virtual CP_Vector3D mf_getNormal(double u, double v) const=0;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const=0;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const=0;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const=0;

    // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawSolid(bool normalFlag=true)=0;
    virtual void mf_drawWireframe( )=0;
}; // ��CP_Surface3D�������

// ��������Ϊ: S(u, v)=m_center + m_axisX*x + m_axisY*y +vz*z
// ����: x = m_radius * sin(v * PI) * cos(u * PI2);
//       y = m_radius * sin(v * PI) * sin(u * PI2);
//       z = m_radius * cos(v * PI);
//       vz = m_axisX ^ m_axisY;
// ����u��v�Ļ���������Ϊu, v \in [0, 1]��
class CP_Sphere : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double  m_radius;
public:
    CP_Sphere( );
    CP_Sphere(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r);
    virtual ~CP_Sphere( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawSolid(bool normalFlag=true);
    virtual void mf_drawWireframe( );
}; // ��CP_Sphere�������

#endif