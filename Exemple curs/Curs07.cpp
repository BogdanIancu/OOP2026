#include <iostream>
#include <string>
using namespace std;

class Drona;

class Drona
{
private:
	const int autonomieMaxima;
	string model;
	float nivelBaterie = 0;
	int* durataZilnicaZbor = nullptr;
	int nrZile = 0;

protected:
	string producator;
public:
	float altitudine = 0;
	static float altitudineMaxima;

	//Drona()
	//{
	//	model = "N/A";
	//	producator = "N/A";
	//	nivelBaterie = 1;
	//}

	Drona(string _producator = "N/A", string _model = "N/A") :
		autonomieMaxima(25)
	{
		this->producator = _producator;
		this->model = _model;
		nivelBaterie = 1;
	}

	Drona(int nivelBaterie, int autonomieInMinute) :
		autonomieMaxima(autonomieInMinute)
	{
		this->nivelBaterie = nivelBaterie;
		model = "N/A";
		producator = "N/A";
	}

	Drona(const int* durataZilnicaZbor, int nrZile) :
		autonomieMaxima(25)
	{
		if (nrZile > 0 or durataZilnicaZbor != nullptr)
		{
			this->nrZile = nrZile;
			this->durataZilnicaZbor = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaZbor[i] = 
					durataZilnicaZbor[i];
			}
		}
	}

	Drona(const Drona& drona) :
		autonomieMaxima(drona.autonomieMaxima)
	{
		producator = drona.producator;
		model = drona.model;
		nivelBaterie = drona.nivelBaterie;
		altitudine = drona.altitudine;

		if (drona.nrZile > 0 && drona.durataZilnicaZbor != nullptr)
		{
			this->nrZile = drona.nrZile;
			this->durataZilnicaZbor = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				this->durataZilnicaZbor[i] =
					drona.durataZilnicaZbor[i];
			}
		}
	}

	Drona& operator=(const Drona& drona)
	{
		if (this != &drona)
		{
			delete[] durataZilnicaZbor;
		
			producator = drona.producator;
			model = drona.model;
			nivelBaterie = drona.nivelBaterie;
			altitudine = drona.altitudine;

			if (drona.nrZile > 0 && drona.durataZilnicaZbor != nullptr)
			{
				this->nrZile = drona.nrZile;
				this->durataZilnicaZbor = new int[nrZile];
				for (int i = 0; i < nrZile; i++)
				{
					this->durataZilnicaZbor[i] =
						drona.durataZilnicaZbor[i];
				}
			}
			else
			{
				this->durataZilnicaZbor = nullptr;
				this->nrZile = 0;
			}
		}
		return *this;
	}


	~Drona()
	{
		delete[] durataZilnicaZbor;
		durataZilnicaZbor = nullptr;
	}

	string getModel() const
	{
		return model;
	}

	void setModel(string model)
	{
		if (model.length() > 1)
		{
			this->model = model;
		}
	}

	int getNrZile() const
	{
		return this->nrZile;
	}

	int* getDurataZilnicaZbor() const
	{
		if (durataZilnicaZbor != nullptr)
		{
			int* copie = new int[nrZile];
			for (int i = 0; i < nrZile; i++)
			{
				copie[i] = durataZilnicaZbor[i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getDurataZilnicaZbor(int index) const
	{
		if (index >= 0 && index < nrZile && durataZilnicaZbor != nullptr)
		{
			return durataZilnicaZbor[index];
		}
		else return -1;
	}


	static float nivelMediuBaterie(Drona* drone, int nrDrone)
	{
		if (drone == nullptr || nrDrone <= 0)
		{
			return 0;
		}

		float suma = 0;

		for (int i = 0; i < nrDrone; i++)
		{
			suma += drone[i].nivelBaterie;
		}
		return suma / nrDrone;
	}

	Drona& operator++()
	{
		this->nivelBaterie++;
		return *this;
	}

	Drona operator++(int)
	{
		Drona copie = *this;
		this->nivelBaterie++;
		return copie;
	}

	Drona operator+(const Drona& d)
	{
		Drona copie = *this;
		copie.nivelBaterie = nivelBaterie + d.nivelBaterie;
		return copie;
	}


	void urca(float metri);
};
float Drona::altitudineMaxima = 120;

void Drona::urca(float metri)
{
	altitudine += metri;
}

Drona ridicaCuUnMetru(Drona drona)
{
	drona.altitudine++;
	return drona;
}

class Pilot
{
	Drona drona;
};

int main()
{
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
	pDronaHobby = nullptr;

	Drona* pDronaLivrare = new Drona("Wingcopter", "198");
	//...
	delete pDronaLivrare;
	pDronaLivrare = nullptr;

	Drona altaDrona("Parrot");
	altaDrona.setModel("Anafi");
	cout << altaDrona.getModel() << endl;
	Drona dronaAgricola(50, 40);

	Drona dronaMilitara(dronaAgricola);
	Drona dronaRezerva = dronaAgricola;
	dronaRezerva.altitudine = 100;
	Drona dronaRezerva2 = ridicaCuUnMetru(dronaRezerva);

	cout << Drona::altitudineMaxima << endl;
	dronaRezerva2.altitudineMaxima = 150;
	cout << Drona::altitudineMaxima << endl;

	Drona drone[]{ dronaFilmare, dronaLivrare };
	cout << Drona::nivelMediuBaterie(drone, 2) << endl;

	int durateZbor[]{ 1, 2, 1 };
	Drona drona2(durateZbor, 3);
	durateZbor[0] = -5;

	const int* durate = drona2.getDurataZilnicaZbor();
	int* pointer = (int*)durate;
	pointer[0] = -10;

	delete[] pointer;
	pointer = nullptr;

	for (int i = 0; i < drona2.getNrZile(); i++)
	{
		cout << drona2.getDurataZilnicaZbor(i) << " ";
	}
	cout << endl;
	Drona drona3(drona2);
	Drona drona4 = drona2;
	Drona drona5;
	dronaLivrare = drona2;
	drona5.operator=(dronaLivrare.operator=(drona2));

	drona5 = ++drona4; //drona4.operator++()
	drona3 = drona2++;

	drona4 = drona2 + drona5;

	cout << "sfarsit main" << endl;
}