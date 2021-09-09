#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas {
    string vard, pavard;
    float nd[10]{};
    float ekzam;
    float gal;
};


void pild(studentas &kint);
void printas(studentas &kin);


int main()
{

    studentas st1;
    studentas st2{ "Vardas2","Pavarde2",{5,8,7,4,5,8,9,5,4},9, 0};
    //pild(st1);
    //printas(st1);
    studentas studentai[10];
    for (int i = 0; i < 2; i++)
        pild(studentai[i]);
    for (int i = 0; i < 2; i++)
        printas(studentai[i]);

}

void pild(studentas& kint) {
    int n;
    cout << "Iveskite studento varda ir pavarde: "; cin >> kint.vard >> kint.pavard;
    cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
    cout << "Iveskite pazymius:" << endl;
    float sum = 0, vid = 0;
    for (int i = 0; i < n; i++) {
        cin >> kint.nd[i];
        sum += kint.nd[i];
    }
    vid = sum / n;
    cout << "Iveskite egzamino pazymi:"; cin >> kint.ekzam;
    kint.gal = vid * 0.4 + kint.ekzam;
}

void printas(studentas& kin) {
    cout << kin.vard << " " << kin.pavard<<" ";
    for (int i = 0; i < sizeof(kin.nd) / sizeof(kin.nd[0]); i++)
        cout << kin.nd[i] << " ";
    cout << "Egzaminas = " << kin.ekzam << "; Galutinis: " << kin.gal<<endl;
}

