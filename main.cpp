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
    for (int i = 1000; i <= 10000000; i*=10) {
        vector<studentas> grupe;
        int stud_s = i;
        int nd_s = 10;
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < stud_s; i++) {
            grupe.push_back(generate(nd_s));
        }
        write_student(grupe,std::to_string(i) + ".txt");
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> create_t = end - start;
        cout << i << " irasu failo kurimo laikas : " << create_t.count() << endl;
        ifstream file;
        grupe.clear();
        string loc = std::to_string(i) + ".txt";
        file.open(loc);
        start = std::chrono::high_resolution_clock::now();
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
                ss.clear();
                ss << data[i];
                ss >> nm;
                st.nd.push_back(nm);
            }
            ss.clear();
            ss << data.back();
            ss >> nm;
            st.ekzam = nm;
            grupe.push_back(st);
            std_n++;
        }
        file.close();
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> read_t = end - start;
        cout << i << " irasu failo nuskaitymo laikas : " << read_t.count() << endl;
        start = std::chrono::high_resolution_clock::now();
        mean_sk(grupe);
        sort(grupe.begin(), grupe.end(), stud_compare_g);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> sort_t = end - start;
        cout << i << " irasu rusiavimo laikas : " << sort_t.count() << endl;

        start = std::chrono::high_resolution_clock::now();
        int indx = binsearch(grupe);
        vector<studentas> nuskriaustukai(grupe.begin(), grupe.begin() + indx);
        vector<studentas> galvociai(grupe.begin() + indx, grupe.end());
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> group_t = end - start;
        cout << i << " irasu skyrstymo i du sarasus laikas : " << group_t.count() << endl;

        start = std::chrono::high_resolution_clock::now();
        write_student(nuskriaustukai, std::to_string(i) + "nuskraustukai.txt");
        write_student(galvociai, std::to_string(i) + "galvociai.txt");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> write_t = end - start;
        cout << i << " irasu irasymo i du failus laikas : " << write_t.count() << endl << endl;
        double t = create_t.count() + read_t.count() + group_t.count() + write_t.count() + sort_t.count();
        cout << i << " irasu testo laikas : " << t << endl;
        cout <<"---------------------------------------------------------"<<endl;
    }
}