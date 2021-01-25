#include <Rent.h>

Rent::Rent() {

}

Rent::~Rent() {

}

void Rent::setRent(Item item, Renter renter) {
    Rent::item = item;
    Rent::renter = renter;
}

