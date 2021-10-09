#include "writeas.h"
void write_student(vector<studentas> &grupe, string filename){
    std::ofstream file(filename, std::ofstream::out);
    int max_vard = 6;
    int max_pavard = 7;
    int max_nd = 0;
    for (auto &kint: grupe) {
        int v = kint.vard.string::length();
        int pv = kint.pavard.string::length();
        int nn = kint.nd.size();
        if (v > max_vard) { max_vard = v; }
        if (pv > max_pavard) { max_pavard = pv; }
        if (nn > max_nd) { max_nd = nn; }
    }

    file << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde";
    for (int i = 0; i < max_nd; i++) {
        file << "ND" << setw(1 + std::to_string(i + 1).length()) << left << i + 1;
    }
    file << setw(5) << left << "Egz.\n";
    for (auto &kint: grupe) {
        file << setw(max_vard + 2) << left << kint.vard << setw(max_pavard + 2) << left << kint.pavard;
            for (int i = 0; i < kint.nd.size(); i++) {
                file << setw(3 + std::to_string(i + 1).length()) << left << kint.nd[i];
            }
            for (int i = kint.nd.size(); i < max_nd; i++) {
                file << setw(3 + std::to_string(i + 1).length()) << left << "--";
            }
            file << setw(5) << left << kint.ekzam<< endl;
    }
    file.close();
}
