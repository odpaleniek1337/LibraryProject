#ifndef LIBRARY_OTHER_H
#define LIBRARY_OTHER_H
#include "Renter.h"

class Other: public Renter {
public:
    Other(int id, std::string name);
    virtual std::string toString() override;
    ~Other();
};
#endif //LIBRARY_OTHER_H