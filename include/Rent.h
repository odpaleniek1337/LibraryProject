#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"
#include "time.h"
#include <memory>

class Rent {
private:
Item item;//also shared_ptr/unique
std::shared_ptr<Renter> renter;
time_t borrowedTime;
public:
    void setRent(Item item, std::shared_ptr<Renter> renter);
    Rent();
    ~Rent();
};
#endif //LIBRARY_RENT_H
