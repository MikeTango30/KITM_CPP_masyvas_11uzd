#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream in ("duom.txt");
ofstream out ("rez.txt");

void nuskaitytiDuomenis(int duomenuKiekis, int skaiciuMasyvas[]);
int rastiDidziausia(int duomenuKiekis, int skaiciuMasyvas[]);
int rastiAntraMaziausia(int duomenuKiekis, int skaiciuMasyvas[]);
int rastiAntraDidziausia(int duomenuKiekis, int skaiciuMasyvas[]);
void rastiKeiciamuElementuIndeksus(int duomenuKiekis, int skaiciuMasyvas[], int skaicius, int keiciamiElementai[], int &indeksuKiekis);
void pakeistiAntrusDidziausius(int skaiciuMasyvas[], int indeksuKiekis, int keiciamiElementai[], int sandauga);
void isvestiDuomenis(int duomenuKiekis, int skaiciuMasyvas[], string txt);

int main()
{
    int duomenuKiekis,
        didziausias,
        antrasMaziausias,
        antrasDidziausias,
        indeksuKiekis = 0,
        sandauga;

    cout << "Iveskite norima apdoroti duomenu kieki nuo 3 iki 10 000\n";
    cin >> duomenuKiekis;
    int skaiciuMasyvas[duomenuKiekis],
        keiciamiElementai[duomenuKiekis];

    nuskaitytiDuomenis(duomenuKiekis, skaiciuMasyvas);
    isvestiDuomenis(duomenuKiekis, skaiciuMasyvas, "Pradinis masyvas: ");

    didziausias = rastiDidziausia(duomenuKiekis, skaiciuMasyvas);
    out << "Didziausias masyvo elementas: " << didziausias << "\n";
    antrasMaziausias = rastiAntraMaziausia(duomenuKiekis, skaiciuMasyvas);
    out << "Antras maziausias masyvo elementas: " << antrasMaziausias << "\n";

    antrasDidziausias = rastiAntraDidziausia(duomenuKiekis, skaiciuMasyvas);
    sandauga = didziausias * antrasMaziausias;

    rastiKeiciamuElementuIndeksus(duomenuKiekis, skaiciuMasyvas, antrasDidziausias, keiciamiElementai, indeksuKiekis);
    isvestiDuomenis(indeksuKiekis, keiciamiElementai, "Keiciamu elementu indeksai: ");

    pakeistiAntrusDidziausius(skaiciuMasyvas, indeksuKiekis, keiciamiElementai, sandauga);
    isvestiDuomenis(duomenuKiekis, skaiciuMasyvas, "Pakeistas masyvas: ");

    in.close();
    out.close();

    return 0;
}

void nuskaitytiDuomenis(int duomenuKiekis, int skaiciuMasyvas[])
{
    for (int i = 0; i < duomenuKiekis; i++) {
        in >> skaiciuMasyvas[i];
    }
}

int rastiDidziausia(int duomenuKiekis, int skaiciuMasyvas[])
{
    int did = *max_element(skaiciuMasyvas, skaiciuMasyvas + duomenuKiekis);

    return did;
}

void rastiKeiciamuElementuIndeksus(int duomenuKiekis, int skaiciuMasyvas[], int skaicius, int keiciamiElementai[], int &indeksuKiekis)
{
    for (int i = 0; i < duomenuKiekis; i++){
        if (skaiciuMasyvas[i] == skaicius){
            keiciamiElementai[indeksuKiekis] = i;
            indeksuKiekis++;
        }
    }
}

int rastiAntraMaziausia(int duomenuKiekis, int skaiciuMasyvas[])
{
    int laikinas[duomenuKiekis];
    for (int j = 0; j < duomenuKiekis; j++) {
        laikinas[j] = skaiciuMasyvas[j];
    }

    int min = *min_element(laikinas, laikinas + duomenuKiekis);
    for (int i = 0; i < duomenuKiekis; i++) {
        if (laikinas[i] == min) {
            laikinas[i] = rastiDidziausia(duomenuKiekis, laikinas); //maziausia padarome nemaziausia
        }
    }
    min = *min_element(laikinas, laikinas + duomenuKiekis); //randame antra maziausia

    return min;
}

int rastiAntraDidziausia(int duomenuKiekis, int skaiciuMasyvas[])
{
    int laikinas[duomenuKiekis];
    for (int j = 0; j < duomenuKiekis; j++) {
        laikinas[j] = skaiciuMasyvas[j];
    }

    int did = rastiDidziausia(duomenuKiekis, laikinas);
    for (int i = 0; i < duomenuKiekis; i++) {
        if (laikinas[i] == did) {
            laikinas[i] = *min_element(laikinas, laikinas + duomenuKiekis); //didziausia padarome maziausiu
        }
    }

    did = rastiDidziausia(duomenuKiekis, laikinas); // randame antra didziausia

    return did;
}

void pakeistiAntrusDidziausius(int skaiciuMasyvas[], int indeksuKiekis, int keiciamiElementai[], int sandauga)
{
    for (int i = 0; i < indeksuKiekis; i++) {
        skaiciuMasyvas[keiciamiElementai[i]] = sandauga;
    }
}

void isvestiDuomenis(int duomenuKiekis, int skaiciuMasyvas[], string txt)
{
    out << txt << "\n";
    for (int i = 0; i < duomenuKiekis; i++) {
        out << skaiciuMasyvas[i] << " ";
    }
    out << "\n";
}