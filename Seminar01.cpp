#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";

    char c = -10;
    cout << c << endl;
    printf("%d\n", c);

    c += 140;
    printf("%d\n", c);

    unsigned short x = 200;
    cout << sizeof(x) << endl;

    int y = -500;
    cout << sizeof(y) << endl;

    long long z = 123;
    cout << sizeof(z) << endl;

    bool ok = true;
    cout << sizeof(ok) << endl;

    if (x == 100)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "Not OK" << endl;
    }

    float a = 8.4;
    cout << sizeof(a) << endl;

    double b = 8.4;
    cout << sizeof(b) << endl;

    if (fabs(a-b) < 0.01)
    {
        cout << "Sunt egale" << endl;
    }
    else
    {
        cout << "Nu sunt egale" << endl;
    }
}
