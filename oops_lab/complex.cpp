#include <iostream>

using namespace std;

class complex
{
double real, img;
public:
	complex(){}
	complex(double x, double y)
	{real = x; img = y;}
	void accept();
	friend complex operator+(complex, complex);
	friend complex operator-(complex, complex);
	friend complex operator*(complex, complex);
	friend complex operator/(complex, complex);
	void display();
};

void complex :: accept()
{
	cout << "\nEnter the real part: ";
	cin >> real;
	cout << "\nEnter the imaginary part: ";
	cin >> img;
}

complex operator+(complex a, complex b)
{
	complex temp;
	temp.real = a.real + b.real;
	temp.img = a.img + b.img;
	return temp;
}

complex operator-(complex a, complex b)
{
	complex temp;
	temp.real = a.real - b.real;
	temp.img = a.img - b.img;
	return temp;
}

complex operator*(complex a, complex b)
{
	complex temp;
	temp.real = (a.real * b.real) - (a.img * b.img);
	temp.img = (a.real * b.img) + (a.img * b.real);
	return temp;
}

complex operator/(complex a, complex b)
{
	complex temp;
	temp.real = (a.real * b.real) + (a.img * b.img);
	temp.img = (a.real * (-1*b.img)) + (a.img * b.real);
	double d = (a.real*a.real) + (a.img*a.img);
	temp.real /= d;
	temp.img /= d;
	return temp;
}

void complex :: display()
{
	cout << real << " + " << img << "i" << endl;
}
int main()
{
	complex c1, c2, c3, c4, c5, c6;
	int ch;
	c1.accept();
	c2.accept();
while(1)
{
	cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n";	
	cout << "\nEnter choice: ";
	cin >> ch;
	switch(ch)
	{
		case 1: c3 = c1 + c2;
		c3.display();
		break;
		
		case 2: c3 = c1 - c2;
		c3.display();
		break;
		
		case 3: c3 = c1 * c2;
		c3.display();
		break;
		
		case 4: c3 = c1 / c2;
		c3.display();
		break;
		
		case 5: return(0);
		default: cout << "Wrong choice\n";
	}
	
}
}