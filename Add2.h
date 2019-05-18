
// Add2.h: PROJECT_NAME 应用程序的主头文件
//

#pragma once
#include "Add2Dlg.h"
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"		// 主符号


// CAdd2App:
// 有关此类的实现，请参阅 Add2.cpp
//

class CAdd2App : public CWinApp
{
public:
	CAdd2App();
	ULONG_PTR gdiplusToken;

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CAdd2App theApp;
