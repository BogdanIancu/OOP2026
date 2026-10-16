#include <iostream>
using namespace std;

void functie(int** v)
{
	//...
}

int main()
{
	int* vector = new int[4];
	//...
	delete[] vector;
	vector = nullptr;

	char sir[10];
	strcpy_s(sir, "ceva");
	char* s = new char[strlen(sir) + 1];
	strcpy_s(s, strlen(sir) + 1, sir);
	cout << s << endl;

#if _DEBUG
	// linie de cod ignorata in release mode
#endif

	// shallow copy
	char* t = s;

	// deep copy
	t = new char[strlen(s) + 1];
	strcpy_s(t, strlen(s) + 1, s);

	delete[] s;
	s = nullptr;
	delete[] t;
	t = nullptr;

	string x = sir;
	const char* copy = x.c_str();
	cout << copy << endl;

	int* v = new int[2];
	// transmitere variabila v prin adresa
	functie(&v);
	delete[] v; v = nullptr;

	int** matrice = nullptr;
	// transmitere variabila matrice prin valoare
	functie(matrice);
}