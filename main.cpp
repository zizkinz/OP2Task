#include "libai.h"


struct studentas {
    string vard, pavard;
//    float nd[5];
    float ekzam;
    float gal;
};
int main() {
    cout << "Iveskite studentu skaiciu: ";
    int stud_sk;
    cin >> stud_sk;
    cout << "Iveskite namu darbu skaiciu: ";
    int nd_sk;
    cin >> nd_sk;
    studentas grupe[stud_sk];
    for (int i = 0; i < stud_sk; i++) {
        int sum = 0;
        int nd[nd_sk];
        cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:";
        cin >> grupe[i].vard >> grupe[i].pavard;
        for (int j = 0; j < nd_sk; j++) {
            cout << "Iveskite " << j + 1 << " pazymio iverti\n";
//            cin >> grupe[i].nd[j];
//            sum += grupe[i].nd[j];
            cin >> nd[j];
            sum += nd[j];
        }
        cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi:\n";
        cin >> grupe[i].ekzam;

        grupe[i].gal = 0.4 * (static_cast<double>(sum) / nd_sk) + (0.6 * grupe[i].ekzam);
    }


    int max_vard = 7;
    int max_pavard = 6;
    for (auto &kint: grupe) {
        int v = kint.vard.string::length();
        int pv = kint.pavard.string::length();
        if (v > max_vard) { max_vard = v; }
        if (pv > max_pavard) { max_pavard = pv; }
    }


    cout << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde" << setw(11) << left
         << "Galutinis" << endl;
    for (int i = 0; i < (max_vard + max_pavard + 15); i++) { cout << "-"; }
    cout << "\n";
    for (auto &kint: grupe) {
        cout << setw(max_vard + 2) << left << kint.vard << setw(max_pavard + 2) << left << kint.pavard << setw(11)
             << left << kint.gal << endl;
    }
}