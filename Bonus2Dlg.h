#pragma once


// CBonus2Dlg 对话框

class CBonus2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBonus2Dlg)

public:
	CBonus2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBonus2Dlg();

	void  SwitchPage();
	void Calculator();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BONUS2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_b22things;
	int m_b2General;
	afx_msg void OnBnClickedB22things();
	afx_msg void OnBnClickedB2menu1();
	afx_msg void OnBnClickedB2menu2();
	afx_msg void OnBnClickedB2menu3();
	afx_msg void OnBnClickedB2menu4();
	afx_msg void OnBnClickedB23things();
	afx_msg void OnBnClickedB2general();
	afx_msg void OnBnClickedB2cun();
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
