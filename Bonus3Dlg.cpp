// Bonus3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "Bonus3Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CBonus3Dlg 对话框

IMPLEMENT_DYNAMIC(CBonus3Dlg, CDialogEx)

CBonus3Dlg::CBonus3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BONUS3_DIALOG, pParent)
	, m_b32things(0)
	, m_b3General(1)
{

}

CBonus3Dlg::~CBonus3Dlg()
{
}

void CBonus3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_B32THINGS, m_b32things);
	DDX_Radio(pDX, IDC_B3GENERAL, m_b3General);
}


BEGIN_MESSAGE_MAP(CBonus3Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_B3MENU_1, &CBonus3Dlg::OnBnClickedB3menu1)
	ON_BN_CLICKED(IDC_B3MENU_2, &CBonus3Dlg::OnBnClickedB3menu2)
	ON_BN_CLICKED(IDC_B3MENU_3, &CBonus3Dlg::OnBnClickedB3menu3)
	ON_BN_CLICKED(IDC_B3MENU_4, &CBonus3Dlg::OnBnClickedB3menu4)
	ON_BN_CLICKED(IDC_B32THINGS, &CBonus3Dlg::OnBnClickedB32things)
	ON_BN_CLICKED(IDC_B33THINGS, &CBonus3Dlg::OnBnClickedB33things)
	ON_BN_CLICKED(IDC_B3GENERAL, &CBonus3Dlg::OnBnClickedB3general)
	ON_BN_CLICKED(IDC_B3CUN, &CBonus3Dlg::OnBnClickedB3cun)
END_MESSAGE_MAP()


// CBonus3Dlg 消息处理程序


void CBonus3Dlg::OnBnClickedB3menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CBonus3Dlg::OnBnClickedB3menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CBonus3Dlg::OnBnClickedB3menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CBonus3Dlg::OnBnClickedB3menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}

void CBonus3Dlg::OnBnClickedB32things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b32things = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonus3Dlg::OnBnClickedB33things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b32things = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus3Dlg::OnBnClickedB3general()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b3General = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus3Dlg::OnBnClickedB3cun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b3General = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus3Dlg::SwitchPage()		//转换界面
{
	if (m_b32things == 0 && m_b3General == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(1);
	}
	else if (m_b32things == 1 && m_b3General == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);
	}
	else if (m_b32things == 0 && m_b3General == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(5);
	}
	else if (m_b32things == 1 && m_b3General == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(6);
	}
	else                              //错误情况
		MessageBox("出现问题啦，请重新选择！");
}
