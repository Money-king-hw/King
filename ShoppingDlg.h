#pragma once



// CShoppingDlg 对话框

class CShoppingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CShoppingDlg)

public:
	CShoppingDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CShoppingDlg();
	void Calculator();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHOPPING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSmenu1();
	afx_msg void OnBnClickedSmenu2();
	afx_msg void OnBnClickedSmenu3();
	afx_msg void OnBnClickedSmenu4();
	afx_msg void OnBnClickedButton1();
	double num_1;
	double num_3;
	double num_4;
	double num_5;
	double num_6;
	double num_2;
	double num_7;
	double n_price;
	double n_result;
};
