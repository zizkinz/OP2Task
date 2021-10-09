#include "libai.h"
#include "studentas.h"
#include "median.h"
#include "generate.h"
#include "mean.h"
#include "printas.h"
#include "comparator.h"

int main() {
    srand(time(NULL));
    vector<studentas> grupe;
    bool prp = false;
    cout << "Kaip jus norite pateikti studentu duomenis?" << endl;
    cout << "Jei norite, kad duomenis butu generuojami atsitiktinai - iveskite '1';" << endl;
    cout << "Jei norite, kad duomenis butu nuskaitomi is failo - iveskite '2';" << endl;
    cout << "Jei norite ivesti duomenis rankiniu budu - iveskite bet koki kita simboli;" << endl;
    int at;
    if (cin >> at && at == 1) {
        prp = true;
        cout << "Kiek studentu jus noretumete sugeneruoti?" << endl;
        int stud_s = 0;
        while (true) {
            if (cin >> stud_s && stud_s > 1) { break; }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Jus ivedete netinkama simboli - iveskite sveika skaiciu" << endl;
            }
        }
        cout << "Kiek namu darbu jus noretumete sugeneruoti?" << endl;
        int nd_s = 0;
        while (true) {
            if (cin >> nd_s && nd_s > 1) { break; }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Jus ivedete netinkama simboli - iveskite sveika skaiciu" << endl;
            }
        }
        for (int i = 0; i < stud_s; i++) {
            grupe.push_back(generate(nd_s));
        }

    } else if (at == 2) {

        cout << "Iveskite tekstinio failio lokacija:" << endl;
        string loc;
        cin >> loc;
//        string loc = "../kursiokai.txt";
        ifstream file;
        while(true) {
            try {
                file.open(loc);
                if (!file.is_open()) { throw 1; }
            }
            catch (int err) {
                cout << "Failas '" << loc << "' nebuvo surastas, iveskite lokacija dar karta:" << endl;
                cin >> loc;
                continue;
            }
            break;
        }
        string line;
        int std_n = 0;
        while (getline(file, line)) {
            if (std_n == 0) {
                std_n++;
                continue;
            }
            vector<string> data;
            int pos;
            if (line.size() < 8) { continue; }
            while (line.size() != 0) {
                pos = line.find(" ");
                if (pos == 0) {
                    line.erase(0, 1);
                    continue;
                }
                if (pos == string::npos) {
                    data.push_back(line);
                    break;
                }
                data.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
            if (data.size() < 4) { continue; }
            studentas st;
            st.vard = data[0];
            st.pavard = data[1];
            int nm;
            bool brk = false;
            std::stringstream ss;
            for (int i = 2; i < data.size() - 1; i++) {
                if (data[i].find_first_not_of("0123456789") != string::npos) {
                    cout << std_n << "-ojo studento " << data[0] << " " << data[1] << " " << i - 1
                         << "-oji namu darbu reiksme '" << data[i] << "' nera sveikas skaicius" << endl;
                    cout << "Ar jus norite pasalinti visus turimus duomenis apie sita studenta?" << endl;
                    cout
                            << "Jei taip - iveskite '1', jei norite palikti likusius duomenis - iveskite bet koki kita simboli"
                            << endl;
                    int v;
                    if (cin >> v && v == 1) {
                        cout << "Studento " << data[0] << " " << data[1]
                             << " duomenis buvo pasalinti. Nuskaitomi kiti studentai." << endl;
                        brk = true;
                        break;
                    } else {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                }
                ss.clear();
                ss << data[i];
                ss >> nm;
                st.nd.push_back(nm);
            }
            if (brk) { continue; }
            ss.clear();
            ss << data.back();
            ss >> nm;
            st.ekzam = nm;
            grupe.push_back(st);
            std_n++;
        }
    } else {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int i = 0;
        while (true) {
            studentas st;
            int aa = 0;
            if (i == 0) {
                aa = 123;
            } else {
                cout << "Iki siol buvo ivesta  " << i << " studentu" << endl;
                cout
                        << "Jeigu norite pratesti studentu ivedima - iveskite bet koki sveika skaiciu\n"
                           "Jei norite uzbaigti duomenu ivedima - iveskite bet koki kita simboli\n";
            }

            if (aa == 123 || cin >> aa) {
                cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:";
                cin >> st.vard >> st.pavard;
                cout << "Pradedamas " << i + 1
                     << "-o studento namu darbu pazymiu ivedimas\nIveskite sveika skaiciu nuo 1 iki 10.\n"
                        "Jeigu norite uzbaigti pazymiu ivedima - iveskite bet koki kita simboli.\n";
                for (int j = 1; j < 100; j++) {
                    cout << "Iveskite " << j << " pazymio iverti\n";
                    int pz = 0;
                    if (cin >> pz && pz > 0 && pz < 11) {
                        st.nd.push_back(pz);
                    } else {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "Namu darbu pazymiu ivedimas baigtas" << endl;
                        cout << i + 1 << "-am studentui jus ivedete siuos pazymius:" << endl;
                        for (int paz: st.nd) {
                            cout << paz << "; ";
                        }
                        cout
                                << "Jeigu duomenys yra teisingi - iveskite bet koki sveika skaiciu.\n"
                                   "Jei norite ivesti duomenis is naujo - iveskite bet koki kita simboli"
                                << endl;
                        int pl = 0;
                        if (cin >> pl) {
                            cout << i + 1 << "-o studento pazymiu ivedimas baigtas" << endl;
                            break;
                        } else {
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            cout << "Pradedamas " << i + 1 << "-o studento pazymiu ivedimas is naujo" << endl;
                            st.nd.clear();
                            j = 0;

                        }
                    }
                }
                cout << "Iveskite " << i + 1 << "-o studento egzamino pazymi:\n";
                cin >> st.ekzam;
                grupe.push_back(st);
                cout << i + 1 << "-o studento duomenu ivedimas baigtas" << endl;
                i++;
            } else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Studentu ivedimas baigtas" << endl;
                break;
            }
        }
    }


    sort(grupe.begin(), grupe.end(), stud_compare);

    med_sk(grupe);
    mean_sk(grupe);
    print_stud(grupe, prp);

}
