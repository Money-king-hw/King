// Bonus2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "Bonus2Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CBonus2Dlg 对话框

IMPLEMENT_DYNAMIC(CBonus2Dlg, CDialogEx)

CBonus2Dlg::CBonus2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BONUS2_DIALOG, pParent)
	, m_b22things(1)
	, m_b2General(0)
	, n_1(0)
	, n_2(0)
	, n_3(0)
	, n_4(0)
	, n_5(0)
	, n_6(0)
	, n_res(_T(""))
{

}

CBonus2Dlg::~CBonus2Dlg()
{
}

void CBonus2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_B22THINGS, m_b22things);
	DDX_Radio(pDX, IDC_B2GENERAL, m_b2General);
	DDX_Text(pDX, IDC_EDIT1, n_1);
	DDX_Text(pDX, IDC_EDIT3, n_2);
	DDX_Text(pDX, IDC_EDIT2, n_3);
	DDX_Text(pDX, IDC_EDIT5, n_4);
	DDX_Text(pDX, IDC_EDIT13, n_5);
	DDX_Text(pDX, IDC_EDIT14, n_6);
	DDX_Text(pDX, IDC_EDIT4, n_res);
}


BEGIN_MESSAGE_MAP(CBonus2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_B22THINGS, &CBonus2Dlg::OnBnClickedB22things)
	ON_BN_CLICKED(IDC_B2MENU_1, &CBonus2Dlg::OnBnClickedB2menu1)
	ON_BN_CLICKED(IDC_B2MENU_2, &CBonus2Dlg::OnBnClickedB2menu2)
	ON_BN_CLICKED(IDC_B2MENU_3, &CBonus2Dlg::OnBnClickedB2menu3)
	ON_BN_CLICKED(IDC_B2MENU_4, &CBonus2Dlg::OnBnClickedB2menu4)
	ON_BN_CLICKED(IDC_B23THINGS, &CBonus2Dlg::OnBnClickedB23things)
	ON_BN_CLICKED(IDC_B2GENERAL, &CBonus2Dlg::OnBnClickedB2general)
	ON_BN_CLICKED(IDC_B2CUN, &CBonus2Dlg::OnBnClickedB2cun)
	ON_BN_CLICKED(IDC_BUTTON1, &CBonus2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBonus2Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CBonus2Dlg 消息处理程序


void CBonus2Dlg::OnBnClickedB2menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CBonus2Dlg::OnBnClickedB2menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CBonus2Dlg::OnBnClickedB2menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CBonus2Dlg::OnBnClickedB2menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CBonus2Dlg::OnBnClickedB22things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b22things = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonus2Dlg::OnBnClickedB23things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b22things = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus2Dlg::OnBnClickedB2general()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b2General = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus2Dlg::OnBnClickedB2cun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b2General = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonus2Dlg::SwitchPage()		//转换界面
{
	UpdateData(TRUE);
	int temp1 = m_b22things, temp2 = m_b2General;
	m_b22things = 1;
	m_b2General = 0;
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

void CBonus2Dlg::Calculator()
{
	UpdateData(TRUE);
	double num_a = n_1 / n_2; //规格A的平均价格
	double num_b = n_3 / n_4; //规格B的平均价格
	double num_c = n_5 / n_6; //规格C的平均价格

	if ((num_a <= num_b) & (num_a <= num_c))
	{
		n_res = "A的性价比最高!";
	}
	else
	{
		if ((num_b <= num_a) & (num_b <= num_c))
		{
			n_res = "B的性价比最高!";
		}
		else
		{
			n_res = "C的性价比最高!";
		}
	}
	UpdateData(FALSE);
}

void CBonus2Dlg::OnBnClickedButton1() //计算键
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if ((n_1 != 0) & (n_2 != 0) & (n_3 != 0) & (n_4 != 0) & (n_5 != 0) & (n_6 != 0)) //避免输错
	{
		Calculator();
	}
	else
	{
		MessageBox("输错了哦，再来一次吧！");
	}
	UpdateData(FALSE);
}


void CBonus2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	n_res = "";       //将结论显示框清空
	n_1 = 0;
	n_2 = 0;
	n_3 = 0;
	n_4 = 0;
	n_5 = 0;
	n_6 = 0;
	UpdateData(FALSE);
}
