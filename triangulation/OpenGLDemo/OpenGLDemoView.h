
// OpenGLDemoView.h : COpenGLDemoView ��Ľӿ�
//

#pragma once


class COpenGLDemoView : public CView
{
protected: // �������л�����
	COpenGLDemoView();
	DECLARE_DYNCREATE(COpenGLDemoView)

// ����
public:
	COpenGLDemoDoc* GetDocument() const;

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
	virtual ~COpenGLDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
	// OpenGL��Ⱦ���(a handle to an OpenGL rendering context)
	HGLRC m_hRC;

    CButton m_button_OuterEnd;
    CButton m_button_InnerEnd;
    CButton m_button_PolygonOK;
    CButton m_button_Begin;
    CButton m_button_Redraw;

public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

    afx_msg void OnBtnClickOuterEnd();
    afx_msg void OnBtnClickRedraw();
    afx_msg void OnBtnClickBegin();
    afx_msg void OnBtnClickPolygonOK();
    afx_msg void OnBtnClickInnerEnd();


    afx_msg void OnTrianglesfilled();
    afx_msg void OnHowtouse();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileSave();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // OpenGLDemoView.cpp �еĵ��԰汾
inline COpenGLDemoDoc* COpenGLDemoView::GetDocument() const
   { return reinterpret_cast<COpenGLDemoDoc*>(m_pDocument); }
#endif

