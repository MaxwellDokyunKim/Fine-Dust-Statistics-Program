#pragma once


// CSubDlg2 대화 상자

class CSubDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg2)

public:
	CSubDlg2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSubDlg2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYSUBDIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_FD10List1;
	CListCtrl m_FD10List2;
	CString m_Getstr;
	afx_msg void OnBnClickedButton1();
};
