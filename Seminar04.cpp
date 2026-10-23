#include <iostream>
using namespace std;

enum TipBursa { performanta = 1, academica = 3, sociala };

union Evaluare
{
	short nota;
	char calificativ[3];
};

struct Carte
{
	string titlu;
	string autor;
	int nrPagini = 0;
};

class Student
{
private:
	string nume = "Anonim";
public:
	int grupa = 0;

	//Student() {
	//	grupa = 1059;
	//}

	Student(string _nume = "Anonim")
	{
		nume = _nume;
		grupa = 1059;
	}

	~Student()
	{
		cout << "s-a apelat destructorul" << endl;
	}

	void afisare()
	{
		cout << nume << " " << grupa << endl;
	}
};


int main()
{
	TipBursa t = TipBursa::academica;
	cout << t << endl;
	t = (TipBursa)4;

	Evaluare e;
	e.nota = 9;
	e.nota = 65;
	cout << e.nota << endl;
	strcpy_s(e.calificativ, "FB");
	cout << e.calificativ << endl;
	cout << e.nota << endl;
	cout << sizeof(e) << endl;

	Carte c;
	c.titlu = "OOP in C++";
	c.autor = "Bjarne Stroustroup";
	c.nrPagini = 600;
	cout << c.titlu << " " << c.autor << " " << c.nrPagini << endl;

	Student s1;
	s1.grupa = 1062;
	s1.afisare();
	Student s2("Ion");
	s2.afisare();
	Student* ps = new Student();
	(*ps).grupa = 1063;
	ps->afisare();
	delete ps;
	ps = nullptr;
	cout << "main ended" << endl;
}