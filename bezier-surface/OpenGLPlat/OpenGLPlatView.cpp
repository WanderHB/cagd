
// OpenGLPlatView.cpp : COpenGLPlatView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "OpenGLPlat.h"
#endif

#include "OpenGLPlatDoc.h"
#include "OpenGLPlatView.h"
#include <gl/GL.h>
#include <gl/GLU.h>

// Import lib
#pragma comment(lib, "OpenGL32.Lib")
#pragma comment(lib, "GlU32.Lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpenGLPlatView

IMPLEMENT_DYNCREATE(COpenGLPlatView, CView)

BEGIN_MESSAGE_MAP(COpenGLPlatView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COpenGLPlatView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// COpenGLPlatView ����/����

COpenGLPlatView::COpenGLPlatView()
{
	// TODO: �ڴ˴���ӹ������
	m_rX = 0;
	m_rY = 0;
}

COpenGLPlatView::~COpenGLPlatView()
{
}

BOOL COpenGLPlatView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// COpenGLPlatView ����

void COpenGLPlatView::OnDraw(CDC* pDC)
{
	COpenGLPlatDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

    // TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
    // ////////////////////////////////////////////////////////////////
    // New codes begin:
	// OpenGL part
    wglMakeCurrent(pDC->m_hDC, m_hRC);

    glClearColor(1,1,1,1);
	glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	// Set material attribute
	GLfloat material_ambient  [ ] = { 0.2f, 0.2f, 0.2f, 0.2f };
	GLfloat material_diffuse  [ ] = { 0.2f, 0.8f, 0.4f, 0.8f };
	GLfloat material_specular [ ] = { 0.2f, 0.8f, 0.4f, 0.8f };
	GLfloat material_emission [ ] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat material_shininess[ ] = { 20.0f };
	glMaterialfv(GL_FRONT, GL_AMBIENT,  material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,  material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, material_emission);
	glMaterialfv(GL_FRONT, GL_SHININESS,material_shininess);
	
	// Set light attribute
	GLfloat light_position [ ] = { 1.0f, 1.0f, 1.0f, 0.0f };
	GLfloat light_ambient  [ ] = { 0.2f, 0.2f, 0.2f, 0.2f };
	GLfloat light_diffuse  [ ] = { 0.5f, 0.5f, 0.5f, 0.2f };
	GLfloat light_specular [ ] = { 0.5f, 0.5f, 0.5f, 0.2f };
	glLightfv(GL_LIGHT0, GL_POSITION,  light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT,   light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,   light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR,  light_specular);

	// Turn on some functions
	glEnable (GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_AUTO_NORMAL);
	glEnable (GL_NORMALIZE);	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

    glLoadIdentity();

	// Draw bezier surface when segment is 40
	m_bezier.m_segmentNumU = 40;
	m_bezier.m_segmentNumV = 40; 

	// Draw solid
	glTranslated(-3, 1, 0);
	glRotated(30, 0.0, 1.0, 0.0);
	glRotated(-70, 1.0, 0.0, 0.0);
	m_bezier.mf_drawSolid();
	m_bezier.mf_drawControlPoints();

	// Draw wire frame
	glLoadIdentity();
	glTranslated(3, 1, 0);
	glRotated(30, 0.0, 1.0, 0.0);
	glRotated(-70, 1.0, 0.0, 0.0);
	m_bezier.mf_drawWireframe();

	// Draw bezier surface when segment is 5
	m_bezier.m_segmentNumU = 5;
	m_bezier.m_segmentNumV = 5; 

	// Draw solid
	glLoadIdentity();
	glTranslated(-3, -3, 0);
	glRotated(30, 0.0, 1.0, 0.0);
	glRotated(-70, 1.0, 0.0, 0.0);
	m_bezier.mf_drawSolid();
	m_bezier.mf_drawControlPoints();

	// Draw wire frame
	glLoadIdentity();
	glTranslated(3, -3, 0);
	glRotated(30, 0.0, 1.0, 0.0);
	glRotated(-70, 1.0, 0.0, 0.0);
	m_bezier.mf_drawWireframe();

    SwapBuffers(pDC->m_hDC);
    wglMakeCurrent(NULL, NULL);

	// Write string
	CRect rect;
	GetClientRect(&rect);
	pDC->TextOutW(rect.Width()/2 - 400, rect.Height()/2 - 100, L"n = 40");
	pDC->TextOutW(rect.Width()/2 - 400, rect.Height()/2 + 100, L"n = 5");
}


// COpenGLPlatView ��ӡ


void COpenGLPlatView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COpenGLPlatView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void COpenGLPlatView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void COpenGLPlatView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void COpenGLPlatView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COpenGLPlatView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COpenGLPlatView ���

#ifdef _DEBUG
void COpenGLPlatView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLPlatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenGLPlatDoc* COpenGLPlatView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenGLPlatDoc)));
	return (COpenGLPlatDoc*)m_pDocument;
}
#endif //_DEBUG


