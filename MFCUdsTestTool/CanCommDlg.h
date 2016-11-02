#pragma once
#include "ColoredListCtrl.h"
#include "ControlCAN.h"

// CCanCommDlg �Ի���

class CCanCommDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCanCommDlg)

public:
	CCanCommDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCanCommDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COMM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CColoredListCtrl m_List;
	BOOL m_CanRxEn;

	CString m_Editcantx;
	CString m_EditCanid;

	BOOL m_CanExt;
	BOOL m_CanRmt;

public:
	afx_msg void OnBnClickedCheckRecv();
	afx_msg void OnBnClickedButtonTx();
	afx_msg void OnBnClickedButtonClear();
	virtual BOOL OnInitDialog();
	// Insert a Can msg to list
	void InsertItem(INT Dire, VCI_CAN_OBJ * pCanObj);
};
