// AADlg.cpp: 实现文件
//

#include "pch.h"
#include "AADlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CAADlg 对话框

IMPLEMENT_DYNAMIC(CAADlg, CDialogEx)

CAADlg::CAADlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AA_DIALOG, pParent)
{

}

CAADlg::~CAADlg()
{
}

void CAADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAADlg, CDialogEx)
	ON_BN_CLICKED(IDC_AMENU_1, &CAADlg::OnBnClickedAmenu1)
	ON_BN_CLICKED(IDC_AMENU_2, &CAADlg::OnBnClickedAmenu2)
	ON_BN_CLICKED(IDC_AMENU_3, &CAADlg::OnBnClickedAmenu3)
	ON_BN_CLICKED(IDC_AMENU_4, &CAADlg::OnBnClickedAmenu4)
END_MESSAGE_MAP()


// CAADlg 消息处理程序


void CAADlg::OnBnClickedAmenu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CAADlg::OnBnClickedAmenu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CAADlg::OnBnClickedAmenu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CAADlg::OnBnClickedAmenu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}
