#ifndef LIBRARY_OTHER_H
#define LIBRARY_OTHER_H
#include "Renter.h"

class Other: public Renter {
public:
    Other(int ID,string name, int CurrentItems);
    ~Other();
};
#endif //LIBRARY_OTHER_H
