// MainSys.cpp: 实现文件
//

#include "pch.h"
#include "PetStoreManage.h"
#include "afxdialogex.h"
#include "MainSys.h"
#include "User.h"

// MainSys 对话框

IMPLEMENT_DYNAMIC(MainSys, CDialogEx)

MainSys::MainSys(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_id(_T(""))
	, m_name(_T(""))
	, m_age(_T(""))
	, m_weight(_T(""))
	, m_type(_T(""))
	, m_value(_T(""))
	, m_character(_T(""))
	, m_onwer(_T(""))
	, m_date(_T(""))
	, m_state(_T(""))
	, M_customer(_T(""))
{

}

MainSys::~MainSys()
{
}

void MainSys::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_age);
	DDX_Text(pDX, IDC_EDIT4, m_weight);
	DDX_Text(pDX, IDC_EDIT5, m_type);
	DDX_Text(pDX, IDC_EDIT6, m_value);
	DDX_Text(pDX, IDC_EDIT7, m_character);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT8, m_onwer);
	DDX_Text(pDX, IDC_EDIT9, m_date);
	DDX_Text(pDX, IDC_EDIT10, m_state);
	DDX_Text(pDX, IDC_EDIT11, M_customer);
}


BEGIN_MESSAGE_MAP(MainSys, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainSys::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainSys::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MainSys::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MainSys::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MainSys::OnBnClickedButton5)
END_MESSAGE_MAP()


// MainSys 消息处理程序


