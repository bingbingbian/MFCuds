
// MFCUdsTestTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "UdsClient.h"

#define FUNCID 0x7DF
#define PHYSID 0x766
#define RSPNID 0x706

#define FUNCID_STR _T("0x7DF")
#define PHYSID_STR _T("0x766")
#define RSPNID_STR _T("0x706")

// CMFCUdsTestToolApp: 
// �йش����ʵ�֣������ MFCUdsTestTool.cpp
//

class CMFCUdsTestToolApp : public CWinApp
{
public:
	CMFCUdsTestToolApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	UINT m_Fucid = FUNCID;
	UINT m_Phyid = PHYSID;
	UINT m_Rspid = RSPNID;

	UINT m_Bgnid;
	UINT m_Endid;
	BOOL m_FilterEn;
	UINT m_CanChnl;

	CUdsClient UdsClient;
	DECLARE_MESSAGE_MAP()
};

extern CMFCUdsTestToolApp theApp;