// COpenGLPlatView ��Ϣ�������


int COpenGLPlatView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	
	// The PIXELFORMATDESCRIPTOR structure describes
	//		the pixel format of a drawing surface.
	PIXELFORMATDESCRIPTOR pfd =
	{ 
		sizeof(PIXELFORMATDESCRIPTOR),  //  size of this pfd 
		1,                     			// version number 
		PFD_DRAW_TO_WINDOW |   	// support window 
		PFD_SUPPORT_OPENGL |   	// support OpenGL 
        	PFD_DOUBLEBUFFER,	// double buffered
		PFD_TYPE_RGBA,
		24,                    	// 24-bit color depth 
		0, 0, 0, 0, 0, 0,      // color bits ignored 
		0,                     	// no alpha buffer 
		0,                     	// shift bit ignored 
		0,                     	// no accumulation buffer 
		0, 0, 0, 0,            	// accum bits ignored 
		32,                    	// 32-bit z-buffer (depth)
		0,                     	// no stencil buffer 
		0,                     	// no auxiliary buffer 
		PFD_MAIN_PLANE,        // main layer 
		0,                     	// reserved 
		0, 0, 0                	// layer masks ignored 
    }; 

	CClientDC dc(this);
	int pixelFormat = ChoosePixelFormat(dc.m_hDC, &pfd);

	if (!SetPixelFormat(dc.m_hDC, pixelFormat, &pfd))
	{
		MessageBox(_T("Error: Unable to Set Pixel Format in CGLTemplate1View::OnCreate( )"),
			_T("Application Error"), MB_ICONERROR);
	}
	m_hRC = wglCreateContext(dc.m_hDC);

	return 0;
}

void COpenGLPlatView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	// Set : a specified OpenGL rendering context ==> NULL
	// Set : current rendering context ==> NULL
    wglMakeCurrent(NULL, NULL);

	// Delete the handle to an OpenGL rendering context 
    wglDeleteContext(m_hRC);
    m_hRC=NULL;

}


void COpenGLPlatView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������	
	CClientDC dc(this);
	wglMakeCurrent(dc.m_hDC, m_hRC);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	double d=10;
	double n=100;

	glOrtho(-cx/n, cx/n, -cy/n, cy/n, -d, d);

	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, cx, cy);
	
	wglMakeCurrent(NULL, NULL);
}


BOOL COpenGLPlatView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	// return CView::OnEraseBkgnd(pDC);
	return TRUE;
}


void COpenGLPlatView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	switch(nChar)
	{
	case VK_LEFT:
		m_rY = (m_rY + 10) % 360;
		break;
	case VK_RIGHT:
		m_rY = (m_rY - 10) % 360;
		break;
	case VK_UP:
		m_rX = (m_rX - 10) % 360;
		break;
	case VK_DOWN:
		m_rX = (m_rX + 10) % 360;
		break;
	}
	this->Invalidate();
}

void COpenGLPlatView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/* CP_Point2D newPoint;
	CRect rect;
	GetClientRect(&rect);
	newPoint.m_x = (point.x - rect.Width()/2.0) / 50;
	newPoint.m_y = (rect.Height()/2.0 - point.y) / 50;
	m_bezier.mf_pushCtrlPoints(newPoint);

	CView::OnLButtonUp(nFlags, point);
	this->Invalidate(true); */
}
