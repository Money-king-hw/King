// MoneyKingDlg.cpp: 实现文件
//

#include "pch.h"
#include "Base.h"
#include "MoneyKingDlg.h"
#include "afxdialogex.h"
#include "BaseDlg.h"


// CMoneyKingDlg 对话框

IMPLEMENT_DYNAMIC(CMoneyKingDlg, CDialogEx)

CMoneyKingDlg::CMoneyKingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MONEYKING_DIALOG, pParent)
	, m_str(_T(""))
{

}

CMoneyKingDlg::~CMoneyKingDlg()
{
}

void CMoneyKingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}


BEGIN_MESSAGE_MAP(CMoneyKingDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BACK_BUTTON, &CMoneyKingDlg::OnBnClickedBackButton)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CMoneyKingDlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_PERCENT, &CMoneyKingDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_ADD, &CMoneyKingDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CMoneyKingDlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_MULTIPLY, &CMoneyKingDlg::OnBnClickedMultiply)
	ON_BN_CLICKED(IDC_DIVIDE, &CMoneyKingDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_NUM_0, &CMoneyKingDlg::OnBnClickedNum0)
	ON_BN_CLICKED(IDC_NUM_1, &CMoneyKingDlg::OnBnClickedNum1)
	ON_BN_CLICKED(IDC_NUM_2, &CMoneyKingDlg::OnBnClickedNum2)
	ON_BN_CLICKED(IDC_NUM_3, &CMoneyKingDlg::OnBnClickedNum3)
	ON_BN_CLICKED(IDC_NUM_4, &CMoneyKingDlg::OnBnClickedNum4)
	ON_BN_CLICKED(IDC_NUM_5, &CMoneyKingDlg::OnBnClickedNum5)
	ON_BN_CLICKED(IDC_NUM_6, &CMoneyKingDlg::OnBnClickedNum6)
	ON_BN_CLICKED(IDC_NUM_7, &CMoneyKingDlg::OnBnClickedNum7)
	ON_BN_CLICKED(IDC_NUM_8, &CMoneyKingDlg::OnBnClickedNum8)
	ON_BN_CLICKED(IDC_NUM_9, &CMoneyKingDlg::OnBnClickedNum9)
	ON_BN_CLICKED(IDC_EQUAL, &CMoneyKingDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_DEMICAL, &CMoneyKingDlg::OnBnClickedDemical)
	ON_BN_CLICKED(IDC_MMENU_1, &CMoneyKingDlg::OnBnClickedMmenu1)
	ON_BN_CLICKED(IDC_MMENU_2, &CMoneyKingDlg::OnBnClickedMmenu2)
	ON_BN_CLICKED(IDC_MMENU_3, &CMoneyKingDlg::OnBnClickedMmenu3)
	ON_BN_CLICKED(IDC_MMENU_4, &CMoneyKingDlg::OnBnClickedMmenu4)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMoneyKingDlg 消息处理程序


void CMoneyKingDlg::OnBnClickedBackButton()			//后退按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (!m_str.IsEmpty())
	{
		m_str = m_str.Left(m_str.GetLength() - 1);		//移除最右边一个字符
	}
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedClearButton()		//清零按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = "";			//将显示框清空
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedPercent()		//百分比按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double temp;
	temp = atof(m_str);
	temp = temp / 100;
	if (temp - int(temp) <= 1e-5)
	{
		m_str.Format("%d", (int)temp);
	}
	else
	{
		m_str.Format("%g", temp);  //double型的数据转为Cstring型,并去除多余的零
	}
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedAdd()		//加号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue1();		//保存第一个数值并在按下操作符按钮后、第二个数值输出之前使编辑框空白
	UpdateData(TRUE);
	m_str = m_str + "+";
	UpdateData(FALSE);
	m_istrle = strlen(m_str);    //求目前字符串的长度
	m_iSign = 0;		//加号标志，用于Calculator()函数中case的跳转判断
}


void CMoneyKingDlg::OnBnClickedDec()		//减号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue1();
	UpdateData(TRUE);
	m_str = m_str + "-";
	UpdateData(FALSE);
	m_istrle = strlen(m_str);    //求目前字符串的长度
	m_iSign = 1;		//减号标志，用于Calculator()函数中case的跳转判断
}


