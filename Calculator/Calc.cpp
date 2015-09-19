#include "stdafx.h"
#include "Calc.h"


CCalc::CCalc() :
	_operand1(0.0),
	_operand2(0.0),
	_result(0.0),
	_operator(_T('+')),
	_state(StateOperandExpectSign),
	_output(_T("0"))
{
}

CCalc::~CCalc()
{
}

CString CCalc::ProcessChar(TCHAR ch)
{
	if (ch == _T('C'))
	{
		_output = _T("0");
		_operand1 = 0;
		_operator = _T('+');
		_state = StateOperandExpectSign;

		return _output;
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
		return _output;
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

		return _output;
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

		return _output;
		break;
	case StateAfterEqual:
		if (ch >= _T('0') && ch <= _T('9'))
		{
			_operand1 = 0;
			_operator = _T('+');
			_state = StateOperandExpectDot;
			return ProcessChar(ch);
		}
		else if (ch == _T('+') || ch == _T('-') || ch == _T('*') || ch == _T('/'))
		{
			_operand2 = _operand1;
			_operand1 = 0;

			_operator = _T('+');
			_state = StateOperandExpectDot;
			return ProcessChar(ch);
		}
		break;
	default:
		ASSERT(0);
		return _T("");
	}

	return _output;
}

double CCalc::Calc()
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
