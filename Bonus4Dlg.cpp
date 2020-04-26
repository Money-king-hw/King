// Bonus4Dlg.cpp: 实现文件
//

#include "pch.h"
#include "Bonus4Dlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "BaseDlg.h"


// CBonus4Dlg 对话框

IMPLEMENT_DYNAMIC(CBonus4Dlg, CDialogEx)

CBonus4Dlg::CBonus4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BONUS4_DIALOG, pParent)
	, m_b42things(1)
	, m_b4General(1)
	, n_1(0)
	, n_2(0)
	, n_3(0)
	, n_4(0)
	, n_5(0)
	, n_6(0)
	, n_res(_T(""))
{

}

CBonus4Dlg::~CBonus4Dlg()
{
}

void CBonus4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_B42THINGS, m_b42things);
	DDX_Radio(pDX, IDC_B4GENERAL, m_b4General);
	DDX_Text(pDX, IDC_EDIT1, n_1);
	DDX_Text(pDX, IDC_EDIT3, n_2);
	DDX_Text(pDX, IDC_EDIT2, n_3);
	DDX_Text(pDX, IDC_EDIT5, n_4);
	DDX_Text(pDX, IDC_EDIT13, n_5);
	DDX_Text(pDX, IDC_EDIT14, n_6);
	DDX_Text(pDX, IDC_EDIT4, n_res);
}


BEGIN_MESSAGE_MAP(CBonus4Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_B4MENU_1, &CBonus4Dlg::OnBnClickedB4menu1)
	ON_BN_CLICKED(IDC_B4MENU_2, &CBonus4Dlg::OnBnClickedB4menu2)
	ON_BN_CLICKED(IDC_B4MENU_3, &CBonus4Dlg::OnBnClickedB4menu3)
	ON_BN_CLICKED(IDC_B4MENU_4, &CBonus4Dlg::OnBnClickedB4menu4)
	ON_BN_CLICKED(IDC_B42THINGS, &CBonus4Dlg::OnBnClickedB42things)
	ON_BN_CLICKED(IDC_B43THINGS, &CBonus4Dlg::OnBnClickedB43things)
	ON_BN_CLICKED(IDC_B4GENERAL, &CBonus4Dlg::OnBnClickedB4general)
	ON_BN_CLICKED(IDC_B4CUN, &CBonus4Dlg::OnBnClickedB4cun)
	ON_BN_CLICKED(IDC_BUTTON1, &CBonus4Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBonus4Dlg::OnBnClickedButton2)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CBonus4Dlg 消息处理程序


void CBonus4Dlg::OnBnClickedB4menu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CBonus4Dlg::OnBnClickedB4menu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CBonus4Dlg::OnBnClickedB4menu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CBonus4Dlg::OnBnClickedB4menu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CBonus4Dlg::OnBnClickedB42things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b42things = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB43things()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b42things = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB4general()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b4General = 0;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}


void CBonus4Dlg::OnBnClickedB4cun()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_b4General = 1;
	UpdateData(FALSE);
	SwitchPage();		//转换至对应界面
}

void CBonus4Dlg::SwitchPage()		//转换界面
{
	UpdateData(TRUE);
	int temp1 = m_b42things, temp2 = m_b4General;
	m_b42things = 1;
	m_b4General = 1;
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

void CBonus4Dlg::Calculator()
{
	UpdateData(TRUE);
	double t = 1.27 * 1.27 * 3.14;
	double num_a = n_1 / (n_2 * n_2 * t); //规格A的平均价格
	double num_b = n_3 / (n_4 * n_4 * t); //规格B的平均价格
	double num_c = n_5 / (n_6 * n_6 * t); //规格C的平均价格

	if (((num_a < num_b) & (num_b <= num_c)) || ((num_a < num_c) & (num_c <= num_b)))
	{
		n_res = "A的性价比最高!";
	}
	else if (((num_b < num_a) & (num_a <= num_c)) || ((num_b < num_c) & (num_c <= num_b)))
	{
		n_res = "B的性价比最高!";
	}
	else if (((num_c < num_a) & (num_a <= num_b)) || ((num_c < num_b) & (num_b <= num_a)))
	{
		n_res = "C的性价比最高!";
	}
	else if ((num_c == num_a) & (num_a < num_b))
	{
		n_res = "A和C的性价比都是最高的!";
	}
	else if ((num_b == num_a) & (num_a < num_c))
	{
		n_res = "A和B的性价比都是最高的!";
	}
	else if ((num_c == num_b) & (num_c < num_a))
	{
		n_res = "B和C的性价比都是最高的!";
	}
	else if (num_c == num_b == num_a)
	{
		n_res = "A、B、C的性价比相同!";
	}
	UpdateData(FALSE);
}

void CBonus4Dlg::OnBnClickedButton1()
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


void CBonus4Dlg::OnBnClickedButton2()
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
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}


void CBonus4Dlg::OnPaint()
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


HBRUSH CBonus4Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
