#pragma once


// CAA2Dlg 对话框

class CAA2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAA2Dlg)

public:
	CAA2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAA2Dlg();

	void SwitchPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AA2_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_a22people;
	double m_a2price1;
	double m_a2price2;
	double m_a2price3;
	double m_a2PriceAll;
	CString m_a2str;
	int old;
	afx_msg void OnBnClickedA2menu1();
	afx_msg void OnBnClickedA2menu2();
	afx_msg void OnBnClickedA2menu3();
	afx_msg void OnBnClickedA2menu4();
	afx_msg void OnBnClickedA22people();
	afx_msg void OnBnClickedA23people();
	afx_msg void OnBnClickedA24people();
	afx_msg void OnBnClickedA2calculateButton();
	afx_msg void OnBnClickedA2clearButton();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
