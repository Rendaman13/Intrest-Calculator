#include <iostream>
#include <math.h>
#include <string>
float simple(float, float, float);
float compound(float, float, float);
using namespace std;
int main()
{
	bool repeat = true;
	while (repeat)
	{
	cout << "Intrest Calculator" << endl;
	cout << "Dollar amount: ";
	float amount;
	cin >> amount;
	cout << "Years: ";
	float yrs;
	cin >> yrs;
        while (yrs < 0)
	{
		cout << "Year amount cannot be less than zero. ";
		cin >> yrs;
	}
	yrs = floor(yrs * 1 + 0.5) / 1;
	cout << "Intrest rate: ";
	float rate;
	cin >> rate;
	rate = rate / 100;
	cout << "Simple or compound intrest? [s/c] ";
	string intresttype;
	cin >> intresttype;
	float total;
	string intresttypeword;
	while (intresttype != "s" & intresttype != "S" & intresttype != "c" & intresttype != "C")
	{
		cout << "Please enter \"s\" or \"c\" ";
		cin >> intresttype;
	}
	if (intresttype == "s" | intresttype == "S")
	{
		total = simple(amount, yrs, rate);
		intresttypeword = "simple";
	}
	else if (intresttype == "c" | intresttype == "C")
	{
		total = compound(amount, yrs, rate);
		intresttypeword = "compound";
	}
	cout << "With " << intresttypeword << " intrest at " << yrs << " year(s), your total comes to $" << total << endl;
	cout << "Repeat? [y/n] ";
	string repeatyesorno;
	cin >> repeatyesorno;
	if (repeatyesorno != "y" & repeatyesorno != "Y")
	{
		repeat = false;
	}
	}
	return 0;
}
float simple(float x, float y, float z)
{
	float endresult = (x*y*z) + x;
	endresult = floor(endresult * 100 + 0.5) / 100;
	return endresult;
}
float compound(float x, float y, float z)
{
	for (int i = 0; i != y; ++i)
	{
		x = (x*z) + x;
		x = floor(x * 100 + 0.5) / 100;
	}
	return x;
}
