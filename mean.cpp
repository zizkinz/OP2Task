#include "mean.h"
void mean_sk(vector<studentas> &grupe) {
    for (studentas &studen: grupe) {
        int sum = 0;
        for (int paz: studen.nd) {
            sum += paz;
        }
        studen.gal_vid = 0.4 * (static_cast<double>(sum) / studen.nd.size()) + (0.6 * studen.ekzam);
    }
}


void mean_sk(list<studentas> &grupe) {
    for (studentas &studen: grupe) {
        int sum = 0;
        for (int paz: studen.nd) {
            sum += paz;
        }
        studen.gal_vid = 0.4 * (static_cast<double>(sum) / studen.nd.size()) + (0.6 * studen.ekzam);
    }
}