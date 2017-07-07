#include <iostream>
#include <cstdlib>
using namespace std;

class Weather
{
	int days;
	double high[31], low[31], rain[31], snow[31];
	public:
	Weather();
	void accept();
	void display();
	void average();
};

Weather :: Weather()
{
	days = 0;
	for(int i=0; i<31; i++)
		high[i] = low[i] = rain[i] = snow[i] = 0;
}

void Weather :: accept()
{
	cout << "Enter days of month:\n";
	cin >> days;
	for(int i=0; i<days; i++)
	{
		cout << "Enter highest & lowest temperature of day " << i+1 << endl;
		cin >> high[i] >> low[i];
		cout << "Enter rainfall & snowfall of day " << i+1 << endl;
		cin >> rain[i] >> snow[i];
	}
}

void Weather :: display()
{
	cout << "Day\thigh\tlow\train\tsnow\n";
	for(int i=0; i<days; i++)
		cout << i+1 << "\t" << high[i] << "\t" << low[i] << "\t" << rain[i] << "\t" << snow[i] << endl;
}

void Weather :: average()
{
	Weather a;
	cout << "Average report of month\n";
	for(int i=0; i<days; i++)
	{
		a.high[0] += high[i];
		a.low[0] += low[i];
		a.rain[0] += rain[i];
		a.snow[0] += snow[i];
	}
	cout << "Avg high temp = " << a.high[0]/days << "\nAvg low temp = " << a.low[0]/days << "\nAvg rainfall = " << a.rain[0] << "\nAvg snow = " << a.snow[0]/days << endl;
}

int main()
{
	Weather wr[12];
	int choice, m;
	
	while(1)
	{
		cout << "\n1. Accept month data\n2. Monthly Avg Report\n3. End\n";
		cin >> choice;
		switch(choice)
		{
			case 1: cout << "\nEnter month number: ";
			cin >> m;
			wr[m-1].accept();
			wr[m-1].display();
			break;
			case 2: cout << "\nEnter month number: ";
			cin >> m;
			wr[m-1].average();
			break;
			case 3: exit(0);
			default: cout << "Wrong choice\n";
		}
	}	
	return 0;
}















