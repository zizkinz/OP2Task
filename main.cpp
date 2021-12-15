#include "libai.h"
#include "studentas.h"


int main() {
studentas st1(10,"Antanas","Smetona");

vector<int> nd = {5, 4, 5, 7, 9};
st1.fillNd(nd);

cout<<st1<<endl;

studentas st3 = st1;
cin>>st3;

cout<<st1<<endl<<st3<<endl;

}