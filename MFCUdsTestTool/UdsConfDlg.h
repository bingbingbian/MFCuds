#pragma once


// CUdsConfDlg �Ի���

class CUdsConfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUdsConfDlg)

public:
	CUdsConfDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUdsConfDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UDSCONF };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CString m_FuncId;
	CString m_PhysId;
	CString m_RspnId;
	CString m_IdResult;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSaveid();

};
