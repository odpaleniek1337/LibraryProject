#ifndef LIBRARY_STUDENT_H
#define LIBRARY_STUDENT_H
#include "Renter.h"

class Student: public Renter {
public:
    Student(int id, const string &name);
    ~Student();
};
#endif //LIBRARY_STUDENT_H
