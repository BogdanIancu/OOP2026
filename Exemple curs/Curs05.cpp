#include <iostream>
#include <string>
using namespace std;

class Drona
{
private:
	string model;
	float nivelBaterie = 0;
protected:
	string producator;
public:
	float altitudine = 0;

	//Drona()
	//{
	//	model = "N/A";
	//	producator = "N/A";
	//	nivelBaterie = 1;
	//}

	Drona(string _producator = "N/A", string _model="N/A")
	{
		this->producator = _producator;
		this->model = _model;
		nivelBaterie = 1;
	}

	Drona(int nivelBaterie)
	{
		this->nivelBaterie = nivelBaterie;
		model = "N/A";
		producator = "N/A";
	}

	Drona(const Drona& drona)
	{
		producator = drona.producator;
		model = drona.model;
		nivelBaterie = drona.nivelBaterie;
		altitudine = drona.altitudine;
	}

	~Drona()
	{
		cout << "S-a apelat destructorul" << endl;
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


	void urca(float metri);
};

void Drona::urca(float metri)
{
	altitudine += metri;
}

Drona ridicaCuUnMetru(Drona drona)
{
	drona.altitudine++;
	return drona;
}

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
	Drona dronaAgricola = 50;

	Drona dronaMilitara(dronaAgricola);
	Drona dronaRezerva = dronaAgricola;
	dronaRezerva.altitudine = 100;
	Drona dronaRezerva2 = ridicaCuUnMetru(dronaRezerva);
	cout << "sfarsit main" << endl;
}