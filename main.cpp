#include "libai.h"
#include "studentas.h"
//#include "median.h"
//#include "generate.h"
//#include "mean.h"
//#include "printas.h"
//#include "comparator.h"
//#include "writeas.h"
//#include "binsearch.h"

int main() {

    cout<<"Nuskaitomi failai..."<<endl;
    vector<studentas> grp1000;
    vector<studentas> grp10000;
    vector<studentas> grp100000;
    vector<studentas> grp1000000;
    vector<studentas> grp10000000;
    std::map<int,vector<studentas>>stds = {{1000,grp1000},{10000,grp10000},{100000,grp100000},{1000000,grp1000000},{10000000,grp10000000}};


    for (int i = 1000; i <= 10000000; i*=10) {
        ifstream file_v;
        ifstream file_l;
        string loc = std::to_string(i) + ".txt";
        while(true) {
            try {
                file_v.open(loc);
                if (!file_v.is_open()) { throw 1; }
            }
            catch (int err) {
                cout << "Failas '" << loc << "' nebuvo surastas, iveskite lokacija dar karta:" << endl;
                cin >> loc;
                continue;
            }
            break;
        }
        string line_v;
        int std_v_n = 0;
        while (getline(file_v, line_v)) {
            if (std_v_n == 0) {
                std_v_n++;
                continue;
            }
            vector<string> data;
            int pos;
            if (line_v.size() < 8) { continue; }
            while (line_v.size() != 0) {
                pos = line_v.find(" ");
                if (pos == 0) {
                    line_v.erase(0, 1);
                    continue;
                }
                if (pos == string::npos) {
                    data.push_back(line_v);
                    break;
                }
                data.push_back(line_v.substr(0, pos));
                line_v.erase(0, pos + 1);
            }
            if (data.size() < 4) { continue; }
            std::stringstream ss;
            int nm;
            ss << data.back();
            ss >> nm;
            studentas st(nm, data[0],data[1]);
            vector <int> nd;
            for (int i = 2; i < data.size() - 1; i++) {
                ss.clear();
                ss << data[i];
                ss >> nm;
                nd.push_back(nm);
            }
            st.fillNd(nd);
            stds[i].push_back(st);
            std_v_n++;
        }
        file_v.close();
    }


    cout<<"Failai sekmingai nuskaityti"<<endl;

    cout<<"\n\n";
    for(int i=0;i<58;i++){cout<<"=";}
    cout<<"\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(49)<<std::right<<"s. |"<<endl;
    for(int i=0;i<58;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10) {
        vector<double> data;
        for (int k = 0; k < 5; k++) {
            vector<studentas> grupe_v;
            list<studentas> grupe_l;
            grupe_v.clear();
            grupe_l.clear();
            for (auto k: stds[i]) {
                grupe_v.push_back(k);
                grupe_l.push_back(k);
            }
            auto start_v = std::chrono::high_resolution_clock::now();
            for (auto k: grupe_v) {
                k.mean_sk();
            }
            sort(grupe_v.begin(), grupe_v.end(), cmp);
            vector<studentas> galvociai_v;
            vector<studentas> nuskriaustukai_v;
            for (auto &std: grupe_v) {
                if (std.getGalVid() >= 5) {
                    galvociai_v.push_back(std);
                } else { nuskriaustukai_v.push_back(std); }
            }
            auto end_v = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> sort_v = end_v - start_v;
            data.push_back(sort_v.count());
        }

        double sm = 0;
        for (auto k : data){
            sm += k;
        }
        sm = sm/data.size();

            cout << setw(10) << left << i << setw(33) << "irasu rusiavimo laikas : " << setw(14) << left
                 << sm << "| " << endl;
            for (int i = 0; i < 58; i++) { cout << "-"; }
            cout << "\n";

    }
}