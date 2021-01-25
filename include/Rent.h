#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "BorrowedItem.h"
#include "Renter.h"

class Rent {
private:
BorrowedItem item;
Renter renter;
public:
    Rent(BorrowedItem item,Renter renter);
    ~Rent();
};
#endif //LIBRARY_RENT_H
