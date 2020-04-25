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
	, n_1(0)
	, n_2(0)
	, n_3(0)
	, n_4(0)
	, n_res(_T(""))
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
	DDX_Text(pDX, IDC_EDIT1, n_1);
	DDX_Text(pDX, IDC_EDIT3, n_2);
	DDX_Text(pDX, IDC_EDIT2, n_3);
	DDX_Text(pDX, IDC_EDIT4, n_4);
	DDX_Text(pDX, IDC_EDIT5, n_res);
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
	ON_BN_CLICKED(IDC_BUTTON1, &CBonus3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBonus3Dlg::OnBnClickedButton2)
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
	UpdateData(TRUE);
	int temp1 = m_b32things, temp2 = m_b3General;
	m_b32things = 0;
	m_b3General = 1;
	UpdateData(FALSE);
	if (temp1 == 0 && temp2 == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(1);
	}
	else if (temp1 == 1 && temp2 == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);
	}
	else if (temp1 == 0 && temp2 == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(5);
	}
	else if (temp1 == 1 && temp2 == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(6);
	}
	else                              //错误情况
		MessageBox("出现问题啦，请重新选择！");
}
void CBonus3Dlg::Calculator()
{
	UpdateData(TRUE);
	double t = 1.27 * 1.27 * 3.14;
	double num_a = n_1 / (n_2 * n_2 * t); //规格A的平均价格
	double num_b = n_3 / (n_4 * n_4 * t); //规格B的平均价格

	if (num_a < num_b)
	{
		n_res = "A的性价比更高!";
	}
	else
	{
		if (num_a == num_b)
		{
			n_res = "A和B的性价比相同!";
		}
		else
		{
			n_res = "B的性价比更高!";
		}
	}
	UpdateData(FALSE);
}

void CBonus3Dlg::OnBnClickedButton1() //计算键
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if ((n_1 != 0) & (n_2 != 0) & (n_3 != 0) & (n_4 != 0)) //避免输错
	{
		Calculator();
	}
	else
	{
		MessageBox("输错了哦，再来一次吧！");
	}
	UpdateData(FALSE);
}


void CBonus3Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	n_res = "";       //将结论显示框清空
	n_1 = 0;
	n_2 = 0;
	n_3 = 0;
	n_4 = 0;
	UpdateData(FALSE);
}
