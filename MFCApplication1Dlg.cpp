
// MFCApplication1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
//#include <shellapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/*
HINSTANCE ShellExecuteW(
        HWND hwnd,
        LPCTSTR lpOperation,
        LPCTSTR lpFile,
        LPCTSTR lpParameters,
        LPCTSTR lpDirectory,
        INT nShowCmd
);
*/

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	ShowWindow(SW_HIDE);	// 点击完后隐藏此对话框
	
	FILE *fp = fopen("voice\\temp.vbs", "a");
	//FILE *fp2 = fopen("1.vbs", "r");
	FILE *fp4 = fopen("voice\\temp.bat", "a");
	char* s = "CreateObject(\"SAPI.SpVoice\").Speak(\"";
	char* s4 = "@echo off\ntype voice\\*.txt >>voice\\temp.vbs\necho \^\"\^\) >>voice\\temp.vbs\nvoice\\temp.vbs\ndel voice\\temp.vbs\ndel voice\\temp.bat\n";
	//char* s2 = "\")";
	//char* s3 = "\@echo off\n";
	//char txt[500];
	//char buf[500];
	//fputs(s3, fp);
	fputs(s, fp);
	fclose(fp);
	//fgets(buf, 500, fp2);	
	//strcat(txt, buf);
	//fputs(txt, fp);
	fclose(fp);
	fputs(s4, fp4);
	fclose(fp4);
	//system("temp.bat");
	WinExec("voice\\temp.bat", SW_HIDE);
	//WinExec(cmd, SW_HIDE);
	//WinExec(cmd.c_str(), SW_HIDE);
	//system("type 1.txt >>temp.vbs");
	//system("echo \^\"\^\) >>temp.vbs");
	//ShellExecuteA(NULL,"open","temp.bat",NULL,NULL,SW_HIDE);
	//fseek(fp, 0, SEEK_SET);
	//fwrite(s, strlen(s), 1, fp);
	//system("echo \"^) >> temp.txt");
	//system("exit");
	//fprintf(fp, "%s\")", *fp2);
	//fopen("temp.txt", "w");
	//fseek(fp, 0, 0);
	//fwrite(s2, strlen(s2),1,fp);
	
	//system("echo off");
	//ShellExecuteA(NULL, "open", "temp.vbs", NULL, NULL, SW_HIDE);
	//system("temp.vbs");
	//system("del temp.vbs");
	//Sleep(500);
	exit(0);
}
