
// Add2Dlg.h: 头文件
//

#pragma once
#include"gdiplus.h"
#include"Vector2.h"
#include"Vector3.h"
#include"Border3.h"
#include"Project3.h"
#include"Matrix4x3.h"
#include"MathUtil.h"
using namespace Gdiplus;

// CAdd2Dlg 对话框
class CAdd2Dlg : public CDialogEx
{
// 构造
public:
	CAdd2Dlg(CWnd* pParent = nullptr);	// 标准构造函数

	double angle = 0.0;
	CDC* pDC = NULL;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool antialisingLine(CDC* pDC, Vector2 start, Vector2 end, bool choose/*是否开启颜色渐变*/, COLORREF backgroundColor/*背景颜色*/);
	bool DrawProject3(Project3& p, CDC* pDC,  COLORREF backgroundColor, bool choose/*是否开启颜色渐变*/, bool blank/*是否开启消隐*/,int mode/*模型类型*/);
	void DrawSurface3(Surface3 sur, bool colInterpolation);
};
