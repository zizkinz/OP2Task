#include "libai.h"

#ifndef OP1TASK_STUDENTAS_H
#define OP1TASK_STUDENTAS_H

class zmogus{
protected:
    string vard_, pavard_;
public:
    zmogus() : vard_(""),pavard_("") {}
    zmogus(string vardas, string pavarde) : vard_(vardas),pavard_(pavarde) {}
    virtual const string &getVard() const = 0;
    virtual const string &getPavard() const = 0;
};

class studentas: public zmogus{
private:
    int ekzam_;
    float gal_vid_;
    float gal_med_;
    vector<int> nd_;
public:
    studentas() : zmogus(), ekzam_(0) {}
    studentas(int ek) : zmogus(), ekzam_(ek) {}
    studentas(string vardas, string pavarde): zmogus(vardas,pavarde),ekzam_(0) {}
    studentas(int egzaminas, string vardas, string pavarde) : zmogus(vardas,pavarde), ekzam_(egzaminas) {}
    ~studentas();

    studentas(const studentas&);



    friend std::ostream& operator<<(std::ostream&, const studentas&);

    friend std::istream& operator>>(std::istream& , studentas&);

    studentas& operator=(const studentas&);

    const int& operator[](int);


    void mean_sk();

    void med_sk();

    void fillNd(vector<int> nd);

    const string &getVard() const;

    const string &getPavard() const;

    const vector<int> &getNd() const;

    int getEkzam() const;

    float getGalVid() const;

    float getGalMed() const;

    void setEkzam(int ekzam);
};

bool cmp(const studentas&, const studentas& );

bool operator==(studentas&, studentas&);

bool operator!=(studentas&, studentas&);

#endif //OP1TASK_STUDENTAS_H