void CMoneyKingDlg::OnBnClickedMultiply()		//乘号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue1();
	UpdateData(TRUE);
	m_str = m_str + "*";
	UpdateData(FALSE);
	m_istrle = strlen(m_str);    //求目前字符串的长度
	m_iSign = 2;		//乘号标志，用于Calculator()函数中case的跳转判断
}


void CMoneyKingDlg::OnBnClickedDivide()			//除号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue1();
	UpdateData(TRUE);
	m_str = m_str + "/";
	UpdateData(FALSE);
	m_istrle = strlen(m_str);    //求目前字符串的长度
	m_iSign = 3;		//除号标志，用于Calculator()函数中case的跳转判断
}


void CMoneyKingDlg::OnBnClickedNum0()		//数字0按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "0";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum1()		//数字1按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "1";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum2()		//数字2按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "2";
	UpdateData(FALSE);
}

void CMoneyKingDlg::OnBnClickedNum3()		//数字3按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "3";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum4()		//数字4按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "4";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum5()		//数字5按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "5";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum6()		//数字6按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "6";
	UpdateData(FALSE);
}

void CMoneyKingDlg::OnBnClickedNum7()		//数字7按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "7";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedNum8()		//数字8按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "8";
	UpdateData(FALSE);
}

void CMoneyKingDlg::OnBnClickedNum9()		//数字9按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + "9";
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedEqual()		//等号按钮，当按下该按钮时执行计算
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_iSign != 0 && m_iSign != 1 && m_iSign != 2 && m_iSign != 3)
	{
		m_fNumber1 = atof(m_str);		//当单击输入某一个数值而没有单击操作符按钮、直接单击“=”时，界面上保持显示第一个操作数
	}
	else
		Calculator();
	UpdateData(FALSE);
}

void CMoneyKingDlg::OnBnClickedDemical()		//小数点按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (-1 == m_str.Find('.'))
	{
		m_str = m_str + ".";		//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个
	}
	UpdateData(FALSE);
}

void CMoneyKingDlg::SaveValue1()	//用于保存第一个操作数
{
	UpdateData(TRUE);
	m_fNumber1 = atof(m_str);		//保存第一个操作数
	UpdateData(FALSE);
}

void CMoneyKingDlg::Calculator()	//计算，涉及到两个操作数，按下“=”时执行
{
	UpdateData(TRUE);
	m_fNumber2 = atof(m_str.Right(m_str.GetLength() - m_istrle));      //获得第二个操作数
	double f = 0.0f;		//f必须初始化，用于保留计算结果
	switch (m_iSign)		//根据m_iSign标志跳转
	{
	case 0:
		f = m_fNumber1 + m_fNumber2;	//加
		break;
	case 1:
		f = m_fNumber1 - m_fNumber2;	//减
		break;
	case 2:
		f = m_fNumber1 * m_fNumber2;	//乘
		break;
	case 3:
		if (m_fNumber2 == 0.0f)			//除法中分母不能为0，为0时需要进行如下操作
		{
			MessageBox("除数不能为0!"); //弹出提示消息框
			f = m_fNumber1;				//除数为0时直接将第一个操作数赋给结果，表示第二个操作数不算，直接继续下一步操作
		}
		else
		{
			f = m_fNumber1 / m_fNumber2;//除
		}
		break;
	default:
		break;
	}
	//计算结果处理
	//如果浮点数其实是个整数
	if (abs(f - int(f)) <= 1e-5)
	{
		m_str.Format("%d", (int)f);
	}
	else
	{
		m_str.Format("%g", f);  //double型的数据转为Cstring型，并去除多余的零
	}
	UpdateData(FALSE);
}



void CMoneyKingDlg::OnBnClickedMmenu1()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(0);			//跳到基础计算器对话框
}


void CMoneyKingDlg::OnBnClickedMmenu2()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(1);			//跳到单价比较对话框
}


void CMoneyKingDlg::OnBnClickedMmenu3()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(2);			//跳到AA制对话框
}


void CMoneyKingDlg::OnBnClickedMmenu4()
{
	// TODO: 在此添加控件通知处理程序代码
	CBaseDlg* pMMD = (CBaseDlg*)AfxGetMainWnd();
	pMMD->ShowPage(3);			//跳到购物最优价对话框
}


void CMoneyKingDlg::OnPaint()
{
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CPaintDC dc(this); // device context for painting
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


HBRUSH CMoneyKingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
