#include "libai.h"
#include "median.h"
void med_sk(vector<studentas> &grupe) {
    for (studentas &studen: grupe) {
        float med;
        vector<int> nd;
        for (int k: studen.nd) {
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