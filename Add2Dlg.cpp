
// Add2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Add2.h"
#include "Add2Dlg.h"
#include "afxdialogex.h"
#include"Project3.h"
#include"MyColor.h"
#include<iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define COL(x) RGB(Round(x*(bR-cRi)+cRi), Round(x * (bG - cGi) + cGi), Round(x * (bB - cBi) + cBi))

using namespace std;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
Vector3 p[8] = { Vector3(-100.0f,-100.0f,-100.0f,RED),Vector3(100.0f,-100.0f,-100.0f,BLUE),Vector3(100.0f,100.0f,-100.0f,GREEN),
						Vector3(-100.0f,100.0f,-100.0f,YELLOW),Vector3(-100.0f,100.0f,100.0f,RED),Vector3(100.0f,100.0f,100.0f,BLUE),
						Vector3(100.0f,-100.0f,100.0f,GREEN),Vector3(-100.0f,-100.0f,100.0f,YELLOW) };
Border3 e[12] = { Border3(&p[0],&p[1]),Border3(&p[1],&p[2]),Border3(&p[2],&p[3]),Border3(&p[3],&p[0]),
						Border3(&p[4],&p[5]),Border3(&p[5],&p[6]),Border3(&p[6],&p[7]),Border3(&p[7],&p[4]),
						Border3(&p[0],&p[7]),Border3(&p[1],&p[6]),Border3(&p[2],&p[5]),Border3(&p[3],&p[4]) };
//Vector3 q[6] = { Vector3(0.0f,0.0f,50.0f,RED),Vector3(0.0f,0.0f,150.0f,GREEN),Vector3(-50.0f,-50.0f,100.0f,YELLOW)
			//,Vector3(50.0f,-50.0f,100.0f,BLUE) ,Vector3(50.0f,50.0f,100.0f,PINK) ,Vector3(-50.0f,50.0f,100.0f,LAVENDERBLUSH) };
vector<Vector3> p1=vector<Vector3>(p, p + 8);
//vector<Vector3> p2 = vector<Vector3>(q, q + 6);
//vector<Border3> b1=vector<Border3>(e, e + 12);
Project3 cube(p1, "0,1,1,2,2,3,3,0,4,5,5,6,6,7,7,4,0,7,1,6,2,5,3,4,");
//Project3 Octahedron(p2,"0,2,0,3,0,4,0,5,1,2,1,3,1,4,1,5,");
Vector3 v1(1.0f, 1.0f, 1.0f);
Vector3 n(0.0f, 0.0f, 1.0f);
Matrix4x3 ma;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAdd2Dlg 对话框



CAdd2Dlg::CAdd2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdd2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAdd2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CAdd2Dlg 消息处理程序

BOOL CAdd2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAdd2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAdd2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CWnd* pWnd;
		pWnd = GetDlgItem(IDC_STATIC);
		CRect rect;
		pWnd->GetClientRect(&rect);
		 pDC= pWnd->GetDC();
		pDC->SetMapMode(MM_ANISOTROPIC);
		pDC->SetROP2(R2_NOTXORPEN);
		pDC->SetWindowExt(rect.Width(), rect.Height());
		pDC->SetViewportExt(rect.Width(), -rect.Height());
		pDC->SetViewportOrg(rect.Width() / 2, rect.Height() / 2);
		rect.OffsetRect(-rect.Width() / 2, -rect.Height() / 2);

		//画坐标轴
		antialisingLine(pDC, Vector2(-rect.Width()/2, 0.0f,BLACK), Vector2(rect.Width() / 2, 0.0f,BLACK),1,WHITE);
		antialisingLine(pDC, Vector2(0.0f, -rect.Height()/2,BLACK), Vector2(0.0f, rect.Height() / 2,BLACK),1,WHITE);
		//绘图部分
		CBrush brush;
		brush.CreateSolidBrush(BLACK);
		pDC->FillRect(rect,&brush);
		//DrawProject3(cube, pDC, BLACK, 1, 1, WIREFRAME);
		DrawProject3(cube, pDC, BLACK, 1, 1, SURFACE);
		SetTimer(1, 1000, NULL);
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAdd2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAdd2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nIDEvent) {
	case 1:
		cout << "定时器触发！" << endl;
		v1.normalize();
		ma.setupRotate(v1, 0.1);
		//DrawProject3(cube, pDC,BLACK,1,1,WIREFRAME);
		DrawProject3(cube, pDC, BLACK, 1, 1, SURFACE);
		cube.transWithMatrix(ma);
		cube.faceBlanking(n);
		//DrawProject3(cube, pDC, BLACK, 1, 1, WIREFRAME);
		DrawProject3(cube, pDC, BLACK, 1, 1, SURFACE);
		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}


