#ifndef LIBRARY_STAFF_H
#define LIBRARY_STAFF_H
#include "Renter.h"

class Staff: public Renter {
public:
    Staff(int id, std::string name);
    virtual std::string toString() override;
    ~Staff();
};
#endif //LIBRARY_STAFF_H
