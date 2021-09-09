#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct studentas
{
    string vard, pavard;
    float nd[10];
    float egzam;
    float gal;
};

void pild(studentas &kint);
void printas(studentas &kint);

int main() {
    int n;
    studentas st1;
    studentas st2;
    cout<<"New testdhsjjdsa";
    cout << "Iveskite studento varda ir pavarde: ";
    cin >> st1.vard >> st1.pavard;
    cout << "Kiek namu darbu bus? (1-10)"; cin >> n;
    cout << "Iveskite pazymius: "<<endl;
    float sun = 0, vid = 0;
    for (int i =0; i < n; i++){
        cin>>st1.nd[i];
        sun += st1.nd[i];
    }
    vid = sun / n;
    cout << "Iveskite egzamino pazymi: "; cin >> st1.egzam;
    st1.gal = vid*0.4 + 0.6 * st1.egzam;
    cout << "Vidurkis: "<< vid;
    cout << "Galutinis: " << st1.gal;
    return 0;
}
