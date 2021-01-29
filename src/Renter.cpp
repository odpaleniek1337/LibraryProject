#include <Renter.h>

Renter::Renter(int id, string name, int maxItems, int currentItems) : ID(id), name(name), maxItems(maxItems),
                                                                             currentItems(currentItems) {}

Renter::Renter(){
    Renter::ID = 0;
    Renter::name = 'None';
    Renter::maxItems = 0;
    Renter::currentItems = 0;
}
std::string Renter::getName() {
    return Renter::name;
}

int Renter::getID() {
    return Renter::ID;
}

int Renter::getCurrentItems() {
    return Renter::currentItems;
}

void Renter::addItem() {
    Renter::currentItems++;

}

void Renter::returnItem() {
    Renter::currentItems--;
}
