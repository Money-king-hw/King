#pragma once


// CAA3Dlg 对话框

class CAA3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAA3Dlg)

public:
	CAA3Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAA3Dlg();

	void SwitchPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AA3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_a32people;
	double m_a3price1;
	double m_a3price2;
	double m_a3price3;
	double m_a3price4;
	double m_a3PriceAll;
	CString m_a3str;
	afx_msg void OnBnClickedA3menu1();
	afx_msg void OnBnClickedA3menu2();
	afx_msg void OnBnClickedA3menu3();
	afx_msg void OnBnClickedA3menu4();
	afx_msg void OnBnClickedA32people();
	afx_msg void OnBnClickedA33people();
	afx_msg void OnBnClickedA34people();
	afx_msg void OnBnClickedA3calculateButton();
	afx_msg void OnBnClickedA3clearButton();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
