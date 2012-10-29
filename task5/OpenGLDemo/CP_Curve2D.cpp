// CP_Curve2D.cpp: ʵ��CP_Curve2D��CP_LineSegment2D��CP_Circle2D��CP_Arc2D
#include "stdafx.h"
#include "CP_Curve2D.h"
#include "GL/GLU.H" // �Ѿ�����GL/GL.h

#include <math.h>

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_LineSegment2D��ʼ
CP_LineSegment2D::CP_LineSegment2D(double u1, double v1, double u2, double v2):m_startingPoint(u1, v1), m_endingPoint(u2, v2)
{
} // ��CP_LineSegment2D���캯������

CP_LineSegment2D::CP_LineSegment2D(const CP_Point2D& s, const CP_Point2D& e):m_startingPoint(s.m_x, s.m_y), m_endingPoint(e.m_x, e.m_y)
{
} // ��CP_LineSegment2D���캯������

CP_Point2D CP_LineSegment2D::mf_getStartingPoint( )
{
    return m_startingPoint;
} // ��Ա����mf_getStartingPoint����

CP_Point2D CP_LineSegment2D::mf_getEndingPoint( )
{
    return m_endingPoint;
} // ��Ա����mf_getEndingPoint����

CP_Point2D CP_LineSegment2D::mf_getPoint(double t)
{
    return m_startingPoint + (m_endingPoint - m_startingPoint) * t;
} // ��Ա����mf_getPoint����

void CP_LineSegment2D::mf_draw( )
{
    glLineWidth(2.25f);
    glBegin(GL_LINES);
        glVertex3d(m_startingPoint.m_x, m_startingPoint.m_y, 0.0);
        glVertex3d(m_endingPoint.m_x, m_endingPoint.m_y, 0.0);
    glEnd();
} // ��Ա����mf_draw����

// ʵ����CP_LineSegment2D����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Circle2D��ʼ
CP_Circle2D::CP_Circle2D( ): m_center(0.0, 0.0), m_axisX(1.0, 0.0), m_axisY(0.0, 1.0), m_radius(1.0)
{
} // ��CP_Circle2D���캯������

CP_Circle2D::CP_Circle2D(const CP_Point2D& c, const CP_Vector2D& vx, const CP_Vector2D& vy, double r)
    : m_center(c.m_x, c.m_y), m_axisX(vx.m_x, vx.m_y), m_axisY(vy.m_x, vy.m_y), m_radius(r)
{
} // ��CP_Circle2D���캯������

CP_Point2D CP_Circle2D::mf_getStartingPoint( )
{
    return m_center + m_axisX * m_radius;
} // ��Ա����mf_getStartingPoint����

CP_Point2D CP_Circle2D::mf_getEndingPoint( )
{
    return m_center + m_axisX * m_radius;
} // ��Ա����mf_getEndingPoint����

CP_Point2D CP_Circle2D::mf_getPoint(double t)
{
    double a = t * PI2;
    return (m_center+m_axisX*(cos(a)*m_radius)+m_axisY*(sin(a)*m_radius));
} // ��Ա����mf_getPoint����

void CP_Circle2D::mf_draw( )
{
    int numberOfSegment=40;
    double t = 0.0;
    double step = 1.0/numberOfSegment;
    CP_Point2D p;

    glLineWidth(2.2f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numberOfSegment; i++, t+=step)            
    {
        p = mf_getPoint(t);
        glVertex3d(p.m_x, p.m_y, 0.0);
    } // forѭ���ṹ����
    glEnd();
} // ��Ա����mf_draw����

// ʵ����CP_Circle2D����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Arc2D��ʼ
CP_Arc2D::CP_Arc2D( ): m_center(0.0, 0.0), m_axisX(1.0, 0.0), m_axisY(0.0, 1.0), m_radius(1.0), m_startintAngle(0.0), m_endintAngle(PI_2)
{
} // ��CP_Arc2D���캯������

CP_Arc2D::CP_Arc2D(const CP_Point2D& c, const CP_Vector2D& vx, const CP_Vector2D& vy, double r, double sa, double ea)
    : m_center(c.m_x, c.m_y), m_axisX(vx.m_x, vx.m_y), m_axisY(vy.m_x, vy.m_y), m_radius(r), m_startintAngle(sa), m_endintAngle(ea) 
{
} // ��CP_Arc2D���캯������

CP_Point2D CP_Arc2D::mf_getStartingPoint( )
{
    return m_center + m_axisX * (cos(m_startintAngle)*m_radius) + m_axisY * (sin(m_startintAngle) * m_radius);
} // ��Ա����mf_getStartingPoint����

CP_Point2D CP_Arc2D::mf_getEndingPoint( )
{
    return m_center + m_axisX * (cos(m_endintAngle)*m_radius) + m_axisY * (sin(m_endintAngle) * m_radius);
} // ��Ա����mf_getEndingPoint����

CP_Point2D CP_Arc2D::mf_getPoint(double t)
{
    double a = m_startintAngle+(m_endintAngle-m_startintAngle)*t;
    return m_center + m_axisX * (cos(a)*m_radius) + m_axisY * (sin(a) * m_radius);
} // ��Ա����mf_getPoint����

void CP_Arc2D::mf_draw( )
{
    glLineWidth(2.2f);
    int numberOfSegment=int(fabs(m_endintAngle-m_startintAngle)/PI2*40);
    if (numberOfSegment<5)
        numberOfSegment=5;
    double t = 0.0;
    double step = 1.0/numberOfSegment;
    CP_Point2D p;

    glLineWidth(2.2f);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < numberOfSegment; i++, t+=step)            
    {
        p = mf_getPoint(t);
        glVertex3d(p.m_x, p.m_y, 0.0);
    } // forѭ���ṹ����
    glEnd();
} // ��Ա����mf_draw����

// ʵ����CP_Arc2D����
// ////////////////////////////////////////////////////////////////////////////
