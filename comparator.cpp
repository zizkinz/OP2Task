#include "comparator.h"

bool stud_compare_v(studentas const &stud_1, studentas const &stud_2) {
    int p = stud_1.vard.compare(stud_2.vard);
    if (p < 0) { return true; }
    else if (p == 0) {
        int k = stud_1.pavard.compare(stud_2.pavard);
        if (k < 0) { return true; }
        else { return false; }
    } else { return false; }
}

bool stud_compare_g(studentas &stud_1, studentas &stud_2) {
    if (stud_1.gal_vid < stud_2.gal_vid){return true;}
    else {return false;}
}