
#include "libai.h"



struct studentas {
    string vard, pavard;
    float ekzam;
    float gal_vid;
    float gal_med;
    vector<int> nd;
};

studentas generate(int nd_sk) {
    studentas st;
    switch(rand()%2){
        case 0:{
            switch(rand()%45){
                case 0: st.vard ="Lukas"; break;
                case 1: st.vard ="Matas"; break;
                case 2: st.vard ="Nojus"; break;
                case 3: st.vard ="Dominykas"; break;
                case 4: st.vard ="Dovydas"; break;
                case 5: st.vard ="Rokas"; break;
                case 6: st.vard ="Mantas"; break;
                case 7: st.vard ="Jonas"; break;
                case 8: st.vard ="Jokubas"; break;
                case 9: st.vard ="Kajus"; break;
                case 10: st.vard ="Ignas"; break;
                case 11: st.vard ="Martynas"; break;
                case 12: st.vard ="Benas"; break;
                case 13: st.vard ="Arnas"; break;
                case 14: st.vard ="Tomas"; break;
                case 15: st.vard ="Emilis"; break;
                case 16: st.vard ="Augustas"; break;
                case 17: st.vard ="Deividas"; break;
                case 18: st.vard ="Karolis"; break;
                case 19: st.vard ="Danielius"; break;
                case 20: st.vard ="Paulius"; break;
                case 21: st.vard ="Domantas"; break;
                case 22: st.vard ="Domas"; break;
                case 23: st.vard ="Justas"; break;
                case 24: st.vard ="Gabrielius"; break;
                case 25: st.vard ="Adomas"; break;
                case 26: st.vard ="Kristupas"; break;
                case 27: st.vard ="Gustas"; break;
                case 28: st.vard ="Titas"; break;
                case 29: st.vard ="Joris"; break;
                case 30: st.vard ="Laurynas"; break;
                case 31: st.vard ="Edvinas"; break;
                case 32: st.vard ="Armandas"; break;
                case 33: st.vard ="Eimantas"; break;
                case 34: st.vard ="Vilius"; break;
                case 35: st.vard ="Pijus"; break;
                case 36: st.vard ="Erikas"; break;
                case 37: st.vard ="Tadas"; break;
                case 38: st.vard ="Nedas"; break;
                case 39: st.vard ="Markas"; break;
                case 40: st.vard ="Ugnius"; break;
                case 41: st.vard ="Ernestas"; break;
                case 42: st.vard ="Aronas"; break;
                case 43: st.vard ="Daniel"; break;
                case 44: st.vard ="Vakaris"; break;
            }
            switch(rand()%45){
                case 0: st.pavard ="Adomaitis"; break;
                case 1: st.pavard ="Alekna"; break;
                case 2: st.pavard ="Anusauskas"; break;
                case 3: st.pavard ="Armonas"; break;
                case 4: st.pavard ="Asanavicius"; break;
                case 5: st.pavard ="Azubalis"; break;
                case 6: st.pavard ="Azuolas"; break;
                case 7: st.pavard ="Bakas"; break;
                case 8: st.pavard ="Balcytis"; break;
                case 9: st.pavard ="Bartosevicius"; break;
                case 10: st.pavard ="Baublys"; break;
                case 11: st.pavard ="Biciunas"; break;
                case 12: st.pavard ="Bukauskas"; break;
                case 13: st.pavard ="Butkevicius"; break;
                case 14: st.pavard ="Cepononis"; break;
                case 15: st.pavard ="Dziugelis"; break;
                case 16: st.pavard ="Fiodorovas"; break;
                case 17: st.pavard ="Gaizauskas"; break;
                case 18: st.pavard ="Gapsys"; break;
                case 19: st.pavard ="Gedvilas"; break;
                case 20: st.pavard ="Gentvilas"; break;
                case 21: st.pavard ="Gentvilas"; break;
                case 22: st.pavard ="Glaveckas"; break;
                case 23: st.pavard ="Grazulis"; break;
                case 24: st.pavard ="Griskevicius"; break;
                case 25: st.pavard ="Gudauskas"; break;
                case 26: st.pavard ="Jarutis"; break;
                case 27: st.pavard ="Jonaitis"; break;
                case 28: st.pavard ="Jonauskas"; break;
                case 29: st.pavard ="Jovaisa"; break;
                case 30: st.pavard ="Juozapaitis"; break;
                case 31: st.pavard ="Karbauskis"; break;
                case 32: st.pavard ="Kasciunas"; break;
                case 33: st.pavard ="Kepenis"; break;
                case 34: st.pavard ="Kernagis"; break;
                case 35: st.pavard ="Kindurys"; break;
                case 36: st.pavard ="Kreivys"; break;
                case 37: st.pavard ="Kukuraitis"; break;
                case 38: st.pavard ="Kupcinskas"; break;
                case 39: st.pavard ="Labanavicius"; break;
                case 40: st.pavard ="Landsbergis"; break;
                case 41: st.pavard ="Lopata"; break;
                case 42: st.pavard ="Majauskas"; break;
                case 43: st.pavard ="Maldeikis"; break;
                case 44: st.pavard ="Masiulis"; break;
            }
            break;
        }
        case 1:{
            switch(rand()%45){
                case 0: st.vard ="Gabija"; break;
                case 1: st.vard ="Emilija"; break;
                case 2: st.vard ="Gabriele"; break;
                case 3: st.vard ="Kamile"; break;
                case 4: st.vard ="Ugne"; break;
                case 5: st.vard ="Austeja"; break;
                case 6: st.vard ="Ieva"; break;
                case 7: st.vard ="Viktorija"; break;
                case 8: st.vard ="Vilte"; break;
                case 9: st.vard ="Urte"; break;
                case 10: st.vard ="Greta"; break;
                case 11: st.vard ="Rugile"; break;
                case 12: st.vard ="Goda"; break;
                case 13: st.vard ="Karolina"; break;
                case 14: st.vard ="Migle"; break;
                case 15: st.vard ="Auguste"; break;
                case 16: st.vard ="Evelina"; break;
                case 17: st.vard ="Liepa"; break;
                case 18: st.vard ="Ema"; break;
                case 19: st.vard ="Deimante"; break;
                case 20: st.vard ="Saule"; break;
                case 21: st.vard ="Leja"; break;
                case 22: st.vard ="Paulina"; break;
                case 23: st.vard ="Kotryna"; break;
                case 24: st.vard ="Aiste"; break;
                case 25: st.vard ="Sofija"; break;
                case 26: st.vard ="Patricija"; break;
                case 27: st.vard ="Guste"; break;
                case 28: st.vard ="Smilte"; break;
                case 29: st.vard ="Amelija"; break;
                case 30: st.vard ="Karina"; break;
                case 31: st.vard ="Agne"; break;
                case 32: st.vard ="Eva"; break;
                case 33: st.vard ="Akvile"; break;
                case 34: st.vard ="Monika"; break;
                case 35: st.vard ="Rusne"; break;
                case 36: st.vard ="Marija"; break;
                case 37: st.vard ="Lukne"; break;
                case 38: st.vard ="Laura"; break;
                case 39: st.vard ="Samanta"; break;
                case 40: st.vard ="Egle"; break;
                case 41: st.vard ="Kornelija"; break;
                case 42: st.vard ="Erika"; break;
                case 43: st.vard ="Simona"; break;
                case 44: st.vard ="Milana"; break;
            }
            switch(rand()%45){
                case 0: st.pavard ="Alekna"; break;
                case 1: st.pavard ="Aleknaite"; break;
                case 2: st.pavard ="Liucija"; break;
                case 3: st.pavard ="Armonaite"; break;
                case 4: st.pavard ="Asanaviciute"; break;
                case 5: st.pavard ="Baskiene"; break;
                case 6: st.pavard ="Bilotaite"; break;
                case 7: st.pavard ="Budbergyte"; break;
                case 8: st.pavard ="Budbergyte"; break;
                case 9: st.pavard ="Daniele"; break;
                case 10: st.pavard ="Dobrovolska"; break;
                case 11: st.pavard ="Dumbrava"; break;
                case 12: st.pavard ="Gedviliene"; break;
                case 13: st.pavard ="Girskiene"; break;
                case 14: st.pavard ="Jovaisa"; break;
                case 15: st.pavard ="Jukna"; break;
                case 16: st.pavard ="Kubiliene"; break;
                case 17: st.pavard ="Kuzmickiene"; break;
                case 18: st.pavard ="Kacinskaite"; break;
                case 19: st.pavard ="Kanopa"; break;
                case 20: st.pavard ="Leipute"; break;
                case 21: st.pavard ="Lengviniene"; break;
                case 22: st.pavard ="Lydeka"; break;
                case 23: st.pavard ="Linge"; break;
                case 24: st.pavard ="Miliute"; break;
                case 25: st.pavard ="Mogeniene"; break;
                case 26: st.pavard ="Morkunaite"; break;
                case 27: st.pavard ="Nagiene"; break;
                case 28: st.pavard ="Norkiene"; break;
                case 29: st.pavard ="Navickiene"; break;
                case 30: st.pavard ="Osmianskiene"; break;
                case 31: st.pavard ="Pakarklyte"; break;
                case 32: st.pavard ="Pociuniene"; break;
                case 33: st.pavard ="Sejoniene"; break;
                case 34: st.pavard ="Skaiste"; break;
                case 35: st.pavard ="Salaseviciute"; break;
                case 36: st.pavard ="Sakaliene"; break;
                case 37: st.pavard ="Simonyte"; break;
                case 38: st.pavard ="Sirinskiene"; break;
                case 39: st.pavard ="Siugzdiniene"; break;
                case 40: st.pavard ="Tamasuniene"; break;
                case 41: st.pavard ="Targamadze"; break;
                case 42: st.pavard ="Starkeviciute"; break;
                case 43: st.pavard ="Juska"; break;
                case 44: st.pavard ="Bagdonaite"; break;
            }
            break;
        }

    }
    for (int i = 0; i < nd_sk; i++){
        st.nd.push_back((rand()%10)+1);
    }
    st.ekzam = (rand()%10)+1;
    return st;
}

