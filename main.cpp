#include "libai.h"


struct studentas {
    string vard, pavard;
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
    cout << "Kaip jus norite skaicioti galutini bala?\nJei pagal mediana - iveskite \"1\", jei pagal vidurki - iveskite \"2\":\n";
    int ats;
    cin >> ats;

    studentas grupe[stud_sk];
    while (true){
        if (ats == 1){
            for (int i = 0; i < stud_sk; i++) {
                int nd[nd_sk];
                float med;
                cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:";
                cin >> grupe[i].vard >> grupe[i].pavard;
                for (int j = 0; j < nd_sk; j++) {
                    cout << "Iveskite " << j + 1 << " pazymio iverti\n";
                    cin >> nd[j];
                }
                int n = sizeof(nd)/sizeof(nd[0]);
                std::sort(nd,nd+n);
                if (n % 2 == 0){
                    med = (nd[n/2-1] + nd[(n/2)])/2.0;
                }
                else{
                    n = static_cast<int>(n/2);
                    med = nd[n];
                }
                cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi:\n";
                cin >> grupe[i].ekzam;

                grupe[i].gal = 0.4 * med + (0.6 * grupe[i].ekzam);
            }
            break;
        }
        else if (ats == 2){

            for (int i = 0; i < stud_sk; i++) {
                int sum = 0;
                int nd[nd_sk];
                cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:";
                cin >> grupe[i].vard >> grupe[i].pavard;
                for (int j = 0; j < nd_sk; j++) {
                    cout << "Iveskite " << j + 1 << " pazymio iverti\n";
                    cin >> nd[j];
                    sum += nd[j];
                }
                cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi:\n";
                cin >> grupe[i].ekzam;

                grupe[i].gal = 0.4 * (static_cast<double>(sum) / nd_sk) + (0.6 * grupe[i].ekzam);
            }
            break;
        }
        else {
            cout<<"Jus ivedete netinkama simboli: "<<ats<<endl;
            cout<<"Prasome ivesti \"1\", jeigu norite skaicioti galutini bala pagal mediana, arba \"2\", jei norite skaiciuoti pagal vidurki:\n";
            cin>>ats;
        }
    }



    int max_vard = 7;
    int max_pavard = 6;
    for (auto &kint: grupe) {
        int v = kint.vard.string::length();
        int pv = kint.pavard.string::length();
        if (v > max_vard) { max_vard = v; }
        if (pv > max_pavard) { max_pavard = pv; }
    }
    if (ats == 1){
        cout << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde" << setw(18) << left
                           << "Galutinis (Med.)" << endl;}
    else {
        cout << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde" << setw(18) << left
                   << "Galutinis (Vid.)" << endl;}
    for (int i = 0; i < (max_vard + max_pavard + 15); i++) { cout << "-"; }
    cout << "\n";
    for (auto &kint: grupe) {
        cout << setw(max_vard + 2) << left << kint.vard << setw(max_pavard + 2) << left << kint.pavard << setw(18)
             << left << kint.gal << endl;
    }
}