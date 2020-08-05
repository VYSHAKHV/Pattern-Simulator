// DefaultSettingsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Counter.h"
#include "DefaultSettingsDlg.h"
#include "afxdialogex.h"


// CDefaultSettingsDlg dialog

IMPLEMENT_DYNAMIC(CDefaultSettingsDlg, CDialogEx)

CDefaultSettingsDlg::CDefaultSettingsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1_DEFAULT_SETTINGS, pParent)
	, m_SelectedData(_T(""))
{

}

CDefaultSettingsDlg::~CDefaultSettingsDlg()
{
}

void CDefaultSettingsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_OPTIONS, m_SelectedData);
}


BEGIN_MESSAGE_MAP(CDefaultSettingsDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDefaultSettingsDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CDefaultSettingsDlg message handlers


void CDefaultSettingsDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData();
	
	CDialogEx::OnOK();
}
