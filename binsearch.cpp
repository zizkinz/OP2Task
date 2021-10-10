#include "binsearch.h"
int binsearch(vector<studentas> &grupe){
    int s = 0;
    int en = grupe.size()-1;
    int res = 0;
    while (true){
        if (en - s == 1){
            res = en;
            break;
        }

        int indx = s + (en-s)/2;
        if (grupe[indx].gal_vid < 5){s = indx;}
        else if (grupe[indx].gal_vid > 5){en = indx;}
        else {for (int j = indx;j<en;j++){if(grupe[j].gal_vid > 5){res = j;break;}}break;}
    }
    return res;
}