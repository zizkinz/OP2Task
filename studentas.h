#include "libai.h"

#ifndef OP1TASK_STUDENTAS_H
#define OP1TASK_STUDENTAS_H


class studentas{
private:
    string vard_, pavard_;
    int ekzam_;
    float gal_vid_;
    float gal_med_;
    vector<int> nd_;
public:
    studentas() : ekzam_(0) {}
    studentas(int ek) : ekzam_(ek) {}
    studentas(string vardas, string pavarde);
    studentas(int egzaminas, string vardas, string pavarde);


    void mean_sk();

    void med_sk();

    void fillNd(vector<int> nd);

    const string &getVard() const;

    const string &getPavard() const;

    int getEkzam() const;

    float getGalVid() const;

    float getGalMed() const;


};

bool cmp(const studentas&, const studentas& );
#endif //OP1TASK_STUDENTAS_H





