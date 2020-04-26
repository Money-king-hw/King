// AA3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "AA3Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CAA3Dlg 对话框

IMPLEMENT_DYNAMIC(CAA3Dlg, CDialogEx)

CAA3Dlg::CAA3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AA3_DIALOG, pParent)
	, m_a32people(2)
	, m_a3price1(0)
	, m_a3price2(0)
	, m_a3price3(0)
	, m_a3price4(0)
	, m_a3PriceAll(0)
	, m_a3str(_T(""))
{

}

CAA3Dlg::~CAA3Dlg()
{
}

void CAA3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_A32PEOPLE, m_a32people);
	DDX_Text(pDX, IDC_A3PRICE1, m_a3price1);
	DDX_Text(pDX, IDC_A3PRICE2, m_a3price2);
	DDX_Text(pDX, IDC_A3PRICE3, m_a3price3);
	DDX_Text(pDX, IDC_A3PRICE4, m_a3price4);
	DDX_Text(pDX, IDC_A3PRCIE_ALL, m_a3PriceAll);
	DDX_Text(pDX, IDC_A3EDIT, m_a3str);
}


BEGIN_MESSAGE_MAP(CAA3Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_A3MENU_1, &CAA3Dlg::OnBnClickedA3menu1)
	ON_BN_CLICKED(IDC_A3MENU_2, &CAA3Dlg::OnBnClickedA3menu2)
	ON_BN_CLICKED(IDC_A3MENU_3, &CAA3Dlg::OnBnClickedA3menu3)
	ON_BN_CLICKED(IDC_A3MENU_4, &CAA3Dlg::OnBnClickedA3menu4)
	ON_BN_CLICKED(IDC_A32PEOPLE, &CAA3Dlg::OnBnClickedA32people)
	ON_BN_CLICKED(IDC_A33PEOPLE, &CAA3Dlg::OnBnClickedA33people)
	ON_BN_CLICKED(IDC_A34PEOPLE, &CAA3Dlg::OnBnClickedA34people)
	ON_BN_CLICKED(IDC_A3CALCULATE_BUTTON, &CAA3Dlg::OnBnClickedA3calculateButton)
	ON_BN_CLICKED(IDC_A3CLEAR_BUTTON, &CAA3Dlg::OnBnClickedA3clearButton)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CAA3Dlg 消息处理程序


void CAA3Dlg::OnBnClickedA3menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CAA3Dlg::OnBnClickedA3menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CAA3Dlg::OnBnClickedA3menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CAA3Dlg::OnBnClickedA3menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CAA3Dlg::OnBnClickedA32people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a32people = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAA3Dlg::OnBnClickedA33people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a32people = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAA3Dlg::OnBnClickedA34people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a32people = 2;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAA3Dlg::SwitchPage()
{
	UpdateData(TRUE);
	int temp = m_a32people;
	m_a32people = 2;
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

void CAA3Dlg::OnBnClickedA3calculateButton()		//计算按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double money1, money2, money3, money4, total_money;
	total_money = m_a3price1 + m_a3price2 + m_a3price3 + m_a3price4;
	if (total_money == 0.0f)	//购买总金额不能为零，否则提醒用户重新输入
	{
		MessageBox("请输入数据！");
	}
	else
	{
		money1 = m_a3price1 * m_a3PriceAll / total_money;
		money2 = m_a3price2 * m_a3PriceAll / total_money;
		money3 = m_a3price3 * m_a3PriceAll / total_money;
		money4 = m_a3price4 * m_a3PriceAll / total_money;
		m_a3str.Format("用户1应支付%.2f\r\n用户2应支付%.2f\r\n用户3应支付%.2f\r\n用户4应支付%.2f"
			, money1, money2, money3, money4);		//格式化输出结论
	}
	UpdateData(FALSE);
}


void CAA3Dlg::OnBnClickedA3clearButton()		//清零按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a3str = "";
	m_a3price1 = 0;
	m_a3price2 = 0;
	m_a3price3 = 0;
	m_a3price4 = 0;
	m_a3PriceAll = 0;
	UpdateData(FALSE);
}


void CAA3Dlg::OnPaint()
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


HBRUSH CAA3Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
