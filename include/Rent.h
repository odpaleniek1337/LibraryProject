#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"

class Rent {
private:
Item item;
Renter renter;
public:
    Rent(Item item, Renter renter);
    ~Rent();
};
#endif //LIBRARY_RENT_H
