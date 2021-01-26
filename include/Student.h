#ifndef LIBRARY_STUDENT_H
#define LIBRARY_STUDENT_H
#include "Renter.h"

class Student: public Renter {
public:
    Student(int id, std::string name);
    virtual std::string toString() override;
    ~Student();
};
#endif //LIBRARY_STUDENT_H
