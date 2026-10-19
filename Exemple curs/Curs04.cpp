#include <iostream>
#include <string>
using namespace std;

union Eticheta
{
	short v1;
	int v2;
	long long v3;
};

struct Carte
{
	int numarPagini;
	float pret;
	char* denumire;
	char* autor;
};

class Drona
{
private:
	string model;
	float nivelBaterie = 0;
protected:
	string producator;
public:
	float altitudine = 0;

	Drona()
	{
		model = "N/A";
		producator = "N/A";
		nivelBaterie = 1;
	}

	Drona(string _producator, string _model)
	{
		producator = _producator;
		model = _model;
		nivelBaterie = 1;
	}


	void urca(float metri)
	{
		altitudine += metri;
	}
};

int main()
{
	Eticheta eticheta;
	eticheta.v3 = 9999999;
	printf("%lld\n", eticheta.v3);
	printf("%d\n", eticheta.v1); 
	printf("%ld\n", eticheta.v2);
	eticheta.v2 = 7;
	printf("%lld\n", eticheta.v3);
	printf("%d\n", eticheta.v1);
	printf("%ld\n", eticheta.v2);
	cout << sizeof(eticheta) << endl;

	Carte carte{ 100, 0, nullptr, nullptr };
	carte.numarPagini = 200; 
	carte.pret = 99.99f;
	carte.denumire = new char[strlen("Razboiul lumilor") + 1];
	strcpy_s(carte.denumire, strlen("Razboiul lumilor") + 1,
		"Razboiul lumilor");
	printf("%s", carte.denumire);
	cout << endl;

	Drona dronaFilmare("DJI", "Mavic 3");
	Drona dronaLivrare;

	dronaFilmare.altitudine = 20;
	dronaFilmare.urca(50);
	cout << dronaFilmare.altitudine << endl;
	//dronaFilmare.nivelBaterie = 70;

	Drona* pDronaHobby = new Drona();
	(*pDronaHobby).urca(30);
	cout << pDronaHobby->altitudine << endl;
	delete pDronaHobby;

	Drona* pDronaLivrare = new Drona("Wingcopter", "198");
	//...
	delete pDronaLivrare;
}