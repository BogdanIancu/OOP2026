#include <iostream>
using namespace std;

class Vacanta
{
private:
	string destinatie;
	string cazare;
	int numarNopti = 0;
	float pret = 0;
	const int idRezervare;
	static string sezon;
public:
	Vacanta() : idRezervare(0)
	{
		destinatie = "N/A";
		cazare = "N/A";
	}

	Vacanta(int idRezervare, string destinatie, string cazare) : idRezervare(idRezervare)
	{
		this->destinatie = destinatie;
		this->cazare = cazare;
	}

	Vacanta(const Vacanta& v) : idRezervare(v.idRezervare) {
		this->destinatie = v.destinatie;
		this->cazare = v.cazare;
		this->numarNopti = v.numarNopti;
		this->pret = v.pret;
	}

	int getNumarNopti()
	{
		return numarNopti;
	}

	void setNumarNopti(int numarNopti)
	{
		if (numarNopti > 0 && numarNopti < 30)
		{
			this->numarNopti = numarNopti;
		}
	}

	float getPret() const
	{
		return pret;
	}

	static string getSezon()
	{
		return sezon;
	}

	static void setSezon(string sezon)
	{
		Vacanta::sezon = sezon;
	}

	static int calculNrTotalNoptiCazare(Vacanta* vacante, int nrVacante)
	{
		int sum = 0;
		if (vacante != nullptr && nrVacante > 0)
		{
			for (int i = 0; i <= nrVacante - 1; i++)
			{
				sum = sum + vacante[i].numarNopti;
			}
		}
		return sum;
	}
};
string Vacanta::sezon = "Iarna 2026";

int main()
{
	Vacanta v1;
	Vacanta v2(2, "Roma", "Hotel Intercontinental");
	Vacanta v3(v2);
	Vacanta v4 = v2;
	v4.setNumarNopti(4);
	cout << v4.getNumarNopti() << endl;
	cout << Vacanta::getSezon() << endl;
	v1.setSezon("Vara 2027");
	cout << v2.getSezon() << endl;
	Vacanta vacante[]{ v1, v2, v4 };
	cout << Vacanta::calculNrTotalNoptiCazare(vacante, 3);
}