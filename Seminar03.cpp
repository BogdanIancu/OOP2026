#include <iostream> 
using namespace std;

void afisare(int** matrice, int nrLinii, int nrColoane)
{
    if (matrice != nullptr && nrLinii > 0 && nrColoane > 0)
    {
        for (int i = 0; i < nrLinii; i++)
        {
            for (int j = 0; j < nrColoane; j++)
            {
                cout << matrice[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void interschimba(int& x, int& y)
{
    int aux = x;
    x = y;
    y = aux;
}

void interschimba2(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    char s[20];
    strcpy_s(s, "Maria");
    cout << s << endl;

    cout << strlen(s) << endl;

    s[5] = '!';
    s[6] = '\0';

    cout << s << endl;

    char* copie = new char[strlen(s) + 1];
    strcpy_s(copie, strlen(s) + 1, s);
    cout << copie << endl;
    delete[] copie;
    copie = nullptr;

    string sir = "Ion";
    cout << sir << endl;
    cout << sir.length() << endl;
    string altSir = "Dl. " + sir;
    cout << altSir << endl;
    altSir = s;
    const char* t = altSir.c_str();

    int m[2][3] = { {1, 2, 3}, {4, 5, 6} };
    cout << sizeof(m) / sizeof(m[0]) << endl;
    cout << sizeof(m[0]) / sizeof(m[0][0]) << endl;
    cout << *(*(m + 1) + 2) << endl;

    int nrLinii = 2;
    int nrColoane = 3;
    int** w = new int* [nrLinii];
    for (int i = 0; i < nrLinii; i++)
    {
        w[i] = new int[nrColoane];
    }


    for (int i = 0; i < nrLinii; i++)
    {
        for (int j = 0; j < nrColoane; j++)
        {
            w[i][j] = 1;
        }
    }
    afisare(w, nrLinii, nrColoane);
    cout << endl;

    int a = 3, b = 21;
    interschimba(a, b);
    cout << a << " " << b << endl;
    interschimba2(&a, &b);
    cout << a << " " << b << endl;

    for (int i = 0; i < nrLinii; i++)
    {
        delete[] w[i];
    }
    delete[] w;
    w = nullptr;
}