#include "printas.h"
void print_stud(vector<studentas> &grupe, bool pr) {
    int max_vard = 6;
    int max_pavard = 7;
    int max_nd = 0;
    for (auto &kint: grupe) {
        int v = kint.vard.string::length();
        int pv = kint.pavard.string::length();
        if (v > max_vard) { max_vard = v; }
        if (pv > max_pavard) { max_pavard = pv; }
    }

    if (pr) {
        for (auto &kint: grupe) {
            int nn = kint.nd.size();
            if (nn > max_nd) { max_nd = nn; }
        }
    }
    cout << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde";
    if (pr) {
        for (int i = 0; i < max_nd; i++) {
            cout << "ND" << setw(1 + std::to_string(i + 1).length()) << left << i + 1;
        }
        cout << setw(5) << left << "Egz.";
    }
    cout << setw(18) << left << "Galutinis (Vid.)" << setw(18) << left << "Galutinis (Med.)" << endl;
    for (int i = 0; i < (max_vard + max_pavard + 38); i++) { cout << "-"; }
    if (pr) {
        for (int i = 0; i < max_nd; i++) {
            cout << "----";
        }
    }
    cout << "\n";
    for (auto &kint: grupe) {
        cout << setw(max_vard + 2) << left << kint.vard << setw(max_pavard + 2) << left << kint.pavard;
        if (pr) {
            for (int i = 0; i < kint.nd.size(); i++) {
                cout << setw(3 + std::to_string(i + 1).length()) << left << kint.nd[i];
            }
            for (int i = kint.nd.size(); i < max_nd; i++) {
                cout << setw(3 + std::to_string(i + 1).length()) << left << "--";
            }
            cout << setw(5) << left << kint.ekzam;
        }
        cout << setw(18) << left << fixed << setprecision(2) << kint.gal_vid;
        cout << setw(18) << left << fixed << setprecision(2) << kint.gal_med << endl;
    }
}