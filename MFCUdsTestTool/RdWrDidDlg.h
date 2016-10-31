#pragma once
#include "ColoredListCtrl.h"

// CReadDidDlg �Ի���

class CRdWrDidDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRdWrDidDlg)

public:
	CRdWrDidDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CRdWrDidDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RDWRDID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CColoredListCtrl m_list;

public:
	enum { EmRd = 0, EmWr = 1 };
	BYTE RdWr;
	int nItem, nSubItem;
	BOOL SetTim;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtRddid();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLvnItemchangedListRdid(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListRdid(NMHDR *pNMHDR, LRESULT *pResult);
	// shis function inserts the default values into the listControl
	void InsertItems();
	// this function will returns the item text depending on the item and SubItem Index
	CString GetItemText(HWND hWnd, int nItem, int nSubItem) const;
	afx_msg void OnNMClickListRdwrdid(NMHDR *pNMHDR, LRESULT *pResult);
	// This function set the text in the specified SubItem depending on the Row and Column values
	void SetCell(HWND hWnd1, CString value, int nRow, int nCol);
};
