#pragma once


// CAADlg 对话框

class CAADlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAADlg)

public:
	CAADlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAADlg();

	void SwitchPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AA_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMenu1();
	afx_msg void OnBnClickedMenu2();
	afx_msg void OnBnClickedMenu3();
	afx_msg void OnBnClickedAmenu1();
	afx_msg void OnBnClickedAmenu2();
	afx_msg void OnBnClickedAmenu3();
	afx_msg void OnBnClickedAmenu4();
	int m_a2people;
	double m_aPrice1;
	double m_aPrice2;
	double m_aPriceAll;
	CString m_astr;
	afx_msg void OnBnClickedAcalculateButton();
	afx_msg void OnBnClickedAclearButton();
	afx_msg void OnBnClickedA2people();
	afx_msg void OnBnClickedA3people();
	afx_msg void OnBnClickedA4people();
};
