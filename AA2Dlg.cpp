// AA2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "AA2Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CAA2Dlg 对话框

IMPLEMENT_DYNAMIC(CAA2Dlg, CDialogEx)

CAA2Dlg::CAA2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AA2_DIALOG, pParent)
	, m_a22people(1)
	, m_a2price1(0)
	, m_a2price2(0)
	, m_a2price3(0)
	, m_a2PriceAll(0)
	, m_a2str(_T(""))
{

}

CAA2Dlg::~CAA2Dlg()
{
}

void CAA2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_A22PEOPLE, m_a22people);
	DDX_Text(pDX, IDC_A2PRICE1, m_a2price1);
	DDX_Text(pDX, IDC_A2PRICE2, m_a2price2);
	DDX_Text(pDX, IDC_A2PRICE3, m_a2price3);
	DDX_Text(pDX, IDC_A2PRCIE_ALL, m_a2PriceAll);
	DDX_Text(pDX, IDC_A2EDIT, m_a2str);
}


BEGIN_MESSAGE_MAP(CAA2Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_A2MENU_1, &CAA2Dlg::OnBnClickedA2menu1)
	ON_BN_CLICKED(IDC_A2MENU_2, &CAA2Dlg::OnBnClickedA2menu2)
	ON_BN_CLICKED(IDC_A2MENU_3, &CAA2Dlg::OnBnClickedA2menu3)
	ON_BN_CLICKED(IDC_A2MENU_4, &CAA2Dlg::OnBnClickedA2menu4)
	ON_BN_CLICKED(IDC_A22PEOPLE, &CAA2Dlg::OnBnClickedA22people)
	ON_BN_CLICKED(IDC_A23PEOPLE, &CAA2Dlg::OnBnClickedA23people)
	ON_BN_CLICKED(IDC_A24PEOPLE, &CAA2Dlg::OnBnClickedA24people)
	ON_BN_CLICKED(IDC_A2CALCULATE_BUTTON, &CAA2Dlg::OnBnClickedA2calculateButton)
	ON_BN_CLICKED(IDC_A2CLEAR_BUTTON, &CAA2Dlg::OnBnClickedA2clearButton)
END_MESSAGE_MAP()


// CAA2Dlg 消息处理程序


void CAA2Dlg::OnBnClickedA2menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CAA2Dlg::OnBnClickedA2menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CAA2Dlg::OnBnClickedA2menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CAA2Dlg::OnBnClickedA2menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CAA2Dlg::OnBnClickedA22people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a22people = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAA2Dlg::OnBnClickedA23people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a22people = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAA2Dlg::OnBnClickedA24people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a22people = 2;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CAA2Dlg::SwitchPage()
{
	UpdateData(TRUE);
	int temp = m_a22people;
	m_a22people = 1;
	UpdateData(FALSE);
	if (temp == 0)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(2);
	}
	else if (temp == 1)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(7);
	}
	else if (temp == 2)
	{
		CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
		pMMD->ShowPage(8);
	}
	else                              //错误情况
		MessageBox("出现问题啦，请重新选择！");
}


void CAA2Dlg::OnBnClickedA2calculateButton()		//计算按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double money1, money2, money3, total_money;
	total_money = m_a2price1 + m_a2price2 + m_a2price3;
	if (total_money == 0.0f)	//购买总金额不能为零，否则提醒用户重新输入
	{
		MessageBox("请输入数据！");
	}
	else
	{
		money1 = m_a2price1 * m_a2PriceAll / total_money;
		money2 = m_a2price2 * m_a2PriceAll / total_money;
		money3 = m_a2price3 * m_a2PriceAll / total_money;
		m_a2str.Format("用户1应支付%.2f\r\n用户2应支付%.2f\r\n用户3应支付%.2f", money1, money2, money3);		//格式化输出结论
	}
	UpdateData(FALSE);
}


void CAA2Dlg::OnBnClickedA2clearButton()		//清零按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a2str = "";
	m_a2price1 = 0;
	m_a2price2 = 0;
	m_a2price3 = 0;
	m_a2PriceAll = 0;
	UpdateData(FALSE);
}
