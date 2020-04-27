#pragma once


// CMoneyKingDlg 对话框

class CMoneyKingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMoneyKingDlg)

public:
	CMoneyKingDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMoneyKingDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONEYKING_DIALOG };
#endif

	//输入的两个值
	double m_fNumber1;
	double m_fNumber2;

	//保存计算符号,0='+',1='-',2='*',3='/',4='^',5='mod'
	int m_iSign;

	//计算
	void SaveValue1();
	void Calculator();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edit;
	CString m_str;
	int m_istrle;

	afx_msg void OnBnClickedBackButton();
	afx_msg void OnBnClickedClearButton();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDec();
	afx_msg void OnBnClickedMultiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedNum0();
	afx_msg void OnBnClickedNum1();
	afx_msg void OnBnClickedNum2();
	afx_msg void OnBnClickedNum3();
	afx_msg void OnBnClickedNum4();
	afx_msg void OnBnClickedNum5();
	afx_msg void OnBnClickedNum6();
	afx_msg void OnBnClickedNum7();
	afx_msg void OnBnClickedNum8();
	afx_msg void OnBnClickedNum9();
	afx_msg void OnBnClickedEqual();
	afx_msg void OnBnClickedDemical();
	afx_msg void OnBnClickedMmenu1();
	afx_msg void OnBnClickedMmenu2();
	afx_msg void OnBnClickedMmenu3();
	afx_msg void OnBnClickedMmenu4();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedExp();
	afx_msg void OnBnClickedExp2();
	afx_msg void OnBnClickedLn();
	afx_msg void OnBnClickedMod();
	afx_msg void OnBnClickedSqrt();
};
