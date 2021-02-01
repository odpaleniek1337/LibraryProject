#ifndef LIBRARY_RENT_H
#define LIBRARY_RENT_H
#include "Item.h"
#include "Renter.h"
#include <memory>

class Rent {
private:
std::shared_ptr<Item> item;
std::shared_ptr<Renter> renter;
int id;
public:
    void setRent(std::shared_ptr<Item> item, std::shared_ptr<Renter> renter);
    std::shared_ptr<Renter> getRenter();
    std::shared_ptr<Item> getItem();
    void setID(int id);
    int getID();
    Rent();
    ~Rent();
};
#endif //LIBRARY_RENT_H
