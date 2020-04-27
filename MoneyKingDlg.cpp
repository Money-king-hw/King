// MoneyKingDlg.cpp: 实现文件
//

#include "pch.h"
#include "Base.h"
#include "MoneyKingDlg.h"
#include "afxdialogex.h"
#include "BaseDlg.h"
#include <ctime>
#include <cstdlib>
#include <cmath>


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
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_EXP, &CMoneyKingDlg::OnBnClickedExp)
	ON_BN_CLICKED(IDC_EXP2, &CMoneyKingDlg::OnBnClickedExp2)
	ON_BN_CLICKED(IDC_LN, &CMoneyKingDlg::OnBnClickedLn)
	ON_BN_CLICKED(IDC_MOD, &CMoneyKingDlg::OnBnClickedMod)
	ON_BN_CLICKED(IDC_SQRT, &CMoneyKingDlg::OnBnClickedSqrt)
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
	if (m_str.GetLength() != m_istrle)		//如果最后一个字符为运算符，则清空运算符数据
	{
		m_iSign = -1;
		m_istrle = 0;
	}
	
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedClearButton()		//清零按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = "";			//将显示框清空
	m_istrle = 0;
	m_iSign = -1;
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedPercent()		//百分比按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_str.GetLength() != m_istrle)
	{
		CString strtemp;
		double temp;
		strtemp = m_str.Right(m_str.GetLength() - m_istrle);		//获得第二个操作数
		temp = atof(strtemp);
		temp = temp / 100;
		if (temp - int(temp) <= 1e-5)
		{
			strtemp.Format("%d", (int)temp);
		}
		else
		{
			strtemp.Format("%g", temp);  //double型的数据转为Cstring型,并去除多余的零
		}
		m_str = m_str.Left(m_istrle) + strtemp;
	}
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedAdd()		//加号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "+";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 0;		//加号标志，用于Calculator()函数中case的跳转判断
	}
}


void CMoneyKingDlg::OnBnClickedDec()		//减号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "-";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 1;		//减号标志，用于Calculator()函数中case的跳转判断
	}
}


void CMoneyKingDlg::OnBnClickedMultiply()		//乘号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "*";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 2;		//乘号标志，用于Calculator()函数中case的跳转判断
	}
}


void CMoneyKingDlg::OnBnClickedDivide()			//除号按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "/";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 3;		//除号标志，用于Calculator()函数中case的跳转判断
	}
}

void CMoneyKingDlg::OnBnClickedExp()		//幂次按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "^";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 4;		//幂次标志，用于Calculator()函数中case的跳转判断
	}
}


void CMoneyKingDlg::OnBnClickedMod()		//取余按钮
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_str.GetLength() != 0)		//当存在操作数时进行运算
	{
		if (m_str.GetLength() != m_istrle)		//最后一个符号不为运算符
		{
			if (m_iSign == 0 || m_iSign == 1 || m_iSign == 2 || m_iSign == 3 || m_iSign == 4 || m_iSign == 5)
				Calculator();		//如果此前已有计算符号，则计算出先前运算的答案
			SaveValue1();		//保存第一个数值
		}
		else			//如果最后一个符号为运算符，则替换运算符
		{
			UpdateData(TRUE);
			m_str = m_str.Left(m_str.GetLength() - 1);
			UpdateData(FALSE);
		}
		UpdateData(TRUE);
		m_str = m_str + "%";
		UpdateData(FALSE);
		m_istrle = strlen(m_str);    //求目前字符串的长度
		m_iSign = 5;		//取余标志，用于Calculator()函数中case的跳转判断
	}
}


void CMoneyKingDlg::OnBnClickedExp2()		//平方按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_str.GetLength() != m_istrle)
	{
		CString strtemp;
		double temp;
		strtemp = m_str.Right(m_str.GetLength() - m_istrle);		//获得第二个操作数
		temp = atof(strtemp);
		temp = temp * temp;		//平方运算
		if (temp - int(temp) <= 1e-5)
		{
			strtemp.Format("%d", (int)temp);
		}
		else
		{
			strtemp.Format("%g", temp);  //double型的数据转为Cstring型,并去除多余的零
		}
		m_str = m_str.Left(m_istrle) + strtemp;
	}
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedSqrt()		//平方根按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_str.GetLength() != m_istrle)
	{
		CString strtemp;
		double temp;
		strtemp = m_str.Right(m_str.GetLength() - m_istrle);		//获得第二个操作数
		temp = atof(strtemp);
		if (temp >= 0)		//正数开根，负数弹出提示
		{
			temp = sqrt(temp);		//开平方根
			if (temp - int(temp) <= 1e-5)
			{
				strtemp.Format("%d", (int)temp);
			}
			else
			{
				strtemp.Format("%g", temp);  //double型的数据转为Cstring型,并去除多余的零
			}
			m_str = m_str.Left(m_istrle) + strtemp;
		}
		else
		{
			MessageBox("负数不能开平方根！");
		}
	}
	UpdateData(FALSE);
}


