#pragma once
#include "ChartCtrl_source_cord/ChartCtrl.h"

// CSubDlg1 대화 상자

class CSubDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg1)

public:
	CSubDlg1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSubDlg1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYSUBDIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_FD25List1;
	CListCtrl m_FD25List2;
//	CString m_GetCity;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio2();
//	CString m_GetString;
//	CString m_GetString2;

	CString m_GetCity;
};
