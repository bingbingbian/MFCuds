// UdsCcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCUdsTestTool.h"
#include "UdsCcDlg.h"
#include "afxdialogex.h"

#include "UdsClient.h"


// CUdsCcDlg �Ի���

IMPLEMENT_DYNAMIC(CUdsCcDlg, CDialogEx)

CUdsCcDlg::CUdsCcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CC, pParent)
{

}

CUdsCcDlg::~CUdsCcDlg()
{
}

void CUdsCcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO_CCSUB, m_combccsub);
	DDX_Control(pDX, IDC_COMBO_CCTYPE, m_combcctype);

	DDX_Text(pDX, IDC_EDIT_CCRST, m_CcResult);
}


BEGIN_MESSAGE_MAP(CUdsCcDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CC, &CUdsCcDlg::OnBnClickedButtonCc)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CUdsCcDlg ��Ϣ�������


BOOL CUdsCcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_combccsub.SetCurSel(3); //Ԥ�� �رս��պͷ���
	m_combcctype.SetCurSel(1);//Ԥ�� һ�㱨��

	m_CcResult = _T("");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CUdsCcDlg::OnBnClickedButtonCc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE CmdBuf[BUF_LEN];
	UINT CmdLen = 2;

	
	CmdBuf[0] = 0x03;
	theApp.UdsClient.request(SID_10, CmdBuf, 1);
	Sleep(50);
	//Communication Control
	CmdBuf[0] = m_combccsub.GetCurSel();
	CmdBuf[1] = m_combcctype.GetCurSel();

	theApp.UdsClient.request(SID_28, CmdBuf, CmdLen);

	SetTimer(1, 200, NULL);
	SetTim = TRUE;
}


void CUdsCcDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	BYTE DataBuf[BUF_LEN];
	UINT readlen;
	if (SetTim == TRUE)
	{
		SetTim = FALSE;
		readlen = theApp.UdsClient.get_rsp(DataBuf, BUF_LEN);
		m_CcResult = _T("");
		if (readlen > 0)
			m_CcResult += _T("Success");
		else
			m_CcResult += _T("Failed");

		UpdateData(false);//��������
			
	}

	CDialogEx::OnTimer(nIDEvent);
}
