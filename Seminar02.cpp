#include <iostream>
using namespace std;

int main()
{
    int* p = nullptr;
    int x = 10;
    p = &x;
    cout << p << endl;
    cout << *p << endl;
    cout << *&x << endl;

    void* t = p;
    cout << *(int*)t << endl;

    int& r = x;
    x++;
    cout << r << endl;

    int* q = ++p;
    cout << q << endl;
    int* u = p + 3;
    cout << u << endl;
    cout << u - p << endl;

    int dim = 3;
    int v[3] = { 10,20,30 };
    cout << v << endl;
    cout << v[2] << endl;
    cout << *(v + 2) << endl;
    cout << sizeof(v) / sizeof(int) << endl;

    int* w = (int*)malloc(dim * sizeof(int));
    w[2] = 99;
    cout << w[2] << endl;
    free(w);
    w = nullptr;

    int* z = new int[dim];
    z[2] = 98;
    cout << *(z + 2) << endl;
    delete[] z;
    z = nullptr;
}