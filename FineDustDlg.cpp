
// FineDustDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FineDust.h"
#include "FineDustDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "City.h"
#include "SubDlg1.h"
#include "SubDlg2.h"
#include "cidoSubDlg1.h"
#include "ChartViewer.h"

#include "ChartCtrl_source_cord/ChartCtrl.h"
using namespace std;


int selectedIndex;
Datas DT;
Datas DT2;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFineDustDlg 대화 상자



CFineDustDlg::CFineDustDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINEDUST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFineDustDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MYSTATIC, m_MyStaticClick1);
	DDX_Control(pDX, IDC_LIST1, m_FDList1);
	DDX_Control(pDX, IDC_LIST2, m_FDList2);
	DDX_Control(pDX, IDC_PIC1, m_picture_control1);
	DDX_Control(pDX, IDC_MYSTATIC2, m_MyStaticClick2);
	DDX_Control(pDX, IDC_MYSTATIC3, m_MyStaticClick3);
	DDX_Control(pDX, IDC_MYSTATIC4, m_MyStaticClick4);
	DDX_Control(pDX, IDC_MYSTATIC5, m_MyStaticClick5);
	DDX_Control(pDX, IDC_MYSTATIC6, m_MyStaticClick6);
	DDX_Control(pDX, IDC_MYSTATIC7, m_MyStaticClick7);
	DDX_Control(pDX, IDC_MYSTATIC8, m_MyStaticClick8);
	DDX_Control(pDX, IDC_MYSTATIC9, m_MyStaticClick9);


	DDX_Control(pDX, IDC_MYGRAPH5, m_MyGraph3);

	DDX_Control(pDX, IDC_MYSYSLINK2, m_syslink2);
	DDX_Control(pDX, IDC_MYGRAPH6, m_MyGraph4);
}

