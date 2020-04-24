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
}


BEGIN_MESSAGE_MAP(CBonusDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BMENU_1, &CBonusDlg::OnBnClickedBmenu1)
	ON_BN_CLICKED(IDC_BMENU_2, &CBonusDlg::OnBnClickedBmenu2)
	ON_BN_CLICKED(IDC_BUTTON1, &CBonusDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON1, &CBonusDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BMENU_4, &CBonusDlg::OnBnClickedBmenu4)
	ON_BN_CLICKED(IDC_BMENU_3, &CBonusDlg::OnBnClickedBmenu3)
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
	pMMD->ShowPage(2);			//跳到单价比较对话框
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

void CBonusDlg::OnBnClickedButton2() //清零键
{
	UpdateData(TRUE);
	n_str = "";       //将结论显示框清空
	to_string(num_1) = "";
	to_string(num_2) = "";
	to_string(num_3) = "";
	to_string(num_4) = "";
	UpdateData(FALSE);
}

void CBonusDlg::Calculator()
{
	UpdateData(TRUE);
	double num_a = num_2 / num_1; //规格A的平均价格
	double num_b = num_4 / num_3; //规格B的平均价格

	if (num_a <= num_b)
	{
		n_str = "A的性价比更高!";
	}
	else
	{
		n_str = "B的性价比更高!";
	}
	UpdateData(FALSE);
}