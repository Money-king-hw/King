#pragma once


// CBonus4Dlg 对话框

class CBonus4Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBonus4Dlg)

public:
	CBonus4Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBonus4Dlg();

	void SwitchPage();
	void Calculator();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BONUS4_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedB4menu1();
	afx_msg void OnBnClickedB4menu2();
	afx_msg void OnBnClickedB4menu3();
	afx_msg void OnBnClickedB4menu4();
	int m_b42things;
	int m_b4General;
	afx_msg void OnBnClickedB42things();
	afx_msg void OnBnClickedB43things();
	afx_msg void OnBnClickedB4general();
	afx_msg void OnBnClickedB4cun();
	double n_1;
	double n_2;
	double n_3;
	double n_4;
	double n_5;
	double n_6;
	CString n_res;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
