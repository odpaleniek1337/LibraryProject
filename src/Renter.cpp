#include <Renter.h>

int Renter::getCurrentItems() {
    return Renter::currentItems;
}

Renter::Renter(int id, string name, int maxItems, int currentItems) : ID(id), name(name), maxItems(maxItems),
                                                                             currentItems(currentItems) {}
Renter::Renter(){
    Renter::ID = 0;
    Renter::name = 'None';
    Renter::maxItems = 0;
    Renter::currentItems = 0;
}
