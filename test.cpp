#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

struct Ucenik
{
    char imePrezime[50];
    float prosjek;
};

bool cmp(Ucenik &a, Ucenik &b)
{
    return a.prosjek > b.prosjek;
}

int main()
{
    struct Ucenik ucenici[100];
    int brUcenika = 0;
    fstream datoteka1("C:\\Users\\Ga-gama\\Documents\\GitHub\\GitHub-Test\\imenik.bin", ios::binary | ios::in);
    while (datoteka1.read((char *)&ucenici[brUcenika], sizeof(Ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    datoteka1.close();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(ucenici[brUcenika + i].imePrezime, 50);
        cin >> ucenici[brUcenika + i].prosjek;
    }
    sort(ucenici, ucenici + brUcenika + n, cmp);
    fstream datoteka2("C:\\Users\\Ga-gama\\Documents\\GitHub\\GitHub-Test\\imenik.bin", ios::binary | ios::out | ios::trunc);
    datoteka2.write((char *)ucenici, sizeof(Ucenik) * (brUcenika + n));
    datoteka2.close();
    return 0;
}