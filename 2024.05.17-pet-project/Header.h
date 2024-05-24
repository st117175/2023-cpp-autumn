#pragma once
#include <cmath>
#include <iostream>


const double PI = acos(-1.0);

class CComplex
{
private:
	double _Re;
	double _Im;

	void disposeCComplex()
	{
		_Re = 0;
		_Im = 0;
	}
public:
	CComplex()
		: _Re(0), _Im(0) {}

	CComplex(double Re, double Im)
		: _Re(Re), _Im(Im) {}

	CComplex(const CComplex& src) : _Re(src._Re), _Im(src._Im) {}

	~CComplex()
	{
		disposeCComplex();
	}

	void setRe(double Re) { _Re = Re; }
	double getRe() { return _Re; }

	void setIm(double Im) { _Im = Im; }
	double getIm() { return _Im; }

	double Cmodule()
	{
		return sqrt((pow(_Re, 2) + pow(_Im, 2)));
	}

	double arg()
	{
		return atan2(_Im, _Re);
	}

	CComplex ConjugateNum()
	{
		return CComplex(_Re, -_Im);
	}

	CComplex InverseNum()
	{
		double ReNew = ConjugateNum()._Re / pow(Cmodule(), 2);
		double ImNew = ConjugateNum()._Im / pow(Cmodule(), 2);
		return CComplex(ReNew, ImNew);
	}

	friend CComplex operator+(CComplex CNum1, CComplex CNum2);
	friend CComplex operator-(CComplex CNum1, CComplex CNum2);
	friend CComplex operator*(CComplex CNum1, CComplex CNum2);
	friend CComplex operator*(CComplex CNum1, double value);
	friend CComplex operator*(double value, CComplex CNum1);
	friend CComplex operator/(CComplex CNum1, CComplex CNum2);
	friend CComplex operator/(CComplex CNum1, double value);
	friend bool operator==(CComplex CNum1, CComplex CNum2);
	CComplex operator-() const;
};

CComplex operator+(CComplex CNum1, CComplex CNum2)
{
	double ReNew = CNum1._Re + CNum2._Re;
	double ImNew = CNum1._Im + CNum2._Im;
	return CComplex(ReNew, ImNew);
}

CComplex operator-(CComplex CNum1, CComplex CNum2)
{
	double ReNew = CNum1._Re - CNum2._Re;
	double ImNew = CNum1._Im - CNum2._Im;
	return CComplex(ReNew, ImNew);
}

CComplex operator*(CComplex CNum1, CComplex CNum2)
{
	double ReNew = CNum1._Re * CNum2._Re - CNum1._Im * CNum2._Im;
	double ImNew = CNum1._Re * CNum2._Im + CNum1._Im * CNum2._Re;
	return CComplex(ReNew, ImNew);
}

CComplex operator*(CComplex CNum1, double value)
{
	return CComplex(CNum1._Re * value, CNum1._Im * value);
}

CComplex operator*(double value, CComplex CNum1)
{
	return CComplex(CNum1._Re * value, CNum1._Im * value);
}

CComplex operator/(CComplex CNum1, CComplex CNum2)
{
	return CNum1 * CNum2.InverseNum();
}

CComplex operator/(CComplex CNum1, double value)
{
	return CComplex(CNum1._Re / value, CNum1._Im / value);
}

bool operator==(CComplex CNum1, CComplex CNum2)
{
	if (CNum1._Re == CNum2._Re && CNum1._Im == CNum2._Im)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CComplex CComplex::operator-() const
{
	return CComplex(-_Re, -_Im);
}

double sinus(double x)
{
	if (sin(x) < double(1) / pow(10, 10) && sin(x) > 0)
	{
		return 0;
	}
	else if (sin(x) > -double(1) / pow(10, 10) && sin(x) < 0)
	{
		return -0;
	}
	else
	{
		return sin(x);
	}
}

double cosinus(double x)
{
	if (cos(x) < double(1) / pow(10, 10) && cos(x) > 0)
	{
		return 0;
	}
	else if (cos(x) > -double(1) / pow(10, 10) && cos(x) < 0)
	{
		return -0;
	}
	else
	{
		return cos(x);
	}
}

 void Solution_linear_equation(CComplex CNum1, CComplex CNum2, CComplex CNum3, double* linear_equation)
{

	 linear_equation[0] = ((CNum3 - CNum1) / CNum2).getRe();
	 linear_equation[1] = ((CNum3 - CNum1) / CNum2).getIm();
}

void Solution_quadratic_equation(CComplex CNum1, CComplex CNum2, CComplex CNum3, double* quadratic_equation, int& value_quadratic)
{
	CComplex D = CNum2 * CNum2 - 4 * CNum1 * CNum3;

	if (D == CComplex(0, 0))
	{
		quadratic_equation[0] = (-CNum2 / (2 * CNum1)).getRe();
		quadratic_equation[1] = (-CNum2 / (2 * CNum1)).getIm();
		value_quadratic = 1;
	}
	else
	{
		double Re_help = pow(D.Cmodule(), double(1) / 2) * cosinus((D.arg() + 2 * PI * 0) / 2);
		double Im_help = pow(D.Cmodule(), double(1) / 2) * sinus((D.arg() + 2 * PI * 0) / 2);
		CComplex root_discriminant = CComplex(Re_help, Im_help);
		CComplex x1 = (-CNum2 - root_discriminant) / (2 * CNum1);
		CComplex x2 = (-CNum2 + root_discriminant) / (2 * CNum1);
		quadratic_equation[0] = x1.getRe();
		quadratic_equation[1] = x1.getIm();
		quadratic_equation[2] = x2.getRe();
		quadratic_equation[3] = x2.getIm();
		value_quadratic = 2;
	}
}

void Roots_deg_n(CComplex CNum1, int deg, double** Roots_deg_n)
{
	for (int i = 0; i < deg; ++i)
	{
		Roots_deg_n[i][0] = pow(CNum1.Cmodule(), double(1) / deg) * cosinus((CNum1.arg() + 2 * PI * i) / deg);
		Roots_deg_n[i][1] = pow(CNum1.Cmodule(), double(1) / deg) * sinus((CNum1.arg() + 2 * PI * i) / deg);
	}
}

void printSolution(double* equation, int value);
void printSolutionRoot(double** equation, int value);
void record_points_root(double** equation, int value);
void record_points(double* equation, int value);
void critical_case(int Num_of_case);











