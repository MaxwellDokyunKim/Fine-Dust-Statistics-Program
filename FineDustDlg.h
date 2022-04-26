
// FineDustDlg.h: 헤더 파일
//

#pragma once
#include "ChartViewer.h"
#include "ChartCtrl_source_cord/ChartCtrl.h"

// CFineDustDlg 대화 상자
class CFineDustDlg : public CDialogEx
{
// 생성입니다.
public:
	CFineDustDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINEDUST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_MyStaticClick1;
	CListCtrl m_FDList1;
	CListCtrl m_FDList2;
	afx_msg void OnStnClickedMystatic();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic m_picture_control1;
	CImage m_image;
	CStatic m_MyStaticClick2;
	afx_msg void OnStnClickedMystatic2();
	CStatic m_MyStaticClick3;
	CStatic m_MyStaticClick4;
	CStatic m_MyStaticClick5;
	afx_msg void OnStnClickedMystatic3();
	afx_msg void OnStnClickedMystatic4();
	afx_msg void OnStnClickedMystatic5();
	afx_msg void OnStnClickedMystatic6();
	CStatic m_MyStaticClick6;
	CStatic m_MyStaticClick7;
	afx_msg void OnStnClickedMystatic8();
	afx_msg void OnStnClickedMystatic7();
	afx_msg void OnStnClickedMystatic9();
	CStatic m_MyStaticClick8;
	CStatic m_MyStaticClick9;
	CStatic m_picture_control2;
	CImage m_image2;

	CChartViewer m_MyGraph3;
	afx_msg void OnNMClickSyslink1(NMHDR* pNMHDR, LRESULT* pResult);
	CLinkCtrl m_syslink;
	afx_msg void OnNMClickMysyslink2(NMHDR* pNMHDR, LRESULT* pResult);
	CLinkCtrl m_syslink2;
	CChartViewer m_MyGraph4;
	afx_msg void OnStnClickedMygraph6();
	afx_msg void OnStnClickedMygraph5();
};
