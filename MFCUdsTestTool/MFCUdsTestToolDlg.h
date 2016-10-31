
// MFCUdsTestToolDlg.h : ͷ�ļ�
//

#pragma once
#include "ColoredListCtrl.h"
#include "afxwin.h"

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
	CMenu m_Menu;
	CColoredListCtrl m_list;
	BOOL m_CanRxEn;

	CString m_Editcantx;
	CString m_EditCanid;

	BOOL m_CanExt;
	BOOL m_CanRmt;

public:
	static UINT UdsMainThread(void *param);
	static UINT ReceiveThread(void *param);
	static UINT TransmitCanmsg(BYTE CanData[], BYTE CanDlc);
public:
	afx_msg void OnMenuOpendev();
	afx_msg void OnBnClickedCheckRecv();
	afx_msg void OnBnClickedButtonTx();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnMenuClosedev();
	afx_msg void OnMenuRdid();
	//DECLARE_EVENTSINK_MAP()
	afx_msg void OnMenuWdid();
	afx_msg void OnMenuReset();
	afx_msg void OnMenuDtcon();
	afx_msg void OnMenuDtcoff();
	afx_msg void OnMenuRddtc();
	afx_msg void OnMenuCrdtc();
};
