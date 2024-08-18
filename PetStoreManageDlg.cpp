
// PetStoreManageDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PetStoreManage.h"
#include "PetStoreManageDlg.h"
#include "afxdialogex.h"
#include "MainSys.h"
#include "User.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPetStoreManageDlg 对话框



CPetStoreManageDlg::CPetStoreManageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PETSTOREMANAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPetStoreManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPetStoreManageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPetStoreManageDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPetStoreManageDlg 消息处理程序

BOOL CPetStoreManageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPetStoreManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPetStoreManageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPetStoreManageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPetStoreManageDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Admin admin = Admin(_T("200572"), _T("123456"), _T("20110405"));
	Pet pet = Pet(_T("123"), _T("123"), _T("001"), _T("sunheng"), _T("dog"), _T("18"), _T("75"), _T("1200"), _T("cute"),
		_T("shanchuan"), _T("20240102"), _T("未出售"), _T("无"));
	//获取账号和密码
	CString acc,pwd;
	GetDlgItemText(IDC_EDIT1, acc);
	GetDlgItemText(IDC_EDIT2, pwd);
	//管理员登录成功，跳转到管理界面
	if (!acc.CompareNoCase(admin.account) && !pwd.CompareNoCase(admin.password))
	{
		MessageBox(admin.id+_T("管理员登录成功"),_T("登录成功"));
		MainSys mainSys;
		mainSys.DoModal();
	}
	//宠物登录，提示不可用
	else if (!acc.CompareNoCase(pet.account) && !pwd.CompareNoCase(pet.password))
	{
		MessageBox(_T("宠物账号不可用"), _T("登录失败"));
	}
	//账号密码错误
	else
	{
		MessageBox(_T("账号或密码错误"), _T("登录失败"));
	}


}
