// Bonus4Dlg.cpp: 实现文件
//

#include "pch.h"
#include "Bonus4Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CBonus4Dlg 对话框

IMPLEMENT_DYNAMIC(CBonus4Dlg, CDialogEx)

CBonus4Dlg::CBonus4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BONUS4_DIALOG, pParent)
	, m_b42things(1)
	, m_b4General(1)
{

}

CBonus4Dlg::~CBonus4Dlg()
{
}

void CBonus4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_B42THINGS, m_b42things);
	DDX_Radio(pDX, IDC_B4GENERAL, m_b4General);
}


BEGIN_MESSAGE_MAP(CBonus4Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_B4MENU_1, &CBonus4Dlg::OnBnClickedB4menu1)
	ON_BN_CLICKED(IDC_B4MENU_2, &CBonus4Dlg::OnBnClickedB4menu2)
	ON_BN_CLICKED(IDC_B4MENU_3, &CBonus4Dlg::OnBnClickedB4menu3)
	ON_BN_CLICKED(IDC_B4MENU_4, &CBonus4Dlg::OnBnClickedB4menu4)
	ON_BN_CLICKED(IDC_B42THINGS, &CBonus4Dlg::OnBnClickedB42things)
	ON_BN_CLICKED(IDC_B43THINGS, &CBonus4Dlg::OnBnClickedB43things)
	ON_BN_CLICKED(IDC_B4GENERAL, &CBonus4Dlg::OnBnClickedB4general)
	ON_BN_CLICKED(IDC_B4CUN, &CBonus4Dlg::OnBnClickedB4cun)
END_MESSAGE_MAP()


// CBonus4Dlg 消息处理程序


void CBonus4Dlg::OnBnClickedB4menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CBonus4Dlg::OnBnClickedB4menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CBonus4Dlg::OnBnClickedB4menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CBonus4Dlg::OnBnClickedB4menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CBonus4Dlg::OnBnClickedB42things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b42things = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB43things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b42things = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB4general()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b4General = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB4cun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b4General = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonus4Dlg::SwitchPage()		//转换界面
{
	if (m_b42things == 0 && m_b4General == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(1);
	}
	else if (m_b42things == 1 && m_b4General == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);
	}
	else if (m_b42things == 0 && m_b4General == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(5);
	}
	else if (m_b42things == 1 && m_b4General == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(6);
	}
	else                              //错误情况
		MessageBox("出现问题啦，请重新选择！");
}