BEGIN_MESSAGE_MAP(CFineDustDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_STN_CLICKED(IDC_MYSTATIC, &CFineDustDlg::OnStnClickedMystatic)
	ON_BN_CLICKED(IDC_BUTTON1, &CFineDustDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFineDustDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_MYSTATIC2, &CFineDustDlg::OnStnClickedMystatic2)
	ON_STN_CLICKED(IDC_MYSTATIC3, &CFineDustDlg::OnStnClickedMystatic3)
	ON_STN_CLICKED(IDC_MYSTATIC4, &CFineDustDlg::OnStnClickedMystatic4)
	ON_STN_CLICKED(IDC_MYSTATIC5, &CFineDustDlg::OnStnClickedMystatic5)
	ON_STN_CLICKED(IDC_MYSTATIC6, &CFineDustDlg::OnStnClickedMystatic6)
	ON_STN_CLICKED(IDC_MYSTATIC8, &CFineDustDlg::OnStnClickedMystatic8)
	ON_STN_CLICKED(IDC_MYSTATIC7, &CFineDustDlg::OnStnClickedMystatic7)
	ON_STN_CLICKED(IDC_MYSTATIC9, &CFineDustDlg::OnStnClickedMystatic9)

	ON_NOTIFY(NM_CLICK, IDC_MYSYSLINK2, &CFineDustDlg::OnNMClickMysyslink2)
	ON_STN_CLICKED(IDC_MYGRAPH6, &CFineDustDlg::OnStnClickedMygraph6)
	ON_STN_CLICKED(IDC_MYGRAPH5, &CFineDustDlg::OnStnClickedMygraph5)
END_MESSAGE_MAP()


// CFineDustDlg 메시지 처리기

BOOL CFineDustDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	m_FDList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	m_FDList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	m_FDList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	m_FDList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	m_FDList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	m_FDList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	m_FDList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	m_FDList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	m_FDList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	m_FDList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	m_FDList1.SetExtendedStyle(m_FDList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	m_FDList2.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	m_FDList2.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	m_FDList2.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	m_FDList2.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	m_FDList2.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	m_FDList2.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	m_FDList2.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	m_FDList2.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	m_FDList2.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	m_FDList2.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	m_FDList2.SetExtendedStyle(m_FDList2.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);



	int i = 0;
	int num = 0;
	ifstream data;
	data.open("finedust2.5s.csv");
	string line;
	UpdateData(true);

	while (std::getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = m_FDList1.GetItemCount();


		while (std::getline(lineStream, cell, ','))
		{
			if (j == 0)
			{
				DT.EXData[i][j] = cell.c_str();
				m_FDList1.InsertItem(count, DT.EXData[i][j]);
			}
			else if (j > 0)
			{
				DT.EXData[i][j] = cell.c_str();
				m_FDList1.SetItem(count, j, LVIF_TEXT, DT.EXData[i][j], 0, 0, 0, 0);
			}
			j++;
		}
		i++;
	}

	data.close();




	data.open("finedust10.csv");
	int m = 0;

	while (std::getline(data, line))
	{
		stringstream lineStream(line);
		string cell;
		int n = 0;
		int count = m_FDList2.GetItemCount();

		while (std::getline(lineStream, cell, ','))
		{
			if (n == 0)
			{
				DT2.EXData[m][n] = cell.c_str();
				m_FDList2.InsertItem(count, DT2.EXData[m][n]);
			}
			else if (n > 0)
			{
				DT2.EXData[m][n] = cell.c_str();
				m_FDList2.SetItem(count, n, LVIF_TEXT, DT2.EXData[m][n], 0, 0, 0, 0);
			}
			n++;
		}
		m++;
	}
	UpdateData(false);
	data.close();


	if (m_image.IsNull())
	{
		m_image.Load(L"koreamap.bmp");
		((CStatic*)GetDlgItem(IDC_PIC1))->SetBitmap(m_image);
	}

	//지도의 지명들에 마우스를 대면 커서가 손바닥 모양으로 바뀜
	HCURSOR hCursor;
	hCursor = AfxGetApp()->LoadStandardCursor(IDC_HAND);
	SetClassLong(m_MyStaticClick1.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick2.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick3.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick4.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick5.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick6.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick7.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick8.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	SetClassLong(m_MyStaticClick9.GetSafeHwnd(), GCL_HCURSOR, (LONG)hCursor);
	



	// The data for the bar chart
	double datamm[] = { 220, 300, 300, 280, 250, 210, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(280, 180);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("National Average(PM2.5)", "Arial Bold", 10, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(70, 60, 200, 80, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial", 8, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	m_MyGraph3.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;


	// The data for the bar chart
	double data3[] = { 0.020, 0.021, 0.0139, 0.0078, 0.019, 0.091,0.0133, 0.0233 ,0.011};
	const int data_size = (int)(sizeof(data3) / sizeof(*data3));

	// The labels for the bar chart
	const char* labels[] = { "Seo", "GG", "GW", "CB", "CN", "JB", "JN","PB","PN"};
	const int labels_size = (int)(sizeof(labels) / sizeof(*labels));

	// The colors for the bars
	int colors[] = { 0x5588bb, 0x66bbbb, 0xaa6644, 0x99bb55, 0xee9944, 0x444466, 0xbb5555 };
	const int colors_size = (int)(sizeof(colors) / sizeof(*colors));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c3 = new XYChart(280, 180);

	// Add a title box using grey (0x555555) 24pt Arial font
	c3->addTitle("Pb Density", "Arial", 10, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c3->setPlotArea(70, 60, 200, 80, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c3->xAxis()->setColors(Chart::Transparent);
	c3->yAxis()->setColors(Chart::Transparent);
	c3->xAxis()->setLabelStyle("Arial", 8);
	c3->yAxis()->setLabelStyle("Arial", 8);

	// Add a multi-color bar chart layer with transparent border using the given data
	c3->addBarLayer(DoubleArray(data3, data_size), IntArray(colors, colors_size))->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c3->xAxis()->setLabels(StringArray(labels, labels_size));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c3->yAxis()->setTickDensity(0.01);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial font
	c3->yAxis()->setTitle("", "Arial", 14, 0x555555);

	// Output the chart
	//c->makeChart("colorbar.png");
	m_MyGraph4.setChart(c3);
	//free up resources
	delete c3;








	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFineDustDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFineDustDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFineDustDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CFineDustDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.


	CSubDlg1* child = new CSubDlg1();

	child->Create(IDD_MYSUBDIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FD25List1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FD25List1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FD25List1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FD25List1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FD25List1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FD25List1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FD25List1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FD25List1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FD25List1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FD25List1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);


	child->m_FD25List1.SetExtendedStyle(child->m_FD25List1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	int i = 0;
	int num = 0;
	ifstream data;
	data.open("finedust2.5s.csv"); //input file stream 디스크 경로를 주면 읽어주는것.
	string line;
	UpdateData(true);

	while (std::getline(data, line)) // getline 함수.어느경로로부터 라인단위로 읽는다.읽을것이 없으면 false로 반환하는 함수.라인을 그대로 가져오는	것.
	{
		stringstream lineStream(line); //stringstream이라는 개체를 열건데 한 줄의 데이터를 라인스트림형태로 객체로 확보를 해놓고
		string cell;
		int j = 0;
		int count = child->m_FD25List1.GetItemCount();

		while (std::getline(lineStream, cell, ','))
		{
			if (j == 0)
			{
				DT.EXData[i][j] = cell.c_str();
				child->m_FD25List1.InsertItem(count, DT.EXData[i][j]);
			}
			else if (j > 0)
			{
				DT.EXData[i][j] = cell.c_str();
				child->m_FD25List1.SetItem(count, j, LVIF_TEXT, DT.EXData[i][j], 0, 0, 0, 0);
			}
			j++;
		}
		i++;
	}

	UpdateData(false);
	data.close();
}


void CFineDustDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSubDlg2* child = new CSubDlg2();

	child->Create(IDD_MYSUBDIALOG2, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FD10List1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FD10List1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FD10List1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FD10List1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FD10List1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FD10List1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FD10List1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FD10List1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FD10List1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FD10List1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);


	child->m_FD10List1.SetExtendedStyle(child->m_FD10List1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	int i = 0;
	int num = 0;
	ifstream data;
	data.open("finedust10.csv"); //input file stream 디스크 경로를 주면 읽어주는것.
	string line;
	UpdateData(true);

	while (std::getline(data, line)) // getline 함수.어느경로로부터 라인단위로 읽는다.읽을것이 없으면 false로 반환하는 함수.라인을 그대로 가져오는	것.
	{
		stringstream lineStream(line); //stringstream이라는 개체를 열건데 한 줄의 데이터를 라인스트림형태로 객체로 확보를 해놓고
		string cell;
		int j = 0;
		int count = child->m_FD10List1.GetItemCount();

		while (std::getline(lineStream, cell, ','))
		{
			if (j == 0)
			{
				DT.EXData[i][j] = cell.c_str();
				child->m_FD10List1.InsertItem(count, DT.EXData[i][j]);
			}
			else if (j > 0)
			{
				DT.EXData[i][j] = cell.c_str();
				child->m_FD10List1.SetItem(count, j, LVIF_TEXT, DT.EXData[i][j], 0, 0, 0, 0);
			}
			j++;
		}
		i++;
	}
	UpdateData(false);
	data.close();


}


void CFineDustDlg::OnStnClickedMystatic()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);
	
	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	double data0[] = { 30,30,28,25,21,20 };
	double data1[] = { 46,46,45,49,48,40 };
	
	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.
	
	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 220, 300, 300, 280, 250, 210, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;




	int i = 0;

	
	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "서울";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
		while (getline(data, line))
		{

			stringstream lineStream(line);
			string cell;
			int j = 0;
			int count = child->m_FDCidoList1.GetItemCount();
			size_t found = line.find(cidoname);
			if (found != string::npos)
			{
				while (std::getline(lineStream, cell, ','))
				{
					if (j == 0)
					{
						DT2.EXData[i][j] = cell.c_str();
						child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
					}
					else if (j > 0)
					{
						DT.EXData[i][j] = cell.c_str();
						child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
					}
					j++;
				}
				
			}
			i++;
			
		}
	
	UpdateData(false);
	data.close();
	
}


void CFineDustDlg::OnStnClickedMystatic2()
{
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	double data0[] = { 31,30,28,25,19,20 };
	double data1[] = { 48,49,45,49,47,40 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FineDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 300, 310, 280, 250, 250, 190, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;



	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "경기";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}
			
		}
		i++;
	}

	UpdateData(false);
	data.close();

}


void CFineDustDlg::OnStnClickedMystatic3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 30,30,28,25,21,20 };
	double data1[] = { 46,46,45,49,48,40 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 220, 300, 300, 280, 250, 210, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "강원";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();

}


void CFineDustDlg::OnStnClickedMystatic4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 37,38,34,28,23,23 };
	double data1[] = { 50,50,48,49,47,35 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 350, 370, 380, 300, 250, 190, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "충북";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}


void CFineDustDlg::OnStnClickedMystatic5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 30,41,42,34,24,29 };
	double data1[] = { 55,66,58,57,51,44 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 250, 300, 410, 420, 340, 240, 290 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "충남";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}


void CFineDustDlg::OnStnClickedMystatic6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 30,30,28,25,21,20 };
	double data1[] = { 46,46,45,49,48,40 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 220, 300, 300, 280, 250, 210, 200 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "전북";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}



