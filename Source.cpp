#include<iostream> 
#include<cmath> 
#include<iomanip> 
using namespace std;
const auto PI = 3.141592653589793238462643383279;
const double esp = 0.0000000001;
int n = 1;
double function1(double x)
{
	return asin(sqrt(x)) / sqrt(x * (1 - x));
}
double function2(double x)
{
	return x * x * x * exp(2 * x);
}
double function3(double x)
{
	return pow(tan(x / 2 + PI / 4), 3);
}
double integral_square(double a, double b, double(*func)(double x))
{
	if (a == b) return 0.0;
	else
	{
		long double integral_1 = 0, integral_2, step;
		step = (a - b) / n;
		integral_2 = step * func(b);
		do
		{
			integral_1 = integral_2;
			n *= 2;
			step = (a - b) / n;
			integral_2 = 0;
			for (double x = b; x <= a; x += step)
			{
				integral_2 += step * func(x);
			}
		} while (abs(integral_2 - integral_1) > esp);
		return integral_2;
	}
}
double integral_simpson(double a, double b, double(*func)(double x))
{
	if (a == b) return 0.0;
	else
	{
		long double integral_1 = 0, integral_2, step;
		step = (a - b) / (2 * n);
		integral_2 = step * func(b) / 3;
		do
		{
			integral_1 = integral_2;
			n *= 2;
			step = (a - b) / (2 * n);
			integral_2 = func(a) + func(b);
			for (double x = b; x <= a; x += step)
			{
				if ((int)((a - x) / step) % 2 == 0)
				{
					integral_2 += 2 * func(x);
				}
				if ((int)((a - x) / step) % 2 != 0)
				{
					integral_2 += 4 * func(x);
				}
			}
			integral_2 = integral_2 * step / 3;
		} while (abs(integral_2 - integral_1) > esp);
		return integral_2;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	double a, b;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
	}
	cout<< setprecision(6) << integral_square(a, b, function1) << endl;
	cout << setprecision(6) << integral_simpson(a, b, function1) << endl;
	cin >> a >> b;
	if (a < b)
	{
		swap(a, b);
	}
	cout << setprecision(6) << integral_square(a, b, function2) << endl;
	cout << setprecision(6) << integral_simpson(a, b, function2) << endl;
	system("pause");
	return 0;

}