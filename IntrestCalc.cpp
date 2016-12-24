#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
float simple(float, float, float);
float compound(float, float, float);
using namespace std;
int main()
{
	cout << "Intrest Calculator" << endl;
	cout << "Dollar amount: ";
	float amount;
	cin >> amount;
	cout << "Years: ";
	float yrs;
	cin >> yrs;
	if (yrs < 0)
	{
		cout << "Year amount cannot be less than zero." << endl;
		system("pause");
		exit(EXIT_FAILURE);
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
	else
	{
		cout << "Invalid intrest type. Valid intrest types include \"s\" or \"c\"" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	cout << "With " << intresttypeword << " intrest at " << yrs << " years, your total comes to $" << total << endl;
	system("pause");
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