void CFineDustDlg::OnStnClickedMystatic7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 20,29,23,20,20,19 };
	double data1[] = { 43,46,42,43,45,35 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 180, 200, 290, 230, 200, 200, 100 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;


	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "전남";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}



void CFineDustDlg::OnStnClickedMystatic8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 19,18,19,15,14,12 };
	double data1[] = { 41,40,43,46,50,46 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 190, 180, 180,190 , 150, 140, 120 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;
	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "경북";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}


void CFineDustDlg::OnStnClickedMystatic9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CcidoSubDlg1* child = new CcidoSubDlg1();


	child->Create(IDD_MYCIDODIALOG1, this);
	child->ShowWindow(SW_SHOW); // 창을 띄움

	child->m_FDCidoList1.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	child->m_FDCidoList1.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	child->m_FDCidoList1.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	child->m_FDCidoList1.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	child->m_FDCidoList1.SetExtendedStyle(child->m_FDCidoList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	double data0[] = { 22,20,21,14,13,16 };
	double data1[] = { 30,28,31,29,32,30 };

	const char* labels[] = { "19.12", "20.01", "20.03", "20.04", "20.05" };

	// Create a XYChart object of size 350 x 230 pixels
	XYChart* c = new XYChart(350, 230); //차트의 전체 크기를 정한다

	// Set the plotarea at (50, 30) and of size 250 x 150 pixels.
	c->setPlotArea(50, 30, 250, 150); //차트위 위치와 높이 넓이를 정한다.

	// Add a legend box at (55, 0) (top of the chart) using 8 pts Arial Font. Set
	// background and border to Transparent.
	c->addLegend(55, 0, false, "", 8)->setBackground(Chart::Transparent);

	// Add a title to the x axis
	c->xAxis()->setTitle("FinDust 2019.12 to 2020.05");

	// Add a title to the y axis
	c->yAxis()->setTitle("Density");

	// Set the labels on the x axis.
	c->xAxis()->setLabels(StringArray(labels, (int)(sizeof(labels) / sizeof(labels[0]))));

	// Display 1 out of 2 labels on the x-axis. Show minor ticks for remaining
	// labels.
	//c->xAxis()->setLabelStep(2, 1);

	// Add three area layers, each representing one data set. The areas are drawn in
	// semi-transparent colors.

	c->addAreaLayer(DoubleArray(data0, (int)(sizeof(data0) / sizeof(data0[0]))),
		0x80ff0000, "FineDust2.5pm", 3);
	c->addAreaLayer(DoubleArray(data1, (int)(sizeof(data1) / sizeof(data1[0]))),
		0x8000ff00, "FineDust10pm", 3);

	child->m_MyGraph1.setChart(c);  //m_chartView에 Chart를 보여주기 위한 코드
	//
	// 
	// 
	// The data for the bar chart
	double datamm[] = { 210, 220, 200, 210, 140, 130, 160 };
	const int data_size2 = (int)(sizeof(datamm) / sizeof(*datamm));

	// The labels for the bar chart
	const char* labels2[] = { "19.11", "19.12", "20.01", "20.02", "20.03", "20.04", "20.05" };
	const int labels_size2 = (int)(sizeof(labels2) / sizeof(*labels2));

	// Create a XYChart object of size 600 x 400 pixels
	XYChart* c2 = new XYChart(400, 230);

	// Add a title box using grey (0x555555) 24pt Arial Bold font
	c2->addTitle("Bar Graph FineDust", "Arial", 15, 0x555555);

	// Set the plotarea at (70, 60) and of size 500 x 300 pixels, with transparent background and
	// border and light grey (0xcccccc) horizontal grid lines
	c2->setPlotArea(100, 60, 250, 120, Chart::Transparent, -1, Chart::Transparent, 0xcccccc);

	// Set the x and y axis stems to transparent and the label font to 12pt Arial
	c2->xAxis()->setColors(Chart::Transparent);
	c2->yAxis()->setColors(Chart::Transparent);
	c2->xAxis()->setLabelStyle("Arial", 8);
	c2->yAxis()->setLabelStyle("Arial", 8);

	// Add a blue (0x6699bb) bar chart layer with transparent border using the given data
	c2->addBarLayer(DoubleArray(datamm, data_size2), 0x6699bb)->setBorderColor(Chart::Transparent);

	// Set the labels on the x axis.
	c2->xAxis()->setLabels(StringArray(labels2, labels_size2));

	// For the automatic y-axis labels, set the minimum spacing to 40 pixels.
	c2->yAxis()->setTickDensity(40);

	// Add a title to the y axis using dark grey (0x555555) 14pt Arial Bold font
	c2->yAxis()->setTitle("Monthly Variable ", "Arial Bold", 14, 0x555555);

	// Output the chart
	//c2->makeChart("simplebar2.png");

	child->m_MyGraph2.setChart(c2);  //m_chartView에 Chart를 보여주기 위한 코드

	//free up resources
	delete c2;
	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}

	int i = 0;


	ifstream data;
	data.open("finedust2.5s.csv");

	string line;
	string cidoname;
	cidoname = "경남";

	UpdateData(true);

	if (selectedIndex != 0)
	{
		for (int order = selectedIndex; order >= 0; order--)
		{
			child->m_FDCidoList1.DeleteItem(order);
		}
		selectedIndex = -1;
	}
	while (getline(data, line))
	{

		stringstream lineStream(line);
		string cell;
		int j = 0;
		int count = child->m_FDCidoList1.GetItemCount();
		size_t found = line.find(cidoname);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ','))
			{
				if (j == 0)
				{
					DT2.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.InsertItem(count, DT2.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT.EXData[i][j] = cell.c_str();
					child->m_FDCidoList1.SetItem(count, j, LVIF_TEXT, DT2.EXData[i][j], 0, 0, 0, 0);
				}
				j++;
			}

		}
		i++;
	}

	UpdateData(false);
	data.close();
}




void CFineDustDlg::OnNMClickMysyslink2(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString strUrl = L"";

	CLinkCtrl* pLinkCtrl = (CLinkCtrl*)GetDlgItem(IDC_MYSYSLINK2);  //CLinkCtrl는 링크컨트롤을 객체화한 클래스이다.

	pLinkCtrl->GetItemUrl(0, strUrl);          // GetItemUrl 로 0번째 인자를 strUrl 에 넣는다 (즉, www.naver.com 주소)



	::ShellExecute(NULL, L"open", strUrl, NULL, NULL, SW_SHOW);

	*pResult = 0;
}


void CFineDustDlg::OnStnClickedMygraph5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}



void CFineDustDlg::OnStnClickedMygraph6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}