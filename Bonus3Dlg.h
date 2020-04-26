#pragma once


// CBonus3Dlg 对话框

class CBonus3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBonus3Dlg)

public:
	CBonus3Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBonus3Dlg();

	void SwitchPage();
	void Calculator();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BONUS3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedB3menu1();
	afx_msg void OnBnClickedB3menu2();
	afx_msg void OnBnClickedB3menu3();
	afx_msg void OnBnClickedB3menu4();
	afx_msg void OnBnClickedB32things();
	int m_b32things;
	int m_b3General;
	afx_msg void OnBnClickedB33things();
	afx_msg void OnBnClickedB3general();
	afx_msg void OnBnClickedB3cun();
	double n_1;
	double n_2;
	double n_3;
	double n_4;
	CString n_res;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
