// CP_Topology.cpp: ʵ��CP_Body��CP_Face��CP_Loop��CP_Coedge��CP_Edge��CP_Vertex
#include "stdafx.h"
#include "CP_Topology.h"
#include "GL/GLU.H" // �Ѿ�����GL/GL.h

#include <math.h>

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Body��ʼ

CP_Body::~CP_Body( )
{
    int i;
    int n = (int)m_faceArray.GetSize( );
    for (i = 0; i < n; i++)
        delete m_faceArray[i];
    m_faceArray.RemoveAll( );

    n = (int)m_edgeArray.GetSize( );
    for (i = 0; i < n; i++)
        delete m_edgeArray[i];
    m_edgeArray.RemoveAll( );

    n = m_vertexArray.GetSize( );
	/*
    for (i = 0; i < n; i++)
        delete m_vertexArray[i];
    m_vertexArray.RemoveAll( );
	*/
} // ��CP_Body��������������

CP_Face* CP_Body::mf_getFace(int index) const
{
    int n = (int)m_faceArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Face *)(m_faceArray[index]);
} // ��Ա����mf_getFace����

CP_Edge* CP_Body::mf_getEdge(int index) const
{
    int n = m_edgeArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Edge *)(m_edgeArray[index]);
} // ��Ա����mf_getEdge����

CP_Vertex* CP_Body::mf_getVertex(int index) const
{
    int n = m_vertexArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Vertex *)(m_vertexArray[index]);
} // ��Ա����mf_getVertex����

int CP_Body::mf_findFaceIndex(CP_Face *face) const
{
    int n = (int)m_faceArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_faceArray[i] == face)
            return i;
    return -1;
} // ��Ա����mf_findFaceIndex����

int CP_Body::mf_findEdgeIndex(CP_Edge *edge) const
{
    int n = (int)m_edgeArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_edgeArray[i] == edge)
            return i;
    return -1;
} // ��Ա����mf_findEdgeIndex����

int CP_Body::mf_findVertexIndex(CP_Vertex *vertex) const
{
    int n = (int)m_vertexArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_vertexArray[i] == vertex)
            return i;
    return -1;
} // ��Ա����mf_findVertexIndex����

void CP_Body::mf_addFace(CP_Face *face)
{
    m_faceArray.Add(face);
} // ��Ա����mf_addFace����

void CP_Body::mf_addEdge(CP_Edge *edge)
{
    m_edgeArray.Add(edge);
} // ��Ա����mf_addEdge����

void CP_Body::mf_addVertex(CP_Vertex *vertex)
{
    m_vertexArray.Add(vertex);
} // ��Ա����mf_addVertex����

void CP_Body::mf_removeFace(int index)
{
    CP_Face* face=mf_getFace(index);
    if (face!=NULL)
    {
        delete face;
        m_faceArray.RemoveAt(index);
    } // if �ṹ����
} // ��Ա����mf_removeFace����

void CP_Body::mf_removeEdge(int index)
{
    CP_Edge* edge=mf_getEdge(index);
    if (edge!=NULL)
    {
        delete edge;
        m_edgeArray.RemoveAt(index);
    } // if �ṹ����
} // ��Ա����mf_removeEdge����

void CP_Body::mf_removeVertex(int index)
{
    CP_Vertex* v=mf_getVertex(index);
    if (v!=NULL)
    {
        delete v;
        m_vertexArray.RemoveAt(index);
    } // if �ṹ����
} // ��Ա����mf_removeVertex����

void CP_Body::mf_removeAllFace()
{
    int n = (int)m_faceArray.GetSize( );
    for (int i = 0; i < n; i++)
        delete m_faceArray[i];
    m_faceArray.RemoveAll( );
} // ��Ա����mf_removeAllFace����

void CP_Body::mf_removeAllEdge()
{
    int n = (int)m_edgeArray.GetSize( );
    for (int i = 0; i < n; i++)
        delete m_edgeArray[i];
    m_edgeArray.RemoveAll( );
} // ��Ա����mf_removeAllEdge����

void CP_Body::mf_removeAllVertex()
{
    int n = (int)m_vertexArray.GetSize( );
    for (int i = 0; i < n; i++)
        delete m_vertexArray[i];
    m_vertexArray.RemoveAll( );
} // ��Ա����mf_removeAllVertex����

// ʵ����CP_Body����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Face��ʼ
CP_Face::CP_Face( ): m_parent(NULL), m_surface(NULL), m_sameNormalDirection(true)
{
} // ��CP_Face�Ĺ��캯������

CP_Face::CP_Face(CP_Body *parent, CP_Surface3D *surf, bool samedir)
    : m_parent(parent), m_surface(surf), m_sameNormalDirection(samedir)
{
} // ��CP_Face�Ĺ��캯������

CP_Face::~CP_Face( )
{
	delete m_surface;
    int n=(int)m_loopArray.GetSize( );
	for (int i = 0; i < n; i++)
		delete m_loopArray[i];
	m_loopArray.RemoveAll( );
} // ��CP_Face��������������

CP_Loop* CP_Face::mf_getLoop(int index) const
{
    int n = (int)m_loopArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Loop *)(m_loopArray[index]);
} // ��Ա����mf_getLoop����

int CP_Face::mf_findLoopIndex(CP_Loop *loop) const
{
    int n = (int)m_loopArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_loopArray[i] == loop)
            return i;
    return -1;
} // ��Ա����mf_findLoopIndex����

