
// MFCUdsTestTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCUdsTestToolApp: 
// �йش����ʵ�֣������ MFCUdsTestTool.cpp
//

class CMFCUdsTestToolApp : public CWinApp
{
public:
	CMFCUdsTestToolApp();

	UINT m_Bgnid;
	UINT m_Endid;
	BOOL m_FilterEn;
	UINT m_CanChnl;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCUdsTestToolApp theApp;