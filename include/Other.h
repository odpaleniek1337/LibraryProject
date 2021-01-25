#ifndef LIBRARY_OTHER_H
#define LIBRARY_OTHER_H
#include "Renter.h"

class Other: public Renter {
public:
    Other(int id, string name);
    ~Other();
};
#endif //LIBRARY_OTHER_H