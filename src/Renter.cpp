#include <Renter.h>

int Renter::getCurrentItems() {
    return currentItems;
}

Renter::Renter(int id, const string &name, int maxItems, int currentItems) : ID(id), name(name), maxItems(maxItems),
                                                                             currentItems(currentItems) {}

