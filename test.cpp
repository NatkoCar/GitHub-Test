#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void removeSpecialCharacters(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
        {
            if (s[i] != ' ')
            {
                s.erase(i, 1);
                i--;
            }
        }
    }
}

int main()
{
    int n, br = 0;
    double prosjek[101];
    string prezimeIme[101];
    string linija;
    fstream datoteka;
    datoteka.open("C:\\Users\\Ga-gama\\Documents\\GitHub\\GitHub-Test\\imenik.bin", ios::binary | ios::out);
    while (getline(datoteka, linija))
    {
        cout << linija << endl;
        prosjek[br] = stoi(linija);
        removeSpecialCharacters(linija);
        prezimeIme[br] = linija;
        br++;
    }
    datoteka.close();
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cin >> prosjek[i + br];
        cin.ignore();
        getline(cin, prezimeIme[i + br]);
    }
    for (int i = 0; i < n + br; i++)
    {
        for (int j = i + 1; j < n + br; j++)
        {
            if (prosjek[i] > prosjek[j])
            {
                swap(prosjek[i], prosjek[j]);
                swap(prezimeIme[i], prezimeIme[j]);
            }
        }
    }
    datoteka.open("C:\\Users\\Ga-gama\\Documents\\GitHub\\GitHub-Test\\imenik.bin", ios::binary | ios::in);
    for (int i = 0; i < n + br; i++)
    {
        datoteka << prosjek[i];
        datoteka << prezimeIme[i];
        datoteka << endl;
    }
    datoteka.close();
    return 0;
}