bool CAdd2Dlg::antialisingLine(CDC* pDC, Vector2 start, Vector2 end,bool choose/*是否开启颜色渐变*/,COLORREF backgroundColor/*背景颜色*/)
{
	// TODO: 在此处添加实现代码.
	
	//交换起点和终点使正方向朝向第一、二象限；
	if (start.y > end.y) {
		Vector2 t=start;
		start = end;
		end = t;
	}
	//变量：主位移方向,0代表x为主位移方向，1代表y为主位移方向；
	BOOL mainDirect;
	//将背景色的R、G、B分量都提出来
	int bR, bG, bB;
	
	//将起点、终点的RGB分量提出来
	COLORREF startcol, endcol;
	if (choose) {
		bR = GetRValue(backgroundColor);
		bG = GetGValue(backgroundColor);
		bB = GetBValue(backgroundColor);
		startcol = start.color2+RGB(0,0,0);
		endcol = end.color2+RGB(0,0,0);
	}
	else {
		bR = 255;
		bG = 255;
		bB = 255;
		startcol = RGB(0,0,0);
		endcol = RGB(0,0,0);
	}
	 
	int sR, sG, sB;
	int eR, eG, eB;
	sR = GetRValue(startcol);
	sG= GetGValue(startcol);
	sB= GetBValue(startcol);
	eR= GetRValue(endcol);
	eG = GetGValue(endcol);
	eB = GetBValue(endcol);
	//分别计算起点和终点的颜色差值分量
	int dR = eR - sR;
	int dG = eG - sG;
	int dB = eB - sB;
	cout << "R差值：" << dR << "G差值：" << dG << "B差值：" << dB << endl;
	//设置主位移颜色差值单元(在判断出主位移后使用)
	float ddR, ddG, ddB;
	//1.给出起点和终点,判断主位移方向
	float dy = end.y - start.y;
	cout << "dy:" << dy << endl;
	float dx = end.x - start.x;
	float abDx = fabs(dx);
	cout << "abDX:" << abDx << endl;
	if ((dy - abDx) < 0.0) {
		//说明Y轴增量没有x轴增量大，主位移方向为x轴正方向
		cout << "主位移方向确定为x轴正方向" << endl;
		mainDirect = 0;
		//设置主位移方向上的颜色差值单元量
		ddR = (float)dR / abDx;
		ddG = (float)dG / abDx;
		ddB = (float)dB / abDx;
	}
	else {
		//相反地，主位移方向为y轴正方向
		cout << "主位移方向确定为y轴正方向" << endl;
		mainDirect = 1;
		//设置主位移方向上的颜色差值单元量
		ddR = (float)dR / dy;
		ddG = (float)dG / dy;
		ddB = (float)dB / dy;
	}
	//2.针对主位移方向计算斜率,确保不出现分母为0的情况
	float k=0.0;
	//初始化距离误差项e
	float e = 0.0;
	//初始化绘制起点
	int yi = start.y;
	int xi = start.x;
	//初始化绘制颜色值；
	float cRi = sR*1.0;
	float cGi = sG*1.0;
	float cBi = sB*1.0;
	switch (mainDirect) {
	case 0://主位移方向为x轴，因为正方向朝向第一、二象限，
		//所以当主位移方向是x轴时需要分k<0和k>0两种情况
		k = dy / dx;
		cout << "主位移为x轴"<<"未变换k:"<<k << endl;
		if (k == 0.0) {//水平线
			if(choose){
				do {
					pDC->SetPixelV(xi, yi, COL(e));
					cRi = cRi + ddR;
					cGi = cGi + ddG;
					cBi = cBi + ddB;
					start.x>end.x?xi--:xi++;
					//cout << "xi:" << xi << endl;
					//截取e的小数部分,使e永远小于1

				} while (start.x > end.x ? xi >= end.x: xi <= end.x);
			}
			else{
			pDC->MoveTo(start.toCPoint());
			pDC->LineTo(end.toCPoint());
			}
			return true;
		}
		else if (k < 0.0) {//-1<k<0
			k = -k;
			cout << "变换之后的k:" << k << endl;
			do {
				pDC->SetPixelV(xi,yi,COL(e));
				pDC->SetPixelV(xi, yi + 1, COL((1-e)));
				e += k;
				if (e >= 1.0) {
					e -= 1.0;
					yi += 1;
				}
				cRi = cRi + ddR;
				cGi = cGi + ddG;
				cBi = cBi + ddB;
				xi--;
				//cout << "xi:" << xi << endl;
				//截取e的小数部分,使e永远小于1

			} while (xi>=end.x);
			return true;
		}
		else {//1>k>0
			cout << "变换之后的k:" << k << endl;
			do {
				pDC->SetPixelV(xi, yi, COL(e));
				pDC->SetPixelV(xi, yi + 1, COL((1 - e)));
				e += k;
				if (e >= 1.0) {
					e -= 1.0;
					yi += 1;
				}
				cRi = cRi + ddR;
				cGi = cGi + ddG;
				cBi = cBi + ddB;
				xi++;
				//截取e的小数部分,使e永远小于1

			} while (xi <= end.x);
			return true;
		}
		break;
	case 1://主位移方向为y轴
		k = dx / dy;
		cout << "主位移为y轴" << "未变换k:" << k << endl;
		if (k == 0.0) {
			if (choose) {
				do {
					pDC->SetPixelV(xi, yi, COL(e));
					cRi = cRi + ddR;
					cGi = cGi + ddG;
					cBi = cBi + ddB;
					yi++;
					//cout << "xi:" << xi << endl;
					//截取e的小数部分,使e永远小于1

				} while (yi<=end.y);
			}
			else {
				pDC->MoveTo(start.toCPoint());
				pDC->LineTo(end.toCPoint());
			}
			//垂直线
			
			return true;
		}
		else if (k < 0.0) {
			//-1>k>负无穷
			k = -k;
			cout << "变换之后的k:" << k << endl;
			do {
				pDC->SetPixelV(xi, yi, COL(e));
				pDC->SetPixelV(xi-1, yi, COL((1 - e)));
				e += k;
				if (e >= 1.0) {
					e -= 1.0;
					xi -= 1;
				}
				cRi = cRi + ddR;
				cGi = cGi + ddG;
				cBi = cBi + ddB;
				yi++;
				//截取e的小数部分,使e永远小于1

			} while (yi <= end.y);
			return true;
		}
		else {
			//正无穷>k>1
			cout << "变换之后的k:" << k << endl;
			do {
				pDC->SetPixelV(xi, yi, COL(e));
				pDC->SetPixelV(xi + 1, yi, COL((1 - e)));
				e += k;
				if (e >= 1.0) {
					e -= 1.0;
					xi += 1;
				}
				cRi = cRi + ddR;
				cGi = cGi + ddG;
				cBi = cBi + ddB;
				yi++;
				//截取e的小数部分,使e永远小于1

			} while (yi <= end.y);
			return true;
		}
		break;
	default:
		return false;
		break;
	}
	//cout << "dy:" << dy << ",dx:" << dx << ",k:" << k << endl;

	return false;
}


bool CAdd2Dlg::DrawProject3(Project3& p, CDC* pDC,COLORREF backgroundColor, bool choose, bool blank/*是否开启消隐*/,int mode/*模型类型*/)
{
	// TODO: 在此处添加实现代码.
	switch (mode) {
	case WIREFRAME:
		//画边（线框模型）
		for (vector<Border3>::iterator iter = p.borderTable.begin(); iter != p.borderTable.end(); ++iter) {
			if (blank == true && iter->shouldBeShow == false) {

			}
			else {
				antialisingLine(pDC, iter->start->toVector2(), iter->end->toVector2(), choose, backgroundColor);
			}
		}
		break;
	case SURFACE:
		//画面（表面模型）
		for (vector<Surface3>::iterator iter = p.surfaceTable.begin(); iter != p.surfaceTable.end(); ++iter) {
			if (blank == true && iter->shouldBeShow == false) {

			}
			else {
				DrawSurface3(*iter, choose);
			}
		}
		break;
	case ENTITY:
		break;
	default:break;
	}
	
	
	return false;
}


void CAdd2Dlg::DrawSurface3(Surface3 sur, bool colInterpolation)
{
	// TODO: 在此处添加实现代码.

}
