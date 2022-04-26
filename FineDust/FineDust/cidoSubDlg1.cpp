// cidoSubDlg1.cpp: 구현 파일
//

#include "pch.h"
#include "FineDust.h"
#include "cidoSubDlg1.h"
#include "afxdialogex.h"
#include "ChartCtrl_source_cord/ChartCtrl.h"
#include "ChartCtrl_source_cord/ChartLineSerie.h"//라인차트 구조체
#include "ChartCtrl_source_cord/ChartCandlestickSerie.h"//봉차트 구조체

// CcidoSubDlg1 대화 상자

IMPLEMENT_DYNAMIC(CcidoSubDlg1, CDialogEx)

CcidoSubDlg1::CcidoSubDlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYCIDODIALOG1, pParent)
{
	m_sAppPath = _T("");
}

CcidoSubDlg1::~CcidoSubDlg1()
{
}


void CcidoSubDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_FDCidoList1);

	DDX_Control(pDX, IDC_MYGRAPH1, m_MyGraph1);
	DDX_Control(pDX, IDC_MYGRAPH2, m_MyGraph2);
}

BOOL CcidoSubDlg1::InitInstance()
{
	

	return 0;
	
}


BEGIN_MESSAGE_MAP(CcidoSubDlg1, CDialogEx)
END_MESSAGE_MAP()


// CcidoSubDlg1 메시지 처리기

