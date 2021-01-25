#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"

class Rent {
private:
Item item;
Renter renter;
public:
    void setRent(Item item, Renter renter);
    Rent();
    ~Rent();
};
#endif //LIBRARY_RENT_H
