// CP_Surface3D.cpp: ʵ��CP_Surface3D��CP_Plane��CP_Sphere��CP_Cylinder
#include "stdafx.h"
#include "CP_Surface3D.h"
#include "GL/GLU.H" // �Ѿ�����GL/GL.h

#include <math.h>

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Plane��ʼ
CP_Plane::CP_Plane( ): m_center(0.0, 0.0, 0.0), m_axisX(1.0, 0.0, 0.0), m_axisY(0.0, 1.0, 0.0)
{
} // ��CP_Plane���캯������

CP_Plane::CP_Plane(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy)
    : m_center(c.m_x, c.m_y, c.m_z), m_axisX(vx.m_x, vx.m_y, vx.m_z), m_axisY(vy.m_x, vy.m_y, vy.m_z)
{
} // ��CP_Plane���캯������

CP_Point3D CP_Plane::mf_getPoint(double u, double v) const
{
    return m_center + m_axisX*u + m_axisY*v;
} // ��Ա����mf_getPoint����

CP_Point3D CP_Plane::mf_getPoint(const CP_Point2D& uv) const
{
    return m_center + m_axisX*uv.m_x + m_axisY*uv.m_y;
} // ��Ա����mf_getPoint����

CP_Vector3D CP_Plane::mf_getNormal(double u, double v) const
{
    return m_axisX ^ m_axisY;
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Plane::mf_getNormal(const CP_Point2D& uv) const
{
    return m_axisX ^ m_axisY;
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Plane::mf_getUnitNormal(double u, double v) const
{
    CP_Vector3D vz = m_axisX ^ m_axisY;
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����


CP_Vector3D CP_Plane::mf_getUnitNormal(const CP_Point2D& uv) const
{
    CP_Vector3D vz = m_axisX ^ m_axisY;
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����

void CP_Plane::mf_drawSolid(bool normalFlag)
{
    double u[]={0.0, 1.0, 1.0, 0.0, 0.0};
    double v[]={0.0, 0.0, 1.0, 1.0, 0.0};
    CP_Point3D p;
    CP_Vector3D vz = mf_getUnitNormal(0.0, 0.0);
    if (!normalFlag)
        vz*=(-1);
    glNormal3d(vz.m_x, vz.m_y, vz.m_z);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 3; i++)
    {
        p = mf_getPoint(u[i], v[i]);
        glVertex3d(p.m_x, p.m_y, p.m_z);
    } // forѭ���ṹ����
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 2; i < 5; i++)
    {
        p = mf_getPoint(u[i], v[i]);
        glVertex3d(p.m_x, p.m_y, p.m_z);
    } // forѭ���ṹ����
    glEnd();
} // ��Ա����mf_drawSolid����

void CP_Plane::mf_drawWireframe( )
{
    double u[]={0.0, 1.0, 1.0, 0.0, 0.0};
    double v[]={0.0, 0.0, 1.0, 1.0, 0.0};
    CP_Point3D p;
    glLineWidth(2.2f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++)
    {
        p = mf_getPoint(u[i], v[i]);
        glVertex3d(p.m_x, p.m_y, p.m_z);
    } // forѭ���ṹ����
    glEnd();
    glBegin(GL_LINE_LOOP);
    for (int i = 2; i < 5; i++)
    {
        p = mf_getPoint(u[i], v[i]);
        glVertex3d(p.m_x, p.m_y, p.m_z);
    } // forѭ���ṹ����
    glEnd();
} // ��Ա����mf_drawWireframe����

// ʵ����CP_Plane����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Sphere��ʼ
CP_Sphere::CP_Sphere( ): m_center(0.0, 0.0, 0.0), m_axisX(1.0, 0.0, 0.0), m_axisY(0.0, 1.0, 0.0), m_radius(2.0)
{
} // ��CP_Sphere���캯������

CP_Sphere::CP_Sphere(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r)
    : m_center(c.m_x, c.m_y, c.m_z), m_axisX(vx.m_x, vx.m_y, vx.m_z), m_axisY(vy.m_x, vy.m_y, vy.m_z), m_radius(r)
{
} // ��CP_Sphere���캯������

CP_Point3D CP_Sphere::mf_getPoint(double u, double v) const
{
    double r1 = m_radius * sin(v * PI);
    double x = r1 * cos(u * PI2);
    double y = r1 * sin(u * PI2);
    double z = m_radius * cos(v * PI);
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_center + m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getPoint����

CP_Point3D CP_Sphere::mf_getPoint(const CP_Point2D& uv) const
{
    double r1 = m_radius * sin(uv.m_y * PI);
    double x = r1 * cos(uv.m_x * PI2);
    double y = r1 * sin(uv.m_x * PI2);
    double z = m_radius * cos(uv.m_y * PI);
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_center + m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getPoint����

CP_Vector3D CP_Sphere::mf_getNormal(double u, double v) const
{
    double sv = sin(v * PI);
    double A=-2*PI*PI*m_radius*m_radius*sv;
    double x = A*sv * cos(u * PI2);
    double y = A*sv * sin(u * PI2);
    double z = A*cos(v * PI);
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Sphere::mf_getNormal(const CP_Point2D& uv) const
{
    double sv = sin(uv.m_y * PI);
    double A=-2*PI*PI*m_radius*m_radius*sv;
    double x = A*sv * cos(uv.m_x * PI2);
    double y = A*sv * sin(uv.m_x * PI2);
    double z = A*cos(uv.m_y * PI);
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Sphere::mf_getUnitNormal(double u, double v) const
{
    CP_Vector3D vz = mf_getNormal(u, v);
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����

CP_Vector3D CP_Sphere::mf_getUnitNormal(const CP_Point2D& uv) const
{
    CP_Vector3D vz = mf_getNormal(uv);
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����

void CP_Sphere::mf_drawSolid(bool normalFlag)
{
    int i, j, k;
    int nu=40;
    int nv=20;
    double stepU=1.0/nu;
    double stepV=1.0/nv;
    double du, dv;
    CP_Point3D p, p0;
    CP_Vector3D v, v0;

    // �¶���������: ע��mf_getPoint(u, 0.0)��Ϊͬһ����
    p0=mf_getPoint(0.0, 0.0);
    v0=mf_getUnitNormal(0.0, 0.0);
    if (!normalFlag)
        v0*=(-1);
    for (j=0, du=0.0; j<nu; j++)
    {
        glBegin(GL_POLYGON);
            glNormal3d(v0.m_x, v0.m_y, v0.m_z);
            glVertex3d(p0.m_x, p0.m_y, p0.m_z);
            p=mf_getPoint(du, stepV);
            v=mf_getUnitNormal(du, stepV);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
            du+=stepU;
            p=mf_getPoint(du, stepV);
            v=mf_getUnitNormal(du, stepV);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        glEnd();
    } // forѭ���ṹ����

    // �м���������
    for (i=2, dv=stepV; i<nv; i++, dv+=stepV)
    {
        for (j=0, du=0.0; j<nu; j++, du+=stepU)
        {
            double uu[ ]={du, du+stepU, du+stepU, du,       du};
            double vv[ ]={dv, dv,       dv+stepV, dv+stepV, dv};
            glBegin(GL_POLYGON);
            for (k=0; k<3; k++)
            {
                p=mf_getPoint(uu[k], vv[k]);
                v=mf_getUnitNormal(uu[k], vv[k]);
                if (!normalFlag)
                    v*=(-1);
                glNormal3d(v.m_x, v.m_y, v.m_z);
                glVertex3d(p.m_x, p.m_y, p.m_z);
            } // �ڲ�(k)forѭ���ṹ����
            glEnd();
            glBegin(GL_POLYGON);
            for (k=2; k<5; k++)
            {
                p=mf_getPoint(uu[k], vv[k]);
                v=mf_getUnitNormal(uu[k], vv[k]);
                if (!normalFlag)
                    v*=(-1);
                glNormal3d(v.m_x, v.m_y, v.m_z);
                glVertex3d(p.m_x, p.m_y, p.m_z);
            } // �ڲ�(k)forѭ���ṹ����
            glEnd();
        } // �ڲ�(j)forѭ���ṹ����
    } // ���(i)forѭ���ṹ����

    // �϶���������: ע��mf_getPoint(u, 1.0)��Ϊͬһ����
    p0=mf_getPoint(0.0, 1.0);
    v0=mf_getUnitNormal(0.0, 1.0);
    if (!normalFlag)
        v0*=(-1);
    for (j=0, du=0.0; j<nu; j++)
    {
        glBegin(GL_POLYGON);
            glNormal3d(v0.m_x, v0.m_y, v0.m_z);
            glVertex3d(p0.m_x, p0.m_y, p0.m_z);
            p=mf_getPoint(du, 1-stepV);
            v=mf_getUnitNormal(du, 1-stepV);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
            du+=stepU;
            p=mf_getPoint(du, 1-stepV);
            v=mf_getUnitNormal(du, 1-stepV);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        glEnd();
    } // forѭ���ṹ����
} // ��Ա����mf_drawSolid����

void CP_Sphere::mf_drawWireframe( )
{
    int i, j, k;
    int nu=40;
    int nv=20;
    double stepU=1.0/nu;
    double stepV=1.0/nv;
    double u, v;
    CP_Point3D p, p0;

    // �¶���������: ע��mf_getPoint(u, 0.0)��Ϊͬһ����
    glLineWidth(2.2f);
    p0=mf_getPoint(0.0, 0.0);
    for (j=0, u=0.0; j<nu; j++)
    {
        glBegin(GL_LINE_LOOP);
            glVertex3d(p0.m_x, p0.m_y, p0.m_z);
            p=mf_getPoint(u, stepV);
            glVertex3d(p.m_x, p.m_y, p.m_z);
            u+=stepU;
            p=mf_getPoint(u, stepV);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        glEnd();
    } // forѭ���ṹ����

    // �м���������
    for (i=2, v=stepV; i<nv; i++, v+=stepV)
    {
        for (j=0, u=0.0; j<nu; j++, u+=stepU)
        {
            double uu[ ]={u, u+stepU, u+stepU, u,       u};
            double vv[ ]={v, v,       v+stepV, v+stepV, v};
            glBegin(GL_LINE_LOOP);
            for (k=0; k<3; k++)
            {
                p=mf_getPoint(uu[k], vv[k]);
                glVertex3d(p.m_x, p.m_y, p.m_z);
            } // �ڲ�(k)forѭ���ṹ����
            glEnd();
            glBegin(GL_LINE_LOOP);
            for (k=2; k<5; k++)
            {
                p=mf_getPoint(uu[k], vv[k]);
                glVertex3d(p.m_x, p.m_y, p.m_z);
            } // �ڲ�(k)forѭ���ṹ����
            glEnd();
        } // �ڲ�(j)forѭ���ṹ����
    } // ���(i)forѭ���ṹ����

    // �϶���������: ע��mf_getPoint(u, 1.0)��Ϊͬһ����
    p0=mf_getPoint(0.0, 1.0);
    for (j=0, u=0.0; j<nu; j++)
    {
        glBegin(GL_LINE_LOOP);
            glVertex3d(p0.m_x, p0.m_y, p0.m_z);
            p=mf_getPoint(u, 1-stepV);
            glVertex3d(p.m_x, p.m_y, p.m_z);
            u+=stepU;
            p=mf_getPoint(u, 1-stepV);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        glEnd();
    } // forѭ���ṹ����
} // ��Ա����mf_drawWireframe����

// ʵ����CP_Sphere����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Cylinder��ʼ
CP_Cylinder::CP_Cylinder( ): m_center(0.0, 0.0, 0.0), m_axisX(1.0, 0.0, 0.0), m_axisY(0.0, 1.0, 0.0), m_radius(1.0), m_height(3.0)
{
} // ��CP_Cylinder���캯������

CP_Cylinder::CP_Cylinder(const CP_Point3D& c, const CP_Vector3D& vx, const CP_Vector3D& vy, double r, double h)
    : m_center(c.m_x, c.m_y, c.m_z), m_axisX(vx.m_x, vx.m_y, vx.m_z), m_axisY(vy.m_x, vy.m_y, vy.m_z), m_radius(r), m_height(h)
{
} // ��CP_Cylinder���캯������

CP_Point3D CP_Cylinder::mf_getPoint(double u, double v) const
{
    double x = m_radius * cos(u * PI2);
    double y = m_radius * sin(u * PI2);
    double z = v * m_height;
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_center + m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getPoint����

CP_Point3D CP_Cylinder::mf_getPoint(const CP_Point2D& uv) const
{
    double x = m_radius * cos(uv.m_x * PI2);
    double y = m_radius * sin(uv.m_x * PI2);
    double z = uv.m_y * m_height;
    CP_Vector3D vz = m_axisX ^ m_axisY;
    return m_center + m_axisX*x + m_axisY*y +vz*z;
} // ��Ա����mf_getPoint����

CP_Vector3D CP_Cylinder::mf_getNormal(double u, double v) const
{
    return m_axisX * cos(u*PI2) + m_axisY * sin(u*PI2);
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Cylinder::mf_getNormal(const CP_Point2D& uv) const
{
    return m_axisX * cos(uv.m_x*PI2) + m_axisY * sin(uv.m_x*PI2);
} // ��Ա����mf_getNormal����

CP_Vector3D CP_Cylinder::mf_getUnitNormal(double u, double v) const
{
    CP_Vector3D vz = mf_getNormal(u, v);
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����

CP_Vector3D CP_Cylinder::mf_getUnitNormal(const CP_Point2D& uv) const
{
    CP_Vector3D vz = mf_getNormal(uv);
    vz.mf_normalize( );
    return vz;
} // ��Ա����mf_getUnitNormal����

void CP_Cylinder::mf_drawSolid(bool normalFlag)
{
    int i, k;
    int nu=40;
    double stepU=1.0/nu;
    double u;
    double vv[ ]={0.0, 0.0, 1.0, 1.0, 0.0};
    CP_Point3D p;
    CP_Vector3D v;

    for (i=0, u=0.0; i<nu; i++, u+=stepU)
    {
        double uu[ ]={u, u+stepU, u+stepU, u, u};
        glBegin(GL_POLYGON);
        for (k=0; k<3; k++)
        {
            p=mf_getPoint(uu[k], vv[k]);
            v=mf_getUnitNormal(uu[k], vv[k]);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        } // �ڲ�(k)forѭ���ṹ����
        glEnd();
        glBegin(GL_POLYGON);
        for (k=2; k<5; k++)
        {
            p=mf_getPoint(uu[k], vv[k]);
            v=mf_getUnitNormal(uu[k], vv[k]);
            if (!normalFlag)
                v*=(-1);
            glNormal3d(v.m_x, v.m_y, v.m_z);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        } // �ڲ�(k)forѭ���ṹ����
        glEnd();
    } // ���(i)forѭ���ṹ����
} // ��Ա����mf_drawSolid����

void CP_Cylinder::mf_drawWireframe( )
{
    int i, k;
    int nu=40;
    double stepU=1.0/nu;
    double u;
    double vv[ ]={0.0, 0.0, 1.0, 1.0, 0.0};
    CP_Point3D p;

    glLineWidth(2.2f);
    for (i=0, u=0.0; i<nu; i++, u+=stepU)
    {
        double uu[ ]={u, u+stepU, u+stepU, u, u};
        glBegin(GL_LINE_LOOP);
        for (k=0; k<3; k++)
        {
            p=mf_getPoint(uu[k], vv[k]);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        } // �ڲ�(k)forѭ���ṹ����
        glEnd();
        glBegin(GL_LINE_LOOP);
        for (k=2; k<5; k++)
        {
            p=mf_getPoint(uu[k], vv[k]);
            glVertex3d(p.m_x, p.m_y, p.m_z);
        } // �ڲ�(k)forѭ���ṹ����
        glEnd();
    } // ���(i)forѭ���ṹ����
} // ��Ա����mf_drawWireframe����

// ʵ����CP_Cylinder����
// ////////////////////////////////////////////////////////////////////////////

