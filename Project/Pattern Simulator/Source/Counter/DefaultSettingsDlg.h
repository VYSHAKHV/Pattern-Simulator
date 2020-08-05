#pragma once


// CDefaultSettingsDlg dialog

class CDefaultSettingsDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDefaultSettingsDlg)

public:
	CDefaultSettingsDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDefaultSettingsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_DEFAULT_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_SelectedData;
	afx_msg void OnBnClickedOk();
};