void CP_Face::mf_addLoop(CP_Loop *loop)
{
    m_loopArray.Add(loop);
} // ��Ա����mf_addLoop����

void CP_Face::mf_removeLoop(int index)
{
    CP_Loop* loop=mf_getLoop(index);
    if (loop!=NULL)
    {
        delete loop;
        m_loopArray.RemoveAt(index);
    } // if �ṹ����
} // ��Ա����mf_removeLoop����

void CP_Face::mf_removeAllLoop()
{
    int n=(int)m_loopArray.GetSize( );
	for (int i = 0; i < n; i++)
		delete m_loopArray[i];
	m_loopArray.RemoveAll( );
} // ��Ա����mf_removeAllLoop����

// ʵ����CP_Face����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Loop��ʼ
CP_Loop::CP_Loop( ): m_parent(NULL)
{
} // ��CP_Loop�Ĺ��캯������

CP_Loop::CP_Loop(CP_Face* face): m_parent(face)
{
} // ��CP_Loop�Ĺ��캯������

CP_Loop::~CP_Loop( )
{
    int n = (int)m_coedgeArray.GetSize();
    for (int i=0; i<n; i++)
        delete m_coedgeArray[i];
    m_coedgeArray.RemoveAll();
} // ��CP_Loop��������������

CP_Coedge* CP_Loop::mf_getCoedge(int index) const
{
    int n = (int)m_coedgeArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Coedge *)(m_coedgeArray[index]);
} // ��Ա����mf_getCoedge����

int CP_Loop::mf_findCoedgeIndex(CP_Coedge *coedge) const
{
    int n = (int)m_coedgeArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_coedgeArray[i] == coedge)
            return i;
    return -1;
} // ��Ա����mf_findCoedgeIndex����

void CP_Loop::mf_addCoedge(CP_Coedge *coedge)
{
    m_coedgeArray.Add(coedge);
} // ��Ա����mf_addCoedge����

void CP_Loop::mf_removeCoedge(int index)
{
    CP_Coedge* coedge=mf_getCoedge(index);
    if (coedge!=NULL)
    {
        delete coedge;
        m_coedgeArray.RemoveAt(index);
    } // if �ṹ����
} // ��Ա����mf_removeCoedge����

void CP_Loop::mf_removeAllCoedge( )
{
    int n = (int)m_coedgeArray.GetSize();
    for (int i=0; i<n; i++)
        delete m_coedgeArray[i];
    m_coedgeArray.RemoveAll();
} // ��Ա����mf_removeAllCoedge����

// ʵ����CP_Loop����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Coedge��ʼ
CP_Coedge::CP_Coedge( ) : m_curve2D(NULL), m_parent(NULL), m_edge(NULL), m_sameDirection(true)
{
} // ��CP_Coedge�Ĺ��캯������

CP_Coedge::CP_Coedge(CP_Curve2D *curve, CP_Loop *parent, CP_Edge *edge, bool sameDir)
    : m_curve2D(curve), m_parent(parent), m_edge(edge), m_sameDirection(sameDir)
{
} // ��CP_Coedge�Ĺ��캯������

CP_Coedge::~CP_Coedge( )
{
    delete m_curve2D;
} // ��CP_Coedge��������������

// ʵ����CP_Coedge����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Edge��ʼ
CP_Edge::CP_Edge( ) : m_curve3D(NULL), m_startingVertex(NULL), m_endingVertex(NULL)
{
} // ��CP_Edge�Ĺ��캯������

CP_Edge::CP_Edge(CP_Curve3D* c, CP_Vertex* s, CP_Vertex* e)
    : m_curve3D(c), m_startingVertex(s), m_endingVertex(e)
{
} // ��CP_Edge�Ĺ��캯������

CP_Edge::~CP_Edge( )
{
    delete m_curve3D;
} // ��CP_Edge��������������

CP_Coedge* CP_Edge::mf_getCoedge(int index) const
{
    int n = (int)m_coedgeArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Coedge *)(m_coedgeArray[index]);
} // ��Ա����mf_getCoedge����

int CP_Edge::mf_findCoedgeIndex(CP_Coedge *coedge) const
{
    int n = (int)m_coedgeArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_coedgeArray[i] == coedge)
            return i;
    return -1;
} // ��Ա����mf_findCoedgeIndex����

// ʵ����CP_Edge����
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ʵ����CP_Vertex��ʼ
CP_Vertex::CP_Vertex( ): m_point(NULL)
{
} // ��CP_Vertex�Ĺ��캯������

CP_Vertex::CP_Vertex(CP_Point3D* p): m_point(p)
{
} // ��CP_Vertex�Ĺ��캯������

CP_Vertex::~CP_Vertex( )
{
    delete m_point;
} // ��CP_Vertex�������캯������

CP_Edge* CP_Vertex::mf_getAdjacentEdge(int index) const
{
    int n = (int)m_adjacentEdgeArray.GetSize( );
    if (index<0 || index>=n)
        return NULL;
	return (CP_Edge *)(m_adjacentEdgeArray[index]);
} // ��Ա����mf_getAdjacentEdge����

int CP_Vertex::mf_findAdjacentEdgeIndex(CP_Edge *edge) const
{
    int n = (int)m_adjacentEdgeArray.GetSize();
    for (int i=0; i<n; i++)
        if (m_adjacentEdgeArray[i] == edge)
            return i;
    return -1;
} // ��Ա����mf_findAdjacentEdgeIndex����

// ʵ����CP_Vertex����
// ////////////////////////////////////////////////////////////////////////////

