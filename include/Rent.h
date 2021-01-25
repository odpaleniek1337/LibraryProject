#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"
#include "time.h"

class Rent {
private:
Item item;
Renter renter;
time_t borrowedTime;
public:
    void setRent(Item item, Renter renter);
    Rent();
    ~Rent();
};
#endif //LIBRARY_RENT_H
