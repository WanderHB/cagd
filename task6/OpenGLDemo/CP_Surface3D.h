// CP_Surface3D.h: ����CP_Surface3D��CP_Plane��CP_Sphere��CP_Cylinder
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

    virtual void mf_drawSolid(bool normalFlag=true)=0; // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( )=0;
}; // ��CP_Surface3D�������

// ��������Ϊ: S(u, v)=m_center + m_axisX*u + m_axisY*v
class CP_Plane : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
public:
    CP_Plane( );
    CP_Plane(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy);
    virtual ~CP_Plane( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_Plane�������

// ��������Ϊ: S(u, v)=m_center + m_axisX*x + m_axisY*y +vz*z
// ����: x = m_radius * sin(v * PI) * cos(u * PI2);
//       y = m_radius * sin(v * PI) * sin(u * PI2);
//         z = m_radius * cos(v * PI);
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

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_Sphere�������

// ��������Ϊ: m_center + m_axisX*x + m_axisY*y +vz*z
// ����, x = m_radius * cos(u * PI2);
//       y = m_radius * sin(u * PI2);
//       z = v * m_height;
//       vz = m_axisX ^ m_axisY;
// ����u��v�Ļ���������Ϊu, v \in [0, 1]��
class CP_Cylinder : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double   m_radius;
    double   m_height;
public:
    CP_Cylinder( );
    CP_Cylinder(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double h);
    virtual ~CP_Cylinder( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_Cylinder�������

// ��������Ϊ��m_center + m_axisX*x + m_axisY*y
// ����, x = v * m_radius * cos(u * PI2);
//       y = v * m_radius * sin(u * PI2);
// ����u��v�Ļ���������Ϊu, v \in [0, 1]��
class CP_Circle : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double   m_radius;
public:
    CP_Circle( );
    CP_Circle(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r);
    virtual ~CP_Circle( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_Circle�������

// ��������Ϊ��m_center + m_axisX*x + m_axisY*y
// ����,
//double a = startAngle+(endAngle-startAngle)*u;
//	double x = v * m_radius * cos(a * PI2);
//	double y = v * m_radius * sin(a * PI2);
// ����u��v�Ļ���������Ϊu, v \in [0, 1]
class CP_ArcSurface : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double   m_radius;
    double   startAngle;
    double	 endAngle;
public:
    CP_ArcSurface( );
    CP_ArcSurface(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double startAngle, double endAngle);
    virtual ~CP_ArcSurface( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_ArcSurface�������

//�ԳƵ�����+�ԳƵ���������ɵĹ���ƽ��
//startAngle endAngleֻҪע����С���Ǹ����εĽǶȼ��ɣ��㷨�Լ��ڲ�����Դ˵�����һ��
class CP_ArcSquSurface : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double   m_radius;
    double   startAngle;
    double	 endAngle;
public:
    CP_ArcSquSurface( );
    CP_ArcSquSurface(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double startAngle, double endAngle);
    virtual ~CP_ArcSquSurface( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_ArcSquSurface�������

// ��������Ϊ: m_center + m_axisX*x + m_axisY*y +vz*z
// ����, x = m_radius * cos(u * PI2);
//       y = m_radius * sin(u * PI2);
//       z = v * m_height;
//       vz = m_axisX ^ m_axisY;
// ����u��v�Ļ���������Ϊu, v \in [0, 1]��
class CP_CylinderTrimmed : public CP_Surface3D
{
public:
    CP_Point3D m_center;
    CP_Vector3D m_axisX;
    CP_Vector3D m_axisY;
    double   m_radius;
    double   m_height;
	double m_u1,m_u2,m_u3,m_u4,m_v1,m_v2;
public:
    CP_CylinderTrimmed( );
    CP_CylinderTrimmed(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double h, 
		double u1,double u2,double u3,double u4, double v1,double v2);
    virtual ~CP_CylinderTrimmed( ) { };
    virtual CP_Point3D mf_getPoint(double u, double v) const;
    virtual CP_Point3D mf_getPoint(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getNormal(double u, double v) const;
    virtual CP_Vector3D mf_getNormal(const CP_Point2D& uv) const;
    virtual CP_Vector3D mf_getUnitNormal(double u, double v) const;
    virtual CP_Vector3D mf_getUnitNormal(const CP_Point2D& uv) const;

    virtual void mf_drawSolid(bool normalFlag=true); // normalFlag: true(������ȡ����); false(������ȡ����)
    virtual void mf_drawWireframe( );
}; // ��CP_CylinderTrimmed�������

#endif