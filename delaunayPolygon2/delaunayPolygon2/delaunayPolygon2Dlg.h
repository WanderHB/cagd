
// delaunayPolygon2Dlg.h : ͷ�ļ�
//

#pragma once


// CdelaunayPolygon2Dlg �Ի���
class CdelaunayPolygon2Dlg : public CDialogEx
{
// ����
public:
	CdelaunayPolygon2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DELAUNAYPOLYGON2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOuterend();
	afx_msg void OnBnClickedInnerend();
	afx_msg void OnBnClickedPolygonok();
	afx_msg void OnBnClickedDelaunaybegin();
	afx_msg void OnBnClickedRedraw();
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
