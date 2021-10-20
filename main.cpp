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
    cout<<"\n\n";
    cout << setw(10)<<left<<"Įrašų sk." <<setw(34)<<""<<"vector"<< setw(10)<<std::right<< "| "<<setw(13)<< left <<"list"<<setw(15)<<"| vector/list"<<setw(15)<<"| list/vector"
    <<endl;
    for(int i=0;i<98;i++){cout<<"=";}
    cout<<"\n";
    for (int i = 1000; i <= 10000000; i*=10) {


        vector<studentas> grupe_v;
        list<studentas> grupe_l;
        ifstream file_v;
        ifstream file_l;
        grupe_v.clear();
        grupe_l.clear();
        string loc = "/Users/maksimcizov/CLionProjects/OP1Task/" + std::to_string(i) + ".txt";



            file_v.open(loc);
            auto start_v = std::chrono::high_resolution_clock::now();
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
                grupe_v.push_back(st);
                std_v_n++;
            }
            file_v.close();
            auto end_v = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> read_v = end_v - start_v;






            file_l.open(loc);
            auto start_l = std::chrono::high_resolution_clock::now();
            string line_l;
            int std_l_n = 0;
            while (getline(file_l, line_l)) {
                if (std_l_n == 0) {
                    std_l_n++;
                    continue;
                }
                list<string> data;
                int pos;
                if (line_l.size() < 8) { continue; }
                while (line_l.size() != 0) {
                    pos = line_l.find(" ");
                    if (pos == 0) {
                        line_l.erase(0, 1);
                        continue;
                    }
                    if (pos == string::npos) {
                        data.push_back(line_l);
                        break;
                    }
                    data.push_back(line_l.substr(0, pos));
                    line_l.erase(0, pos + 1);
                }
                if (data.size() < 4) { continue; }
                studentas st;
                st.vard = data.front();
                data.pop_front();

                st.pavard = data.front();
                data.pop_front();
                int nm;
                std::stringstream ss;
                ss << data.back();
                data.pop_back();
                ss >> nm;
                st.ekzam = nm;
                while (!data.empty()) {
                    ss << data.front();
                    data.pop_front();
                    ss >> nm;
                    st.nd.push_back(nm);
                }
                grupe_l.push_back(st);
                std_l_n++;
            }
            file_l.close();
            auto end_l = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> read_l = end_l - start_l;



        cout << setw(10)<<left<<i <<setw(33)<< "irasu failo nuskaitymo laikas : " <<setw(14)<< left<<read_v.count()<<"| "<< setw(13)<< left <<read_l.count()<<"| "<< setw(13)<<read_v.count()/read_l.count()<<"| "<< setw(13)<<read_l.count()/read_v.count()  <<endl;


        start_v = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_v);
        sort(grupe_v.begin(), grupe_v.end(), stud_compare_g);
        int indx_v = binsearch(grupe_v);
        vector<studentas> nuskriaustukai_v(grupe_v.begin(), grupe_v.begin() + indx_v);
        vector<studentas> galvociai_v(grupe_v.begin() + indx_v, grupe_v.end());
        end_v = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_v = end_v - start_v;


        start_l = std::chrono::high_resolution_clock::now();
        mean_sk(grupe_l);
        grupe_l.sort(stud_compare_g);

        list<studentas> nuskriaustukai_l;


        while (grupe_l.front().gal_vid<5){
            nuskriaustukai_l.push_back(grupe_l.front());
            grupe_l.pop_front();
        }

        list<studentas> galvociai_l = grupe_l;
        end_l = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_l = end_l - start_l;


        cout << setw(10)<<left<<i <<setw(33)<< "irasu rusiavimo laikas : " <<setw(14)<< left<<sort_v.count()<<"| "<< setw(13)<< left <<sort_l.count()<<"| "<< setw(13)<<sort_v.count()/sort_l.count()   <<"| "<< setw(13)<<sort_l.count()/sort_v.count() <<endl;
        cout << setw(10)<<left<<i <<setw(33)<< "irasu bendras testo laikas : " <<setw(14)<< left<<sort_v.count()+read_v.count()<<"| "<< setw(13)<< left <<sort_l.count()+read_l.count()<<"| "<< setw(13)<<(sort_v.count()+read_v.count())/(sort_l.count()+read_l.count())   <<"| "<< setw(13)<<(sort_l.count()+read_l.count())/(sort_v.count()+read_v.count()) <<endl;
        for(int i=0;i<98;i++){cout<<"-";}
        cout<<"\n";
    }

}