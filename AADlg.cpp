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
	, m_a2people(0)
	, m_aPrice1(0)
	, m_aPrice2(0)
	, m_aPriceAll(0)
	, m_astr(_T(""))
{

}

CAADlg::~CAADlg()
{
}

void CAADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_A2PEOPLE, m_a2people);
	DDX_Text(pDX, IDC_APRICE1, m_aPrice1);
	DDX_Text(pDX, IDC_APRICE2, m_aPrice2);
	DDX_Text(pDX, IDC_APRCIE_ALL, m_aPriceAll);
	DDX_Text(pDX, IDC_AEDIT, m_astr);
}


BEGIN_MESSAGE_MAP(CAADlg, CDialogEx)
	ON_BN_CLICKED(IDC_AMENU_1, &CAADlg::OnBnClickedAmenu1)
	ON_BN_CLICKED(IDC_AMENU_2, &CAADlg::OnBnClickedAmenu2)
	ON_BN_CLICKED(IDC_AMENU_3, &CAADlg::OnBnClickedAmenu3)
	ON_BN_CLICKED(IDC_AMENU_4, &CAADlg::OnBnClickedAmenu4)
	ON_BN_CLICKED(IDC_ACALCULATE_BUTTON, &CAADlg::OnBnClickedAcalculateButton)
	ON_BN_CLICKED(IDC_ACLEAR_BUTTON, &CAADlg::OnBnClickedAclearButton)
	ON_BN_CLICKED(IDC_A2PEOPLE, &CAADlg::OnBnClickedA2people)
	ON_BN_CLICKED(IDC_A3PEOPLE, &CAADlg::OnBnClickedA3people)
	ON_BN_CLICKED(IDC_A4PEOPLE, &CAADlg::OnBnClickedA4people)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
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


void CAADlg::OnBnClickedAcalculateButton()		//计算按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double money1, money2, total_money;
	total_money = m_aPrice1 + m_aPrice2;
	if (total_money == 0.0f)	//两人购买总金额不能为零，否则提醒用户重新输入
	{
		MessageBox("请输入数据！");
	}
	else
	{
		money1 = m_aPrice1 * m_aPriceAll / total_money;
		money2 = m_aPrice2 * m_aPriceAll / total_money;
		m_astr.Format("用户1应支付%.2f\r\n用户2应支付%.2f", money1, money2);		//格式化输出结论
	}
	UpdateData(FALSE);
}


void CAADlg::OnBnClickedAclearButton()		//清零按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_astr = "";
	m_aPrice1 = 0;
	m_aPrice2 = 0;
	m_aPriceAll = 0;
	GetDlgItem(IDC_AEDIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_AEDIT)->ShowWindow(SW_SHOW);

	UpdateData(FALSE);
}


void CAADlg::OnBnClickedA2people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a2people = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAADlg::OnBnClickedA3people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a2people = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CAADlg::OnBnClickedA4people()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_a2people = 2;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CAADlg::SwitchPage()
{
	UpdateData(TRUE);
	int temp = m_a2people;
	m_a2people = 0;
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


void CAADlg::OnPaint()
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


HBRUSH CAADlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
