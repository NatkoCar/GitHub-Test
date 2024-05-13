#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int br_uc;
    cin >> br_uc;
    cin.ignore();
    string prezimeIme[101];
    double prosjek[101];
    for (int i = 0; i < br_uc; i++)
    {
        cin >> prosjek[i];
        cin.ignore();
        getline(cin, prezimeIme[i]);
    }
    for (int i = 0; i < br_uc; i++)
    {
        for (int j = i + 1; j < br_uc; j++)
        {
            if (prosjek[i] < prosjek[j])
            {
                swap(prosjek[i], prosjek[j]);
                swap(prezimeIme[i], prezimeIme[j]);
            }
        }
    }
    fstream datotekaOut("D:\\DOWNLOAD\\VS_Code\\GitHub-Test\\imenik.bin", ios::binary | ios::out);
    for (int i = 0; i < br_uc; i++)
    {
        datotekaOut.write((char *)&prosjek[i], sizeof(double));
        int len = prezimeIme[i].size();
        datotekaOut.write((char *)&len, sizeof(int));
        datotekaOut.write((char *)&prezimeIme[i], sizeof(string));
    }
    datotekaOut.close();
    fstream datotekaIn("D:\\DOWNLOAD\\VS_Code\\GitHub-Test\\imenik.bin", ios::binary | ios::in);
    for (int i = 0; i < br_uc; i++)
    {
        string prezime_ime;
        double prosjek;
        datotekaIn.read((char *)&prosjek, sizeof(double));
        int len;
        datotekaIn.read((char *)&len, sizeof(int));
        char *buffer = new char[len + 1];
        datotekaIn.read(buffer, len);
        buffer[len] = '\0';
        prezime_ime = buffer;
        delete[] buffer;
        cout << prezime_ime << " " << prosjek << endl;
    }
    datotekaIn.close();
    return 0;
}