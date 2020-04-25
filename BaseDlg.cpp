
// BaseDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Base.h"
#include "BaseDlg.h"
#include "afxdialogex.h"
#include "BonusDlg.h"
#include "MoneyKingDlg.h"
#include "AADlg.h"
#include "ShoppingDlg.h"
#include "Bonus2Dlg.h"
#include "Bonus3Dlg.h"
#include "Bonus4Dlg.h"
#include "AA2Dlg.h"
#include "AA3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBaseDlg 对话框



CBaseDlg::CBaseDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BASE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBaseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CBaseDlg 消息处理程序

BOOL CBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	m_MoneyKing = new CMoneyKingDlg;
	m_MoneyKing->Create(IDD_MONEYKING_DIALOG, this);
	m_MoneyKing->ShowWindow(SW_SHOW);
	CRect m_ShowRect;
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_MoneyKing->MoveWindow(m_ShowRect);

	m_Bonus = new CBonusDlg;
	m_Bonus->Create(IDD_BONUS_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_Bonus->MoveWindow(m_ShowRect);
	m_Bonus->ShowWindow(SW_HIDE);

	m_AA = new CAADlg;
	m_AA->Create(IDD_AA_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_AA->MoveWindow(m_ShowRect);
	m_AA->ShowWindow(SW_HIDE);

	m_Shopping = new CShoppingDlg;
	m_Shopping->Create(IDD_SHOPPING_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_Shopping->MoveWindow(m_ShowRect);
	m_Shopping->ShowWindow(SW_HIDE);

	m_Bonus2 = new CBonus2Dlg;
	m_Bonus2->Create(IDD_BONUS2_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_Bonus2->MoveWindow(m_ShowRect);
	m_Bonus2->ShowWindow(SW_HIDE);

	m_Bonus3 = new CBonus3Dlg;
	m_Bonus3->Create(IDD_BONUS3_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_Bonus3->MoveWindow(m_ShowRect);
	m_Bonus3->ShowWindow(SW_HIDE);

	m_Bonus4 = new CBonus4Dlg;
	m_Bonus4->Create(IDD_BONUS4_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_Bonus4->MoveWindow(m_ShowRect);
	m_Bonus4->ShowWindow(SW_HIDE);

	m_AA2 = new CAA2Dlg;
	m_AA2->Create(IDD_AA2_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_AA2->MoveWindow(m_ShowRect);
	m_AA2->ShowWindow(SW_HIDE);

	m_AA3 = new CAA3Dlg;
	m_AA3->Create(IDD_AA3_DIALOG, this);
	GetWindowRect(&m_ShowRect);
	m_ShowRect = CRect(0, 0, m_ShowRect.Width(), m_ShowRect.Height());
	m_AA3->MoveWindow(m_ShowRect);
	m_AA3->ShowWindow(SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBaseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBaseDlg::ShowPage(int CurrentPage)
{
	switch (CurrentPage)
	{
	case DLG_MONEYKING:
	{
		m_MoneyKing->ShowWindow(SW_SHOW);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_BONUS:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_SHOW);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_AA:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_SHOW);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_SHOPPING:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_SHOW);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_BONUS2:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_SHOW);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_BONUS3:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_SHOW);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_BONUS4:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_SHOW);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_AA2:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_SHOW);
		m_AA3->ShowWindow(SW_HIDE);
	}
	break;
	case DLG_AA3:
	{
		m_MoneyKing->ShowWindow(SW_HIDE);
		m_Bonus->ShowWindow(SW_HIDE);
		m_AA->ShowWindow(SW_HIDE);
		m_Shopping->ShowWindow(SW_HIDE);
		m_Bonus2->ShowWindow(SW_HIDE);
		m_Bonus3->ShowWindow(SW_HIDE);
		m_Bonus4->ShowWindow(SW_HIDE);
		m_AA2->ShowWindow(SW_HIDE);
		m_AA3->ShowWindow(SW_SHOW);
	}
	break;
	}
}