void CMoneyKingDlg::OnBnClickedLn()			//自然对数按钮
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_str.GetLength() != m_istrle)
	{
		CString strtemp;
		double temp;
		strtemp = m_str.Right(m_str.GetLength() - m_istrle);		//获得第二个操作数
		temp = atof(strtemp);
		if (temp > 0)		//正数取对数，非正数弹出提示
		{
			temp = log(temp);
			if (temp - int(temp) <= 1e-5)
			{
				strtemp.Format("%d", (int)temp);
			}
			else
			{
				strtemp.Format("%g", temp);  //double型的数据转为Cstring型,并去除多余的零
			}
			m_str = m_str.Left(m_istrle) + strtemp;
		}
		else if (temp == 0)
		{
			MessageBox("零不能取自然对数！");
		}
		else
		{
			MessageBox("负数不能取自然对数！");
		}
	}
	UpdateData(FALSE);
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
	if (m_iSign != 0 && m_iSign != 1 && m_iSign != 2 && m_iSign != 3 && m_iSign != 4 && m_iSign != 5)
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
	if (m_str.GetLength() != m_istrle)
	{
		CString strtemp;
		strtemp = m_str.Right(m_str.GetLength() - m_istrle);		//获得第二个操作数
		if (-1 == strtemp.Find('.'))
		{
			m_str = m_str + ".";		//如果没有小数点，则加上一个小数点，如果已有小数点就忽略此次的小数点，保证最多只有1个
		}
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
	case 4:
		f = pow(m_fNumber1, m_fNumber2);//幂次
		break;
	case 5:
		f = fmod(m_fNumber1, m_fNumber2);//取余
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
	m_iSign = -1;		//清空计算符号
	m_istrle = 0;

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



BOOL CMoneyKingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetTimer(1, 50, NULL);

	srand((int)time(0));

	int i = rand() % 12;

	CString headstr = "每次多攒一点点，快乐生活每一天！\r\n今天的省钱小妙招是：\r\n\r\n";

	switch (i)
	{
	case 0:
	{
		MessageBox(headstr + "超市里同一款商品，最难拿到的生产日期越好", "省钱小妙招");
	}
	break;
	case 1:
	{
		MessageBox(headstr + "同一家商店在不同外卖平台的满减不一定相同", "省钱小妙招");
	}
	break;
	case 2:
	{
		MessageBox(headstr + "自用的商品少买礼盒装，普通包装更划算", "省钱小妙招");
	}
	break;
	case 3:
	{
		MessageBox(headstr + "饿了么外卖上的店铺满减、津贴、饭票和红包是可以同时使用的哦", "省钱小妙招");
	}
	break;
	case 4:
	{
		MessageBox(headstr + "晚上八点之后，超市的鲜食价格超低", "省钱小妙招");
	}
	break;
	case 5:
	{
		MessageBox(headstr + "揣着学生证，吃喝玩乐都能省", "省钱小妙招");
	}
	break;
	case 6:
	{
		MessageBox(headstr + "电影上映前两周，购票平台会有9.9的点映价", "省钱小妙招");
	}
	break;
	case 7:
	{
		MessageBox(headstr + "到店用餐可以提前看看网上有没有团购套餐，会更划算哦", "省钱小妙招");
	}
	break;
	case 8:
	{
		MessageBox(headstr + "海底捞两个半份的量比一份多，价钱却一样哦", "省钱小妙招");
	}
	break;
	case 9:
	{
		MessageBox(headstr + "保健品维生素比药品维生素含量低，价格贵，都是智商税", "省钱小妙招");
	}
	break;
	case 10:
	{
		MessageBox(headstr + "无硅油的洗发水除了贵点，没其他用处", "省钱小妙招");
	}
	break;
	case 11:
	{
		MessageBox(headstr + "牙膏含氟就行，其他再贵再花里胡哨的功能都没多大用", "省钱小妙招");
	}
	break;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CMoneyKingDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)
	{
	case 1:
	{
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(SW_SHOW);
		break;
	}
	}

	CDialogEx::OnTimer(nIDEvent);
}