void med_sk(vector<studentas> &grupe) {
    for (studentas &studen: grupe) {
        float med;
        vector<int> nd;
        for (int k:studen.nd){
            nd.push_back(k);
        }
        std::sort(nd.begin(), nd.end());
        int n = nd.size();
        if (n % 2 == 0) {
            med = (nd[n / 2 - 1] + nd[(n / 2)]) / 2.0;
        } else {
            n = static_cast<int>(n / 2);
            med = nd[n];
        }
        studen.gal_med = 0.4 * med + (0.6 * studen.ekzam);
    }
}

void mean_sk(vector<studentas> &grupe) {
    for (studentas &studen: grupe) {
        int sum = 0;
        for (int paz: studen.nd) {
            sum += paz;
        }
        studen.gal_vid = 0.4 * (static_cast<double>(sum) / studen.nd.size()) + (0.6 * studen.ekzam);
    }
}

void print_stud(vector<studentas> grupe,  bool pr){
    int max_vard = 6;
    int max_pavard = 7;
    int max_nd = 0;
    for (auto &kint: grupe) {
        int v = kint.vard.string::length();
        int pv = kint.pavard.string::length();
        if (v > max_vard) { max_vard = v; }
        if (pv > max_pavard) { max_pavard = pv; }
    }

    if (pr){
        for (auto &kint: grupe) {
            int nn = kint.nd.size();
            if (nn > max_nd) { max_nd = nn; }
        }
    }
    cout << setw(max_vard + 2) << left << "Vardas" << setw(max_pavard + 2) << left << "Pavarde";
    if (pr){
        for (int i = 0; i < max_nd; i++){
            cout<<"ND"<<setw(1+std::to_string(i+1).length())<<left<<i+1;
        }
        cout<<setw(5)<<left<<"Egz.";
    }
    cout<<setw(18)<< left<< "Galutinis (Vid.)"<<setw(18)<< left<< "Galutinis (Med.)"<< endl;
    for (int i = 0; i < (max_vard + max_pavard + 38); i++) { cout << "-"; }
    if (pr){
        for (int i = 0;i<max_nd;i++){
            cout << "----";
        }
    }
    cout << "\n";
    for (auto &kint: grupe) {
        cout << setw(max_vard + 2) << left << kint.vard<< setw(max_pavard + 2) << left << kint.pavard;
        if (pr) {
            for (int i = 0; i < kint.nd.size(); i++) {
                cout << setw(3 + std::to_string(i+1).length()) << left << kint.nd[i];
            }
            for (int i = kint.nd.size(); i < max_nd; i++){
                cout<< setw(3 + std::to_string(i+1).length())<<left<<"--";
            }
            cout<<setw(5)<<left<<setprecision(2) <<kint.ekzam;
        }
        cout<< setw(18) << left <<left<<setprecision(3) << kint.gal_vid;
        cout<< setw(18) << left <<left<<setprecision(3) << kint.gal_med << endl;
    }
}

