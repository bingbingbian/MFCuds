// UdsDiagDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCUdsTestTool.h"
#include "UdsDiagDlg.h"
#include "afxdialogex.h"

#include "UdsClient.h"



static obd_dtc_t obd_dtc_list[OBD_DTC_CNT] =
{
	{_T("ȼ�ʹ���������"), _T("P04621A"), 0x04621A, 0 },
	{_T("ȼ�ʹ���������"), _T("P04631B"), 0x04631B, 0 },
	{_T("��ص�ѹ����"),   _T("U300316"), 0xF00316, 0 },
	{_T("��ص�ѹ����"),   _T("U300317"), 0xF00317, 0 },
	{_T("ECU���߹ر�"),    _T("U007388"), 0xC07388, 0 },
	{_T("EMSͨ�Ŷ�ʧ"),    _T("U010001"), 0xC10001, 0 },
	{_T("TCUͨ�Ŷ�ʧ"),    _T("U010101"), 0xC10101, 0 },
	{_T("ABSͨ�Ŷ�ʧ"),    _T("U012101"), 0xC12101, 0 },
	{_T("TPMSͨ�Ŷ�ʧ"),   _T("U012701"), 0xC12701, 0 },
	{_T("EPBͨ�Ŷ�ʧ"),    _T("U012801"), 0xC12801, 0 },
	{_T("ESPͨ�Ŷ�ʧ"),    _T("U012901"), 0xC12901, 0 },
	{_T("EPSͨ�Ŷ�ʧ"),    _T("U013101"), 0xC13101, 0 },
	{_T("BCMͨ�Ŷ�ʧ"),    _T("U014100"), 0xC14000, 0 },
	{_T("SRSͨ�Ŷ�ʧ"),    _T("U015101"), 0xC15101, 0 },
	{_T("DVDͨ�Ŷ�ʧ"),    _T("U016300"), 0xC16300, 0 },
	{_T("PDCͨ�Ŷ�ʧ"),    _T("U016900"), 0xC16900, 0 },
	{_T("ALSͨ�Ŷ�ʧ"),    _T("U018101"), 0xC18101, 0 },
	{_T("PEPSͨ�Ŷ�ʧ"),   _T("U023601"), 0xC23601, 0 },
	{_T("ACͨ�Ŷ�ʧ"),     _T("U016400"), 0xC16400, 0 },
	{_T("AVMͨ�Ŷ�ʧ"),    _T("U016700"), 0xC16700, 0 },
	{_T("ɲ��ָʾ�Ƴ���"), _T("B153D01"), 0x953D01, 0 },
	{_T("EPCָʾ�Ƴ���"),  _T("B153E01"), 0x953E01, 0 },
	{_T("TCUָʾ�Ƴ���"),  _T("B153F01"), 0x953F01, 0 },
	{_T("AIRBAGָʾ�Ƴ���"),  _T("B154001"), 0x954001, 0 },
	{_T("ESCָʾ�Ƴ���"),  _T("B154101"), 0x954101, 0 },
	{_T("ABSָʾ�Ƴ���"),  _T("B154401"), 0x954401, 0 },
	{_T("MILָʾ�Ƴ���"),  _T("B154501"), 0x954501, 0 },
	{_T("EPB���ϵƳ���"),  _T("B154601"), 0x954601, 0 },
	{_T("ESC�رյƳ���"),  _T("B154701"), 0x954701, 0 }
};

// CUdsDiagDlg �Ի���

IMPLEMENT_DYNAMIC(CUdsDiagDlg, CDialogEx)

CUdsDiagDlg::CUdsDiagDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_DIAG, pParent)
{

}

CUdsDiagDlg::~CUdsDiagDlg()
{
}

void CUdsDiagDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST_DTC, m_List);
}


BEGIN_MESSAGE_MAP(CUdsDiagDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SPTDTC, &CUdsDiagDlg::OnBnClickedButtonSptdtc)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CLRDTC, &CUdsDiagDlg::OnBnClickedButtonClrdtc)
END_MESSAGE_MAP()


// CUdsDiagDlg ��Ϣ�������


BOOL CUdsDiagDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_List.InsertColumn(0, _T("���"));
	m_List.SetColumnWidth(0, 40);
	m_List.InsertColumn(1, _T("������"));
	m_List.SetColumnWidth(1, 100);
	m_List.InsertColumn(2, _T("��ʾ��"));
	m_List.SetColumnWidth(2, 60);
	m_List.InsertColumn(3, _T("DTC"));
	m_List.SetColumnWidth(3, 65);
	m_List.InsertColumn(4, _T("�ӹ�������"));
	m_List.SetColumnWidth(4, 100);
	m_List.InsertColumn(5, _T("����״̬"));
	m_List.SetColumnWidth(5, 70);
	m_List.InsertColumn(6, _T("״̬λ"));
	m_List.SetColumnWidth(6, 50);

	UINT dtc_n;
	UINT nowItem;
	CString str;
	for (dtc_n = 0; dtc_n < OBD_DTC_CNT; dtc_n++)
	{

			str.Format(_T("%d"), dtc_n);
			nowItem = m_List.InsertItem(dtc_n, str);

			m_List.SetItemText(nowItem, 1, obd_dtc_list[dtc_n].Name);	    //Dtc Name
			m_List.SetItemText(nowItem, 2, obd_dtc_list[dtc_n].DispCode);	//Display code

			str.Format(_T("0X%06X"), obd_dtc_list[dtc_n].DtcCode);
			m_List.SetItemText(nowItem, 3, str);	                        //Dtc

			m_List.SetItemText(nowItem, 5, _T("0x0"));                      //Dtc status

	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CUdsDiagDlg::OnBnClickedButtonSptdtc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE CmdBuf[BUF_LEN];
	UINT CmdLen = 1;

	//ReportSupportedDTC
	CmdBuf[0] = 0x0A;

	theApp.UdsClient.request(SID_19, CmdBuf, CmdLen);

	SetTimer(1, 200, NULL);
	SetTim = TRUE;
}


void CUdsDiagDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	BYTE DataBuf[BUF_LEN];
	UINT readlen;
	UINT remnpos;

	BYTE AvMask;
	UINT DtcCode;
	BYTE DtcSt;


	UINT listrow;
	CString str;

	if (SetTim == TRUE)
	{
		SetTim = FALSE;
		readlen = theApp.UdsClient.get_rsp(DataBuf, BUF_LEN);
		
		AvMask = DataBuf[3];
		remnpos = 3;

		while (remnpos <= readlen)
		{
			DtcCode = 0;
			DtcCode |= (((UINT)DataBuf[remnpos]) << 16);
			DtcCode |= (((UINT)DataBuf[remnpos+1]) << 8);
			DtcCode |= (((UINT)DataBuf[remnpos+2]) << 0);

			DtcSt = DataBuf[remnpos+3];
			remnpos += 4;

			for (listrow = 0; listrow < OBD_DTC_CNT; listrow++)
			{
				if (obd_dtc_list[listrow].DtcCode == DtcCode)
				{
					str.Format(_T("0X%02X"), DtcSt);
					m_List.SetItemText(listrow, 5, str);             //Dtc status

					break;
				}
			}

		}

	}
	CDialogEx::OnTimer(nIDEvent);
}



void CUdsDiagDlg::OnBnClickedButtonClrdtc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BYTE CmdBuf[BUF_LEN];
	UINT CmdLen = 3;

	//All Group
	CmdBuf[0] = 0xFF;
	CmdBuf[1] = 0xFF;
	CmdBuf[2] = 0xFF;

	theApp.UdsClient.request(SID_14, CmdBuf, CmdLen);
}
