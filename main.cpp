#include "libai.h"
#include "studentas.h"
#include "median.h"
#include "generate.h"
#include "mean.h"
#include "printas.h"
#include "comparator.h"
#include "writeas.h"
#include "binsearch.h"

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
            studentas st;
            st.vard = data[0];

            st.pavard = data[1];
            int nm;
            std::stringstream ss;

            for (int i = 2; i < data.size() - 1; i++) {
                ss.clear();
                ss << data[i];
                ss >> nm;
                st.nd.push_back(nm);
            }
            ss.clear();
            ss << data.back();
            ss >> nm;
            st.ekzam = nm;
            stds[i].push_back(st);
            std_v_n++;
        }
        file_v.close();
    }


    cout<<"Failai sekmingai nuskaityti"<<endl;




    cout<<"\n\n";
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    cout<<"Vieno naujo konteinierio strategija"<<endl;
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(31)<<""<<"Mano alg."<< setw(10)<<std::right<< "| "<<setw(28)<< left <<"'remove_if'+'remove_copy_if'"<<setw(15)<<"| Kartų įdiegti algoritmai greitesni už mano"<<endl;
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10){
        vector<studentas> grupe_v;
        vector<studentas> grupe_l;
        grupe_v.clear();
        grupe_l.clear();

        for (auto k: stds[i]){
            grupe_v.push_back(k);
            grupe_l.push_back(k);
        }

        auto start_v = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_v);
        sort(grupe_v.begin(), grupe_v.end(), stud_compare_g);
        vector<studentas> galvociai_v;
        vector<studentas> nuskriaustukai_v;
        for (auto &std:grupe_v){
            if (std.gal_vid>=5){
                galvociai_v.push_back(std);
            }
            else {nuskriaustukai_v.push_back(std);}
        }
        auto end_v = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_v = end_v - start_v;


        auto start_l = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_l);
        sort(grupe_l.begin(), grupe_l.end(), stud_compare_g);
        vector<studentas> galvociai_l;
        std::remove_copy_if(grupe_l.begin(),grupe_l.end(),std::back_inserter(galvociai_l),([](studentas a){if (a.gal_vid<5){return true;} else {return false;}}));
        grupe_l.erase(std::remove_if(grupe_l.begin(), grupe_l.end(),([](studentas a){if (a.gal_vid<5){return false;} else {return true;}})),grupe_l.end());
        auto end_l = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_l = end_l - start_l;


        cout << setw(10)<<left<<i <<setw(33)<< "irasu rusiavimo laikas : " <<setw(14)<< left<<sort_v.count()<<"| "<< setw(28)<< left <<sort_l.count()<<"| "<< setw(13)<<sort_v.count()/sort_l.count()<<endl;
        for(int i=0;i<120;i++){cout<<"-";}
        cout<<"\n";
    }





    cout<<"\n\n";
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    cout<<"Dvieju nauju konteinieriu strategija"<<endl;
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(31)<<""<<"Mano alg."<< setw(10)<<std::right<< "| "<<setw(28)<< left <<"'remove_if'+'remove_copy_if'"<<setw(15)<<"| Kartų įdiegti algoritmai greitesni už mano"<<endl;
    for(int i=0;i<120;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10){
        vector<studentas> grupe_v;
        vector<studentas> grupe_l;
        grupe_v.clear();
        grupe_l.clear();

        for (auto k: stds[i]){
            grupe_v.push_back(k);
            grupe_l.push_back(k);
        }

        auto start_v = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_v);
        sort(grupe_v.begin(), grupe_v.end(), stud_compare_g);
        vector<studentas> galvociai_v;
        while (grupe_v.back().gal_vid>=5){

            galvociai_v.push_back(grupe_v.back());
            grupe_v.pop_back();
        }
        vector<studentas> nuskriaustukai_v = grupe_v;
        auto end_v = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_v = end_v - start_v;


        auto start_l = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_l);
        sort(grupe_l.begin(), grupe_l.end(), stud_compare_g);
        vector<studentas> galvociai_l;
        vector<studentas> nuskriaustukai_l;
        std::remove_copy_if(grupe_l.begin(),grupe_l.end(),std::back_inserter(galvociai_l),([](studentas a){if (a.gal_vid<5){return true;} else {return false;}}));
        std::remove_copy_if(grupe_l.begin(),grupe_l.end(),std::back_inserter(nuskriaustukai_l),([](studentas a){if (a.gal_vid<5){return false;} else {return true;}}));
        auto end_l = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_l = end_l - start_l;


        cout << setw(10)<<left<<i <<setw(33)<< "irasu rusiavimo laikas : " <<setw(14)<< left<<sort_v.count()<<"| "<< setw(28)<< left <<sort_l.count()<<"| "<< setw(13)<<sort_v.count()/sort_l.count()<<endl;
        for(int i=0;i<120;i++){cout<<"-";}
        cout<<"\n";
    }








    cout<<"\n\n";
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    cout<<"Vieno naujo konteinierio strategija"<<endl;
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(34)<<""<<"vector "<<std::right<< setw(9)<<"s. | "<<setw(10)<< left <<"list"<<setw(18)<<"s. | vector/list"<<setw(15)<<"| list/vector"
    <<endl;
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10){
        vector<studentas> grupe_v;
        list<studentas> grupe_l;
        grupe_v.clear();
        grupe_l.clear();

        for (auto k: stds[i]){
            grupe_v.push_back(k);
            grupe_l.push_back(k);
        }

        auto start_v = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_v);
        sort(grupe_v.begin(), grupe_v.end(), stud_compare_g);
        vector<studentas> galvociai_v;
        while (grupe_v.back().gal_vid>=5){

            galvociai_v.push_back(grupe_v.back());
            grupe_v.pop_back();
        }
        vector<studentas> nuskriaustukai_v = grupe_v;
        auto end_v = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_v = end_v - start_v;


        auto start_l = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_l);
        grupe_l.sort(stud_compare_g);
        list<studentas> nuskriaustukai_l;
        while (grupe_l.back().gal_vid>=5){
            nuskriaustukai_l.push_back(grupe_l.back());
            grupe_l.pop_back();
        }
        list<studentas> galvociai_l = grupe_l;
        auto end_l = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_l = end_l - start_l;


        cout << setw(10)<<left<<i <<setw(33)<< "irasu rusiavimo laikas : " <<setw(14)<< left<<sort_v.count()<<"| "<< setw(13)<< left <<sort_l.count()<<"| "<< setw(13)<<sort_v.count()/sort_l.count()   <<"| "<< setw(13)<<sort_l.count()/sort_v.count() <<endl;
       for(int i=0;i<98;i++){cout<<"-";}
        cout<<"\n";
    }
    cout<<"\n\n";
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    cout<<"Dvieju nauju konteinieriu strategija"<<endl;
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(34)<<""<<"vector "<<std::right<< setw(9)<<"s. | "<<setw(10)<< left <<"list"<<setw(18)<<"s. | vector/list"<<setw(15)<<"| list/vector"
         <<endl;
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10) {
        vector<studentas> grupe_v;
        list<studentas> grupe_l;
        grupe_v.clear();
        grupe_l.clear();
        for (auto k: stds[i]){
            grupe_v.push_back(k);
            grupe_l.push_back(k);
        }
        auto start_v = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_v);
        sort(grupe_v.begin(), grupe_v.end(), stud_compare_g);
        vector<studentas> galvociai_v;
        vector<studentas> nuskriaustukai_v;
        for (auto &std:grupe_v){
            if (std.gal_vid>=5){
                galvociai_v.push_back(std);
            }
            else {nuskriaustukai_v.push_back(std);}
        }
        auto end_v = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_v = end_v - start_v;


        auto start_l = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_l);
        grupe_l.sort(stud_compare_g);
        list<studentas> nuskriaustukai_l;
        list<studentas> galvociai_l;
        for (auto &std:grupe_l){
            if (std.gal_vid>=5){
                galvociai_l.push_back(std);
            }
            else {nuskriaustukai_l.push_back(std);}
        }

        auto end_l = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_l = end_l - start_l;


        cout << setw(10)<<left<<i <<setw(33)<< "irasu rusiavimo laikas : " <<setw(14)<< left<<sort_v.count()<<"| "<< setw(13)<< left <<sort_l.count()<<"| "<< setw(13)<<sort_v.count()/sort_l.count()   <<"| "<< setw(13)<<sort_l.count()/sort_v.count() <<endl;
        for(int i=0;i<98;i++){cout<<"-";}
        cout<<"\n";
    }













}