// ShoppingDlg.cpp: 实现文件
//

#include "pch.h"
#include "ShoppingDlg.h"
#include "afxdialogex.h"
#include "BaseDlg.h"
#include "resource.h"
#include "string"
#include "iostream"

using namespace std;

// CShoppingDlg 对话框

IMPLEMENT_DYNAMIC(CShoppingDlg, CDialogEx)

CShoppingDlg::CShoppingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHOPPING_DIALOG, pParent)
	, num_1(0)
	, num_2(0)
	, num_3(0)
	, num_4(0)
	, num_5(0)
	, num_6(0)
	, num_7(0)
	, n_price(0)
	, n_result(0)
{

}

CShoppingDlg::~CShoppingDlg()
{

}

void CShoppingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT9, num_1);
	DDX_Text(pDX, IDC_EDIT2, num_2);
	DDX_Text(pDX, IDC_EDIT6, num_3);
	DDX_Text(pDX, IDC_EDIT7, num_4);
	DDX_Text(pDX, IDC_EDIT8, num_5);
	DDX_Text(pDX, IDC_EDIT11, num_6);
	DDX_Text(pDX, IDC_EDIT10, num_7);
	DDX_Text(pDX, IDC_EDIT12, n_price);
	DDX_Text(pDX, IDC_EDIT3, n_result);
}


BEGIN_MESSAGE_MAP(CShoppingDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SMENU_1, &CShoppingDlg::OnBnClickedSmenu1)
	ON_BN_CLICKED(IDC_SMENU_2, &CShoppingDlg::OnBnClickedSmenu2)
	ON_BN_CLICKED(IDC_SMENU_3, &CShoppingDlg::OnBnClickedSmenu3)
	ON_BN_CLICKED(IDC_SMENU_4, &CShoppingDlg::OnBnClickedSmenu4)
	ON_BN_CLICKED(IDC_BUTTON1, &CShoppingDlg::OnBnClickedButton1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CShoppingDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CShoppingDlg 消息处理程序


void CShoppingDlg::OnBnClickedSmenu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CShoppingDlg::OnBnClickedSmenu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CShoppingDlg::OnBnClickedSmenu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CShoppingDlg::OnBnClickedSmenu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}

void CShoppingDlg::Calculator()
{
	UpdateData(TRUE);
	double b;
	double c;
	double d;
	double a;

	if (num_1 != 0)
	{
		a = n_price * (1 - num_1 * 0.1);
	}
	else
	{
		a = 0;
	}
	if (num_2 > n_price)
	{
		b = n_price * (num_3 / num_2);
	}
	else
	{
		b = num_3;
	}
	if (num_4 > n_price)
	{
		c = n_price * (num_5 / num_4);
	}
	else
	{
		c = num_5;
	}
	if (num_6 > n_price)
	{
		d = n_price * (num_7 / num_6);
	}
	else
	{
		d = num_7;
	}
	n_result = round((n_price - a - b - c - d)*100)/100;
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);

	UpdateData(FALSE);
}

void CShoppingDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Calculator();
	if (n_price != 0) //对未输入价格或理想最优价为0时做出提示
	{
		if (n_result < 0)
		{
			MessageBox("请检查输入！");
		}
	}
	else
	{
		MessageBox("请输入价格！");
	}
	UpdateData(FALSE);

}



void CShoppingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CDC* pDC = &dc;
	CBitmap m_cBitmap;
	BITMAP  m_sBITMAP;
	BOOL m_isBmpLoaded = FALSE;
	CRect m_rect;
	if (!m_isBmpLoaded)
	{
		m_cBitmap.LoadBitmap(IDB_BITMAP1);
		m_cBitmap.GetBitmap(&m_sBITMAP);
		m_isBmpLoaded = TRUE;
	}
	GetClientRect(&m_rect);
	//clear DC
	pDC->Rectangle(0, 0, m_rect.right, m_rect.bottom);
	CDC* pMemDC = new CDC;
	pMemDC->CreateCompatibleDC(pDC);
	pMemDC->SelectObject(&m_cBitmap);
	pDC->BitBlt(0, 0, m_rect.right, m_rect.bottom, pMemDC, 0, 0, SRCCOPY);
	delete pMemDC;
}


HBRUSH CShoppingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	if (nCtlColor == CTLCOLOR_STATIC)  //静态文本
	{
		pDC->SetBkMode(TRANSPARENT);    //设置控件透明
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CShoppingDlg::OnBnClickedButton2()
{
	UpdateData(TRUE);
	n_result = 0;       //将结论显示框清空
	n_price = 0;
	num_1 = 0;
	num_2 = 0;
	num_3 = 0;
	num_4 = 0;
	num_5 = 0;
	num_6 = 0;
	num_7 = 0;
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}
