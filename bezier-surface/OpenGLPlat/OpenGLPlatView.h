
// OpenGLPlatView.h : COpenGLPlatView ��Ľӿ�
//

#pragma once
#include "CP_Surface3D.h"

class COpenGLPlatView : public CView
{
protected: // �������л�����
	COpenGLPlatView();
	DECLARE_DYNCREATE(COpenGLPlatView)

// ����
public:
	COpenGLPlatDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~COpenGLPlatView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	// OpenGl��Ⱦ���(a handle to an OpenGL rendering context)
	HGLRC m_hRC;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

private:
	int m_rX;
	int m_rY;
	CP_Bezier3D m_bezier;
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // OpenGLPlatView.cpp �еĵ��԰汾
inline COpenGLPlatDoc* COpenGLPlatView::GetDocument() const
   { return reinterpret_cast<COpenGLPlatDoc*>(m_pDocument); }
#endif

