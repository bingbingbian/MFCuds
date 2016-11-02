
// MFCUdsTestToolDlg.h : ͷ�ļ�
//

#pragma once
#include "ColoredListCtrl.h"
#include "afxwin.h"
#include "CanCommDlg.h"
#include "UdsDiagDlg.h"
#include "UdsCcDlg.h"

#include "ControlCAN.h"

// CMFCUdsTestToolDlg �Ի���
class CMFCUdsTestToolDlg : public CDialogEx
{

// ����
public:
	CMFCUdsTestToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCUDSTESTTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CTabCtrl m_Table;
	CMenu m_Menu;
	CColoredListCtrl *m_List;

	int m_CurSelTab;
	CCanCommDlg m_CanComm;
	CUdsDiagDlg m_UdsDiag;
	CDialog* pDialog[2];  //��������Ի������ָ��

public:
	static INT TransmitCanmsg(VCI_CAN_OBJ *SendObj);
	static UINT UdsMainThread(void *param);
	static UINT ReceiveThread(void *param);

	afx_msg void OnBnClickedBtOpendev();
	afx_msg void OnMenuOpendev();
	afx_msg void OnMenuClosedev();
	afx_msg void OnMenuRdid();
	//DECLARE_EVENTSINK_MAP()
	afx_msg void OnMenuWdid();
	afx_msg void OnMenuReset();
	afx_msg void OnMenuDtcon();
	afx_msg void OnMenuDtcoff();
	afx_msg void OnMenuRddtc();
	afx_msg void OnMenuCrdtc();
	afx_msg void OnTcnSelchangeTabMain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMenuCc();
	afx_msg void OnMenuUdsconf();
};