BOOL MainSys::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//插入表头
	//样式设置为整行选择，网格线
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("编号"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(1, _T("名字"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(2, _T("年龄"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(3, _T("体重"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(4, _T("种类"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(5, _T("价格"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(6, _T("性格"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(7, _T("主人"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(8, _T("交易日期"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(9, _T("状态"), LVCFMT_LEFT, 100);
	m_list.InsertColumn(10, _T("顾客"), LVCFMT_LEFT, 100);
	//初始化一个宠物信息并写入表格
	Pet p = Pet(_T("123"), _T("123"), _T("001"),
		_T("sunheng"), _T("dog"), _T("18"), _T("75"), _T("1200"), _T("cute"),
		_T("shanchuan"), _T("20240102"), _T("未出售"), _T("无"));
	m_list.InsertItem(0, (LPCTSTR)p.id);
	m_list.SetItemText(0, 0, (LPCTSTR)p.id);
	m_list.SetItemText(0, 1, (LPCTSTR)p.name);
	m_list.SetItemText(0, 2, (LPCTSTR)p.age);
	m_list.SetItemText(0, 3, (LPCTSTR)p.weight);
	m_list.SetItemText(0, 4, (LPCTSTR)p.type);
	m_list.SetItemText(0, 5, (LPCTSTR)p.value);
	m_list.SetItemText(0, 6, (LPCTSTR)p.character);
	m_list.SetItemText(0, 7, (LPCTSTR)p.owner);
	m_list.SetItemText(0, 8, (LPCTSTR)p.date);
	m_list.SetItemText(0, 9, (LPCTSTR)p.state);
	m_list.SetItemText(0, 10, (LPCTSTR)p.customer);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MainSys::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	DWORD dwPos = GetMessagePos();	
	CPoint point(LOWORD(dwPos), HIWORD(dwPos));
	//查看单击位置
	m_list.ScreenToClient(&point);
	LVHITTESTINFO lvinfo;
	lvinfo.pt = point;
	lvinfo.flags = LVHT_ABOVE;
	int nItem = m_list.SubItemHitTest(&lvinfo);
	if (nItem != -1)
	{
		m_id = m_list.GetItemText(nItem, 0);
		m_name = m_list.GetItemText(nItem, 1);
		m_age = m_list.GetItemText(nItem, 2);
		m_weight = m_list.GetItemText(nItem, 3);
		m_type = m_list.GetItemText(nItem, 4);
		m_value = m_list.GetItemText(nItem, 5);
		m_character = m_list.GetItemText(nItem, 6);
		m_onwer = m_list.GetItemText(nItem, 7);
		m_date = m_list.GetItemText(nItem, 8);
		m_state = m_list.GetItemText(nItem, 9);
		M_customer = m_list.GetItemText(nItem, 10);
		UpdateData(FALSE);
	}
	else
	{
		m_id = _T("");
		m_name = _T("");
		m_age = _T("");
		m_weight = _T("");
		m_type = _T("");
		m_value = _T("");
		m_character = _T("");
		m_onwer = _T("");
		m_date = _T("");
		m_state = _T("");
		M_customer = _T("");
		UpdateData(FALSE);
	}
	*pResult = 0;
}


void MainSys::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//添加前异常检查
	CString old_id = m_id;
	int i = 0;
	int nCount = m_list.GetItemCount();
	while (i < nCount)
	{
		old_id = m_list.GetItemText(i, 0);
		if (old_id == m_id)
		{
			MessageBox(_T("编号重复"), _T("添加失败"));
			return;
		}
		i++;
	}
	if (m_name.IsEmpty() || m_age.IsEmpty() || m_weight.IsEmpty() || m_type.IsEmpty() || m_value.IsEmpty() || m_character.IsEmpty())
	{
		MessageBox(_T("信息不完整"), _T("添加失败"));
		return;
	}
	//列表中添加一行
	m_list.InsertItem(0, m_id);
	m_list.SetItemText(0, 1, m_name);
	m_list.SetItemText(0, 2, m_age);
	m_list.SetItemText(0, 3, m_weight);
	m_list.SetItemText(0, 4, m_type);
	m_list.SetItemText(0, 5, m_value);
	m_list.SetItemText(0, 6, m_character);
	m_list.SetItemText(0, 7, m_onwer);
	m_list.SetItemText(0, 8, m_date);
	m_list.SetItemText(0, 9, m_state);
	m_list.SetItemText(0, 10, M_customer);
	MessageBox(_T("添加成功"), _T("添加成功"));
	//清空编辑框
	m_id = _T("");
	m_name = _T("");
	m_age = _T("");
	m_weight = _T("");
	m_type = _T("");
	m_value = _T("");
	m_character = _T("");
	m_onwer = _T("");
	m_date = _T("");
	m_state = _T("");
	M_customer = _T("");
	UpdateData(FALSE);
}


void MainSys::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	int nItem = m_list.GetSelectionMark();
	UpdateData(TRUE);
	//修改前异常检查
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	if (m_name.IsEmpty() || m_age.IsEmpty() || m_weight.IsEmpty() || m_type.IsEmpty() || m_value.IsEmpty() || m_character.IsEmpty()
		||m_onwer.IsEmpty()||m_date.IsEmpty()||m_state.IsEmpty()||M_customer.IsEmpty())
	{
		MessageBox(_T("信息不完整"), _T("修改失败"));
		return;
	}
	//修改列表中的一行
	m_list.SetItemText(nItem, 1, m_name);
	m_list.SetItemText(nItem, 2, m_age);
	m_list.SetItemText(nItem, 3, m_weight);
	m_list.SetItemText(nItem, 4, m_type);
	m_list.SetItemText(nItem, 5, m_value);
	m_list.SetItemText(nItem, 6, m_character);
	m_list.SetItemText(nItem, 7, m_onwer);
	m_list.SetItemText(nItem, 8, m_date);
	m_list.SetItemText(nItem, 9, m_state);
	m_list.SetItemText(nItem, 10, M_customer);
	MessageBox(_T("修改成功"), _T("修改成功"));
	//清空编辑框
	m_id = _T("");
	m_name = _T("");
	m_age = _T("");
	m_weight = _T("");
	m_type = _T("");
	m_value = _T("");
	m_character = _T("");
	m_onwer = _T("");
	m_date = _T("");
	m_state = _T("");
	M_customer = _T("");
	UpdateData(FALSE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
}


void MainSys::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int nItem = m_list.GetSelectionMark();
	m_list.DeleteItem(nItem);
	MessageBox(_T("删除成功"), _T("删除成功"));
	//清空编辑框
	m_id = _T("");
	m_name = _T("");
	m_age = _T("");
	m_weight = _T("");
	m_type = _T("");
	m_value = _T("");
	m_character = _T("");
	m_onwer = _T("");
	m_date = _T("");
	m_state = _T("");
	M_customer = _T("");
	UpdateData(FALSE);
}


void MainSys::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//文件存储位置选择对话框
	CFileDialog dlg(FALSE, _T("txt"), _T("宠物信息"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||"), NULL);
	//确认后写入
	if (dlg.DoModal() == IDOK)
	{
		CString strFilePath = dlg.GetPathName();
		CStdioFile file;
		file.Open(strFilePath, CFile::modeCreate | CFile::modeWrite);
		//写入表头
		file.WriteString(_T("编号\t名字\t年龄\t体重\t种类\t价格\t性格\t主人\t交易日期\t状态\t顾客\n"));
		//写入表格
		int i = 0;
		int nCount = m_list.GetItemCount();
		while (i < nCount)
		{
			CString strTemp;
			int j = 0;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\t"));
			j++;
			strTemp = m_list.GetItemText(i, j);
			file.WriteString(strTemp + _T("\n"));
			i++;
		}
		file.Close();
		MessageBox(_T("保存成功"), _T("保存成功"));
	}	
}
