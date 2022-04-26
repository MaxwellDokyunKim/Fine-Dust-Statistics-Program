// SubDlg1.cpp: 구현 파일
//

#include "pch.h"
#include "FineDust.h"
#include "SubDlg1.h"
#include "afxdialogex.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "City.h"
#include "framework.h"
#include "ChartCtrl_source_cord/ChartCtrl.h"
using namespace std;

Datas DT3;

// CSubDlg1 대화 상자

IMPLEMENT_DYNAMIC(CSubDlg1, CDialogEx)

CSubDlg1::CSubDlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYSUBDIALOG1, pParent)
	
	
	, m_GetCity(_T(""))
	
{

}

CSubDlg1::~CSubDlg1()
{
}

void CSubDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_FD25List1);
	DDX_Control(pDX, IDC_LIST2, m_FD25List2);
	//  DDX_Control(pDX, IDC_EDIT3, m_GetCity);
	//  DDX_Control(pDX, IDC_EDIT1, m_GetString2);


	DDX_Text(pDX, IDC_EDIT3, m_GetCity);
}


BEGIN_MESSAGE_MAP(CSubDlg1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSubDlg1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO2, &CSubDlg1::OnBnClickedRadio2)
END_MESSAGE_MAP()


// CSubDlg1 메시지 처리기


void CSubDlg1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_FD25List2.DeleteAllItems();
	m_FD25List2.DeleteColumn(100);


	m_FD25List2.InsertColumn(0, _T("측정유형"), LVCFMT_CENTER, 70);
	m_FD25List2.InsertColumn(1, _T("시.도별"), LVCFMT_CENTER, 70);
	m_FD25List2.InsertColumn(2, _T("시.군.구별(1)"), LVCFMT_CENTER, 100);
	m_FD25List2.InsertColumn(3, _T("시.군.구별(2)"), LVCFMT_CENTER, 100);
	m_FD25List2.InsertColumn(4, _T("2019.12"), LVCFMT_CENTER, 75);
	m_FD25List2.InsertColumn(5, _T("2020.01"), LVCFMT_CENTER, 75);
	m_FD25List2.InsertColumn(6, _T("2020.02"), LVCFMT_CENTER, 75);
	m_FD25List2.InsertColumn(7, _T("2020.03"), LVCFMT_CENTER, 75);
	m_FD25List2.InsertColumn(8, _T("2020.04"), LVCFMT_CENTER, 75);
	m_FD25List2.InsertColumn(9, _T("2020.05"), LVCFMT_CENTER, 75);

	m_FD25List2.SetExtendedStyle(m_FD25List2.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	int i = 0;

	string getcido;
	ifstream data;
	data.open("finedust2.5s.csv"); //input file stream 디스크 경로를 주면 읽어주는 것.

	string line;
	UpdateData(true);
	
	while (std::getline(data, line)) 
	{
		stringstream lineStream(line); 
		string cell;
		int num = 0;
		int j = 0;
		int count = m_FD25List2.GetItemCount();
		getcido = string(CT2CA(m_GetCity));
		size_t found = line.find(getcido);
		if (found != string::npos)
		{
			while (std::getline(lineStream, cell, ',')) 
			{
				if (j == 0)
				{
					DT3.EXData[i][j] = cell.c_str();
					m_FD25List2.InsertItem(count, DT3.EXData[i][j]);
				}
				else if (j > 0)
				{
					DT3.EXData[i][j] = cell.c_str();
					m_FD25List2.SetItem(count, j, LVIF_TEXT, DT3.EXData[i][j], 0, 0, 0, 0);
				}
				
				j++;
			}
			i++;

		}
	}
	
	UpdateData(false);
	data.close();
	

}


void CSubDlg1::OnBnClickedRadio2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