bool stud_compare(studentas const &stud_1, studentas const &stud_2){
    int p = stud_1.vard.compare(stud_2.vard);
    if ( p < 0){return true;}
    else if(p == 0){
        int k = stud_1.pavard.compare(stud_2.pavard);
        if (k < 0){return true;}
        else {return false;}
    }
    else {return false;}
}



int main() {
    srand(time(NULL));
    vector<studentas> grupe;
    bool prp = false;
    cout<< "Kaip jus norite pateikti studentu duomenis?"<< endl;
    cout<<"Jei norite, kad duomenis butu generuojami atsitiktinai - iveskite '1';"<<endl;
    cout<<"Jei norite, kad duomenis butu nuskaitomi is failo - iveskite '2';"<<endl;
    cout<<"Jei norite ivesti duomenis rankiniu budu - iveskite bet koki kita simboli;"<<endl;
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
            if (cin >> nd_s && nd_s>1) { break; }
            else {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Jus ivedete netinkama simboli - iveskite sveika skaiciu" << endl;
            }
        }
        for (int i = 0; i<stud_s; i++){
            grupe.push_back(generate(nd_s));
        }

    }
    else if (at == 2){

        cout<<"Iveskite tekstinio failio lokacija:"<<endl;
        string loc;
        cin>> loc;
//        string loc = "../kursiokai.txt";
        ifstream file(loc) ;
        while (true){
            if (file.is_open()){break;}
            else {
                cout<<"Failas '"<< loc << "' nebuvo surastas, iveskite lokacija dar karta:" << endl;
                cin>> loc;
                file.open(loc);
            }
        }

        string line;
        int std_n = 0;
        while(getline(file,line)){
            if (std_n == 0){std_n++;continue;}
            vector<string> data;
            int pos;
            if(line.size() < 8 ){continue;}
            while (line.size() != 0){
                pos = line.find(" ");
                if (pos == 0){line.erase(0,1);continue;}
                if (pos == string::npos){
                    data.push_back(line);
                    break;}
                data.push_back(line.substr(0,pos));
                line.erase(0,pos + 1);
            }
            if (data.size() < 4){continue;}
            studentas st;
            st.vard = data[0];
            st.pavard = data[1];
            int nm;
            bool brk = false;
            std::stringstream ss;
            for (int i = 2; i < data.size()-1; i++){
                if ( data[i].find_first_not_of("0123456789") != string::npos){
                    cout<<std_n<<"-ojo studento "<<data[0]<<" "<<data[1]<<" "<<i-1<<"-oji namu darbu reiksme '"<<data[i]<<"' nera sveikas skaicius"<<endl;
                    cout<<"Ar jus norite pasalinti visus turimus duomenis apie sita studenta?"<<endl;
                    cout<<"Jei taip - iveskite '1', jei norite palikti likusius duomenis - iveskite bet koki kita simboli"<<endl;
                    int v;
                    if (cin>>v && v ==1){
                        cout<<"Studento "<<data[0]<<" "<<data[1]<<" duomenis buvo pasalinti. Nuskaitomi kiti studentai."<<endl;
                        brk = true;
                        break;
                    }
                    else {
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
            if (brk){continue;}
            ss.clear();
            ss << data.back();
            ss >> nm;
            st.ekzam = nm;
            grupe.push_back(st);
            std_n++;
        }
    }

    else {
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
                        << "Jeigu norite pratesti studentu ivedima - iveskite bet koki sveika skaiciu\nJei norite uzbaigti duomenu ivedima - iveskite bet koki kita simboli\n";
            }

            if (aa == 123 || cin >> aa) {
                cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde:";
                cin >> st.vard >> st.pavard;
                cout << "Pradedamas " << i + 1
                     << "-o studento namu darbu pazymiu ivedimas\nIveskite sveika skaiciu nuo 1 iki 10.\nJeigu norite uzbaigti pazymiu ivedima - iveskite bet koki kita simboli.\n";
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
                                << "Jeigu duomenys yra teisingi - iveskite bet koki sveika skaiciu.\nJei norite ivesti duomenis is naujo - iveskite bet koki kita simboli"
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


    sort(grupe.begin(),grupe.end(), stud_compare);

    med_sk(grupe);
    mean_sk(grupe);
    print_stud(grupe, prp);

    }
