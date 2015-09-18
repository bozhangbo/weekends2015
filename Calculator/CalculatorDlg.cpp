
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent),
	_operand1(0.0),
	_operand2(0.0),
	_result(0.0),
	_output(_T("0")),
	_operator(_T('+')),
	_state(StateOperandExpectSign)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_OUTPUT, _output);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CCalculatorDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &CCalculatorDlg::OnBnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CCalculatorDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CCalculatorDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_three, &CCalculatorDlg::OnBnClickedButtonthree)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_four, &CCalculatorDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_five, &CCalculatorDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CCalculatorDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CCalculatorDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CCalculatorDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CCalculatorDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE, &CCalculatorDlg::OnBnClickedButtonDivide)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CCalculatorDlg::OnBnClickedButtonClear)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::OnBnClickedButtonZero()
{
	ProcessChar(_T('0'));
}


void CCalculatorDlg::OnBnClickedButtonDot()
{
	ProcessChar(_T('.'));
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	ProcessChar(_T('='));
}

void CCalculatorDlg::OnBnClickedButtonOne()
{
	ProcessChar('1');
}


void CCalculatorDlg::OnBnClickedButtonTwo()
{
	ProcessChar('2');
}


void CCalculatorDlg::OnBnClickedButtonthree()
{
	ProcessChar('3');
}


void CCalculatorDlg::OnBnClickedButtonAdd()
{
	ProcessChar('+');
}


void CCalculatorDlg::OnBnClickedButtonFour()
{
	ProcessChar('4');
}


void CCalculatorDlg::OnBnClickedButtonFive()
{
	ProcessChar('5');
}


void CCalculatorDlg::OnBnClickedButtonSix()
{
	ProcessChar('6');
}


void CCalculatorDlg::OnBnClickedButtonSeven()
{
	ProcessChar('7');
}


void CCalculatorDlg::OnBnClickedButtonEight()
{
	ProcessChar('8');
}


void CCalculatorDlg::OnBnClickedButtonNine()
{
	ProcessChar('9');
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	ProcessChar('-');
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	ProcessChar('*');
}

void CCalculatorDlg::OnBnClickedButtonDivide()
{
	ProcessChar('/');
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	ProcessChar('C');
}

double CCalculatorDlg::Calc()
{
	switch (_operator)
	{
	case _T('+'):
		return _operand1 + _operand2;
	case _T('-'):
		return _operand1 - _operand2;
	case _T('*'):
		return _operand1 * _operand2;
	case _T('/'):
		if (_operand2 == 0)
		{
			AfxMessageBox(_T("Divided by 0."));
			return 0.0;
		}
		return _operand1 / _operand2;
	default:
		ASSERT(0);
	}

	return 0.0;
}

bool CCalculatorDlg::ProcessChar(TCHAR ch)
{
	if (ch == _T('C'))
	{
		_output = _T("0");
		_operand1 = 0;
		_operator = _T('+');
		_state = StateOperandExpectSign;

		UpdateData(FALSE);

		return true;
	}

	switch (_state)
	{
		case StateOperandExpectSign: 
			if (ch >= _T('0') && ch <= _T('9'))
			{
				_output = ch;
				_state = StateOperandExpectDot;
			}
			else if (ch == _T('.'))
			{
				_output += ch;
				_state = StateOperandAfterDot;
			}
			UpdateData(FALSE);
			break;

		case StateOperandExpectDot: 
			if (ch >= _T('0') && ch <= _T('9'))
			{
				_output += ch;
			}
			else if (ch == _T('.'))
			{
				_output += ch;
				_state = StateOperandAfterDot;
			}
			else if (ch == _T('+') || ch == _T('-') || ch == _T('*') || ch == _T('/'))
			{
				_operand2 = atof(CT2CA(_output));
				_operand1 = Calc();
				_output.Format(_T("%lf"), _operand1);

				_operator = ch;
				_state = StateOperandExpectSign;
			}
			else if (ch == _T('='))
			{
				_operand2 = atof(CT2CA(_output));
				_operand1 = Calc();
				_output.Format(_T("%lf"), _operand1);
				_state = StateAfterEqual;
			}

			UpdateData(FALSE);
			break;
		case StateOperandAfterDot:
			if (ch >= _T('0') && ch <= _T('9'))
			{
				_output += ch;
			}
			else if (ch == _T('+') || ch == _T('-') || ch == _T('*') || ch == _T('/'))
			{
				_operand2 = atof(CT2CA(_output));
				_operand1 = Calc();
				_output.Format(_T("%lf"), _operand1);
				_operator = ch;
				_state = StateOperandExpectSign;
			}
			else if (ch == _T('='))
			{
				_operand2 = atof(CT2CA(_output));
				_operand1 = Calc();
				_output.Format(_T("%lf"), _operand1);
				_state = StateAfterEqual;
			}

			UpdateData(FALSE);
			break;
		case StateAfterEqual:
			if (ch >= _T('0') && ch <= _T('9'))
			{
				_operand1 = 0;
				_operator = _T('+');
				_state = StateOperandExpectDot;
				ProcessChar(ch);
			}
			else if (ch == _T('+') || ch == _T('-') || ch == _T('*') || ch == _T('/'))
			{
				_operand2 = _operand1;
				_operand1 = 0;

				_operator = _T('+');
				_state = StateOperandExpectDot;
				ProcessChar(ch);
			}
			break;
		default:
			ASSERT(0);
			return false;
	}

	return true;
}
