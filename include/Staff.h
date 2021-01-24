#ifndef LIBRARY_STAFF_H
#define LIBRARY_STAFF_H
#include "Renter.h"

class Staff: public Renter {
public:
    Staff(int ID,string name, int CurrentItems);
    ~Staff();
};
#endif //LIBRARY_STAFF_H
