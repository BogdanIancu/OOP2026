#include <iostream>
using namespace std;

class Vacanta
{
private:
	string destinatie;
	string cazare;
	int numarNopti = 0;
	float pretDeBaza = 0;
	float* preturiServiciiExtra = nullptr;
	int nrServiciiExtra = 0;
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

	Vacanta(int idRezervare, const float* preturiServicii, int nrServicii) :idRezervare(idRezervare)
	{
		if (preturiServicii != nullptr && nrServicii > 0)
		{
			this->nrServiciiExtra = nrServicii;
			this->preturiServiciiExtra = new float[nrServicii];
			for (int i = 0; i < nrServicii; i++)
			{
				this->preturiServiciiExtra[i] = preturiServicii[i];
			}
		}

	}

	Vacanta(const Vacanta& v) : idRezervare(v.idRezervare) {
		this->destinatie = v.destinatie;
		this->cazare = v.cazare;
		this->numarNopti = v.numarNopti;
		this->pretDeBaza = v.pretDeBaza;
		if (v.preturiServiciiExtra != nullptr && v.nrServiciiExtra > 0)
		{
			this->nrServiciiExtra = v.nrServiciiExtra;
			this->preturiServiciiExtra = new float[v.nrServiciiExtra];
			for (int i = 0; i < v.nrServiciiExtra; i++)
			{
				this->preturiServiciiExtra[i] = v.preturiServiciiExtra[i];
			}
		}
	}

	~Vacanta()
	{
		delete[] preturiServiciiExtra;
	}

	Vacanta& operator=(const Vacanta& v)
	{
		if (this != &v)
		{
			delete[] this->preturiServiciiExtra;

			this->destinatie = v.destinatie;
			this->cazare = v.cazare;
			this->numarNopti = v.numarNopti;
			this->pretDeBaza = v.pretDeBaza;
			if (v.preturiServiciiExtra != nullptr && v.nrServiciiExtra > 0)
			{
				this->nrServiciiExtra = v.nrServiciiExtra;
				this->preturiServiciiExtra = new float[v.nrServiciiExtra];
				for (int i = 0; i < v.nrServiciiExtra; i++)
				{
					this->preturiServiciiExtra[i] = v.preturiServiciiExtra[i];
				}
			}
			else
			{
				this->nrServiciiExtra = 0;
				this->preturiServiciiExtra = nullptr;
			}
		}
		return *this;
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

	float getPretDeBaza() const
	{
		return pretDeBaza;
	}

	int getNrServiciiExtra()
	{
		return nrServiciiExtra;
	}

	float* getPreturiServiciiExtra()
	{
		if (preturiServiciiExtra != nullptr)
		{
			float* copie = new float[nrServiciiExtra];
			for (int i = 0; i < nrServiciiExtra; i++)
			{
				copie[i] = preturiServiciiExtra[i];
			}
			return copie;
		}
		return nullptr;
	}

	float getPreturiServiciiExtra(int index)
	{
		if (index >= 0 && index < nrServiciiExtra && preturiServiciiExtra != nullptr)
			return preturiServiciiExtra[index];
		else return 0;
	}

	void setPreturiServiciiExtra(const float* servicii, int nr)
	{
		if (servicii != nullptr && nr > 0)
		{
			delete[]preturiServiciiExtra;
			this->nrServiciiExtra = nr;
			this->preturiServiciiExtra = new float[nr];
			for (int i = 0; i < nr; i++)
			{
				this->preturiServiciiExtra[i] = servicii[i];
			}
		}
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
	cout << endl;

	float vector[]{ 4,5,6 };
	Vacanta v5(23, vector, 3);
	vector[0] = 99;
	int nr = v5.getNrServiciiExtra();
	float* preturi = v5.getPreturiServiciiExtra();
	for (int i = 0; i < nr; i++)
	{
		cout << preturi[i] << " ";

	}
	cout << endl;
	delete[] preturi;
	preturi = nullptr;
	cout << v5.getPreturiServiciiExtra(1) << endl;
	v2.setPreturiServiciiExtra(vector, 3);
	for (int i = 0; i < v2.getNrServiciiExtra(); i++)
	{
		cout << v2.getPreturiServiciiExtra(i) << " ";
	}
	cout << endl;

	Vacanta v6(v5);
	Vacanta v7 = v5;
	v1 = v2 = v5;
}