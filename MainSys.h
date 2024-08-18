#pragma once
#include "afxdialogex.h"


// MainSys 对话框

class MainSys : public CDialogEx
{
	DECLARE_DYNAMIC(MainSys)

public:
	MainSys(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MainSys();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_id;
	CString m_name;
	CString m_age;
	CString m_weight;
	CString m_type;
	CString m_value;
	CString m_character;
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CString m_onwer;
	CString m_date;
	CString m_state;
	CString M_customer;
};
