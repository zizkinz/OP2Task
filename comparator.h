//
// Created by Maksim Cizov on 2021-10-09.
//

#ifndef OP1TASK_COMPARATOR_H
#define OP1TASK_COMPARATOR_H

#endif //OP1TASK_COMPARATOR_H


bool stud_compare(studentas const &stud_1, studentas const &stud_2) {
    int p = stud_1.vard.compare(stud_2.vard);
    if (p < 0) { return true; }
    else if (p == 0) {
        int k = stud_1.pavard.compare(stud_2.pavard);
        if (k < 0) { return true; }
        else { return false; }
    } else { return false; }
}