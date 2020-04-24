// BonusDlg.cpp: 实现文件
//

#include "pch.h"
#include "Base.h"
#include "BonusDlg.h"
#include "afxdialogex.h"
#include "BaseDlg.h"
#include "resource.h"
#include "string"
#include "iostream"

using namespace std;


// CBonusDlg 对话框

IMPLEMENT_DYNAMIC(CBonusDlg, CDialogEx)

CBonusDlg::CBonusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BONUS_DIALOG, pParent)
	, num_1(0)
	, num_2(0)
	, num_3(0)
	, num_4(0)
	, n_str(_T(""))
	, m_b2things(0)
	, m_bGeneral(0)
{

}

CBonusDlg::~CBonusDlg()
{
}

void CBonusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, num_1);
	DDX_Text(pDX, IDC_EDIT3, num_2);
	DDX_Text(pDX, IDC_EDIT2, num_3);
	DDX_Text(pDX, IDC_EDIT4, num_4);
	DDX_Text(pDX, IDC_EDIT5, n_str);
	DDX_Radio(pDX, IDC_B2THINGS, m_b2things);
	DDX_Radio(pDX, IDC_BGENERAL, m_bGeneral);
}


BEGIN_MESSAGE_MAP(CBonusDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BMENU_1, &CBonusDlg::OnBnClickedBmenu1)
	ON_BN_CLICKED(IDC_BMENU_2, &CBonusDlg::OnBnClickedBmenu2)
	ON_BN_CLICKED(IDC_BUTTON1, &CBonusDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BMENU_4, &CBonusDlg::OnBnClickedBmenu4)
	ON_BN_CLICKED(IDC_BMENU_3, &CBonusDlg::OnBnClickedBmenu3)
	ON_BN_CLICKED(IDC_B2THINGS, &CBonusDlg::OnBnClickedB2things)
	ON_BN_CLICKED(IDC_B3THINGS, &CBonusDlg::OnBnClickedB3things)
	ON_BN_CLICKED(IDC_BGENERAL, &CBonusDlg::OnBnClickedBgeneral)
	ON_BN_CLICKED(IDC_BCUN, &CBonusDlg::OnBnClickedBcun)
	ON_BN_CLICKED(IDC_BUTTON2, &CBonusDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

// CBonusDlg 消息处理程序


void CBonusDlg::OnBnClickedBmenu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CBonusDlg::OnBnClickedBmenu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CBonusDlg::OnBnClickedBmenu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CBonusDlg::OnBnClickedBmenu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}

void CBonusDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if ((num_1 != 0) & (num_2 != 0) & (num_3 != 0) & (num_4 != 0)) //避免输错
	{
		Calculator();
	}
	else
	{
		MessageBox("输错了哦，再来一次吧！");
	}
	UpdateData(FALSE);
}

void CBonusDlg::Calculator()
{
	UpdateData(TRUE);
	double num_a = num_1 / num_2; //规格A的平均价格
	double num_b = num_3 / num_4; //规格B的平均价格

	if (num_a < num_b)
	{
		n_str = "A的性价比更高!";
	}
	else
	{
		if (num_a == num_b)
		{
			n_str = "A和B的性价比相同!";
		}
		else 
		{
			n_str = "B的性价比更高!";
		}
	}
	UpdateData(FALSE);
}

void CBonusDlg::OnBnClickedB2things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b2things = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonusDlg::OnBnClickedB3things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b2things = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonusDlg::OnBnClickedBgeneral()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_bGeneral = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonusDlg::OnBnClickedBcun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_bGeneral = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonusDlg::SwitchPage()		//转换界面
{
	if (m_b2things == 0 && m_bGeneral == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(1);
	}
	else if (m_b2things == 1 && m_bGeneral == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(4);
	}
	else if (m_b2things == 0 && m_bGeneral == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(5);
	}
	else if (m_b2things == 1 && m_bGeneral == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(6);
	}
	else                              //错误情况
		MessageBox("出现问题啦，请重新选择！");
}


void CBonusDlg::OnBnClickedButton2()  //清零键
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	n_str = "";       //将结论显示框清空
	num_1 = 0;
	num_2 = 0;
	num_3 = 0;
	num_4 = 0;
	UpdateData(FALSE);
}
