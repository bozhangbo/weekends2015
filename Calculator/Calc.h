#pragma once

class CCalc
{
public:
	CCalc();
	virtual ~CCalc();

	enum State
	{
		StateOperandExpectSign,
		StateOperandExpectDot,
		StateOperandAfterDot,
		StateExpectOperator,
		StateAfterEqual,
	} _state;

	CString ProcessChar(TCHAR ch);
	CString GetOpposite();
	double Calc();

	double _operand1;
	double _operand2;
	double _result;

	char _operator;
	CString _output;
};

