#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"
#include "time.h"
#include <memory>

class Rent {
private:
std::shared_ptr<Item> item;
std::shared_ptr<Renter> renter;
time_t borrowedTime;
double id;
public:
    void setRent(std::shared_ptr<Item> item, std::shared_ptr<Renter> renter);
    time_t getTime();
    std::shared_ptr<Renter> getRenter();
    std::shared_ptr<Item> getItem();
    void setID(double id);
    Rent();
    ~Rent();
};
#endif //LIBRARY_RENT_H
