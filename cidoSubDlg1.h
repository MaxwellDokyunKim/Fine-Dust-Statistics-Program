#pragma once
#include "ChartViewer.h"
#include "ChartCtrl_source_cord/ChartCtrl.h"
#include "ChartCtrl_source_cord/ChartLineSerie.h"//라인차트 구조체
#include "ChartCtrl_source_cord/ChartCandlestickSerie.h"//봉차트 구조체


// CcidoSubDlg1 대화 상자

class CcidoSubDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CcidoSubDlg1)

public:
	CcidoSubDlg1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CcidoSubDlg1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYCIDODIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_FDCidoList1;
	CChartCtrl m_ChartCtrl;
	virtual BOOL InitInstance();
	CString m_sAppPath;

	void ReadData(SChartCandlestickPoint(&pCandlePoint)[600]);
	
	CChartViewer m_MyGraph1;
	CChartViewer m_MyGraph2;
};


