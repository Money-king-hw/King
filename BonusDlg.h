﻿#pragma once


// CBonusDlg 对话框

class CBonusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBonusDlg)

public:
	CBonusDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CBonusDlg();

	void Calculator();
	void SwitchPage();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BONUS_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBmenu1();
	afx_msg void OnBnClickedBmenu2();
	afx_msg void OnBnClickedButton1();
	double num_1;
	double num_2;
	double num_3;
	double num_4;
	CString n_str;
	afx_msg void OnBnClickedBmenu4();
	afx_msg void OnBnClickedBmenu3();
	int m_b2things;
	int m_bGeneral;
	afx_msg void OnBnClickedB2things();
	afx_msg void OnBnClickedB3things();
	afx_msg void OnBnClickedBgeneral();
	afx_msg void OnBnClickedBcun();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};
