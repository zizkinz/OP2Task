#include "studentas.h"


studentas::studentas(const studentas& st) {
    this->vard_ = st.getVard();
    this->pavard_ = st.getPavard();
    vector<int> nd;
    for (int k:st.getNd()){nd.push_back(k);}
    this->fillNd(nd);
    this->ekzam_ = st.getEkzam();
}

studentas& studentas::operator=(const studentas& st){
    if (&st == this){return *this;}
    this->vard_ = st.getVard();
    this->pavard_ = st.getPavard();
    vector<int> nd;
    for (int k:st.getNd()){nd.push_back(k);}
    this->fillNd(nd);
    this->ekzam_ = st.getEkzam();
    return *this;
}

studentas::~studentas(){
    this->nd_.clear();
}
studentas::studentas(string vardas, string pavarde) {
    this->vard_ = vardas;
    this->pavard_ = pavarde;
    this->ekzam_ = 0;
}

std::ostream& operator<<(std::ostream& out, const studentas &st){
    out << st.getVard()<<" "<< st.getPavard()<<" ";
    for (int k : st.getNd()){
        out<<k<<' ';
    }
    out<<st.getEkzam();
    return out;
}

std::istream& operator>>(std::istream& in, studentas &st){
    string a;
    int pos;
    vector<string> data;
    std::getline(in,a);
    while (a.size() != 0){
        pos = a.find(" ");
        if (pos == string::npos) {
            data.push_back(a);
            break;
        }
        data.push_back(a.substr(0, pos));
        a.erase(0, pos + 1);
    }
    std::stringstream ss;
    int nm;
    vector <int> nd;
    for (string p: data){
        ss.clear();
        ss << p;
        ss >> nm;
        nd.push_back(nm);
    }
    st.fillNd(nd);
    return in;
}

bool operator==(studentas& st1,studentas& st2){
    if ((st1.getVard() != st2.getVard()) or (st1.getPavard() != st2.getPavard()) or (st1.getEkzam() != st2.getEkzam())){
        return false;
    }
    auto st1_nd = st1.getNd();
    auto st2_nd = st2.getNd();
    if (st1_nd.size() != st2_nd.size()){
        return false;
    }
    else {
        for ( int i = 0; i< st1_nd.size(); i++){
            if (st1_nd[i] != st2_nd[i]){return false;}
        }
    }
    return true;
}

bool operator!=(studentas& st1,studentas& st2){
    return !(st1==st2);
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

const int& studentas::operator[](int i){
    if (i<0 or i>= this->nd_.size()){
        throw std::out_of_range {"Vector::operator[]"};
    }
    return this->nd_[i];}

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

const vector<int> &studentas::getNd() const {
    return nd_;
}

void studentas::setEkzam(int ekzam) {
    ekzam_ = ekzam;
}


