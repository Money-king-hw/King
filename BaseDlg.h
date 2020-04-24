
// BaseDlg.h: 头文件
//

#pragma once

class CMoneyKingDlg;
class CBonusDlg;
class CAADlg;
class CShoppingDlg;
class CBonus2Dlg;
class CBonus3Dlg;
class CBonus4Dlg;

// CBaseDlg 对话框
class CBaseDlg : public CDialogEx
{
// 构造
public:
	CBaseDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BASE_DIALOG };
#endif
	enum
	{
		DLG_MONEYKING = 0, 
		DLG_BONUS, 
		DLG_AA,
		DLG_SHOPPING,
		DLG_BONUS2,
		DLG_BONUS3,
		DLG_BONUS4
	};

	CMoneyKingDlg* m_MoneyKing;
	CBonusDlg* m_Bonus;
	CAADlg* m_AA;
	CShoppingDlg* m_Shopping;
	CBonus2Dlg* m_Bonus2;
	CBonus3Dlg* m_Bonus3;
	CBonus4Dlg* m_Bonus4;

	void ShowPage(int CurrentPage);

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
