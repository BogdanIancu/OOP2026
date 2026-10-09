#include <iostream>
using namespace std;

void increment()
{
	static int x = 0;
	x++;
	cout << x << endl;
}

int main()
{
	int b = 2;
	int c = 0;

	if (c != 0)
	{
		cout << b / c;
	}

	increment();
	increment();

	short* pointer = nullptr;
	short x = 100;
	pointer = &x;
	cout << pointer << endl;
	cout << *pointer << endl;

	cout << ++pointer << endl;
	cout << --pointer << endl;

	short* q = pointer + 2;
	cout << q << endl;
	cout << q - pointer << endl;

	short* const pc = pointer;
	//pc = nullptr;
	*pointer = 12;
	cout << x << endl;

	const short* psc = pointer;
	//*psc = 20;
	psc = nullptr;

	short& r = x;
	cout << r << endl;

	void* p = pointer;
	cout << *(short*)p << endl;

	short* v = new short[3];
	*v = 123;
	cout << v[0] << endl;
	delete[] v;
	v = nullptr;
}