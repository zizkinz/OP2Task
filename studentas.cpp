#include "studentas.h"


studentas::studentas(string vardas, string pavarde) {
    this->vard_ = vardas;
    this->pavard_ = pavarde;
    this->ekzam_ = 0;
}

studentas::studentas(int egzaminas, string vardas, string pavarde) {
    this->vard_ = vardas;
    this->pavard_ = pavarde;
    this->ekzam_ = egzaminas;
}

bool cmp(const studentas &stud_1,const  studentas &stud_2) {
    if (stud_1.getGalVid() < stud_2.getGalVid()){return true;}
    else {return false;}
}
void studentas::mean_sk() {
    int sum = 0;
    for (int paz: this->nd_) {
        sum += paz;
    }
    this->gal_vid_ = 0.4 * (static_cast<double>(sum) / this->nd_.size()) + (0.6 * this->ekzam_);
}


void studentas::med_sk() {
    float med;
    vector<int> nd;
    for (int k: this->nd_) {
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
    this->gal_med_ = 0.4 * med + (0.6 * this->ekzam_);
}

void studentas::fillNd(vector<int> nd){
    this->nd_ = nd;
}

const string &studentas::getVard() const {
    return vard_;
}

const string &studentas::getPavard() const {
    return pavard_;
}

int studentas::getEkzam() const {
    return ekzam_;
}

float studentas::getGalVid() const {
    return gal_vid_;
}

float studentas::getGalMed() const {
    return gal_med_;
}


