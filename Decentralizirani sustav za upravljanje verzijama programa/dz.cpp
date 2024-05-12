#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int brUcenika, n;

    cout << "Unesite broj ucenika: ";
    cin >> brUcenika;
    cin.ignore();

    string imena_i_prezimena[100];
    double prosjeci[100];

    for (int i = 0; i < brUcenika; i++)
    {
        cout << "Unesite prosjek " << i + 1 << ".ucenike: ";
        cin >> prosjeci[i];
        cin.ignore();
        cout << "Unesite ime i prezime " << i + 1 << ".ucenika: ";
        getline(cin, imena_i_prezimena[i]);
    }

    for (int i = 0; i < brUcenika-1; i++)
    {
        for (int j = i+1; j < brUcenika; j++)
        {
            if(prosjeci[i] < prosjeci[j])
            {
                swap(prosjeci[i], prosjeci[j]);
                swap(imena_i_prezimena[i], imena_i_prezimena[j]);
            }
        }
        
    }

    fstream datotekaOut("ucenici.bin", ios::binary | ios::out);
    for (int i = 0; i < brUcenika; i++)
    {
        datotekaOut.write((char *)&prosjeci[i], sizeof(double));
        datotekaOut.write((char *)&imena_i_prezimena[i], sizeof(string));
    }
    datotekaOut.close();

    fstream datotekaIn("ucenici.bin", ios::binary | ios::in);
    for (int i = 0; i < brUcenika; i++)
    {
        string imena_i_prezimena;
        double prosjeci;
        datotekaIn.read((char *)&prosjeci, sizeof(double));
        datotekaIn.read((char *)&imena_i_prezimena, sizeof(string));
        cout << imena_i_prezimena << " " << prosjeci << endl;
    }
    datotekaIn.close();
    return 0;
}
