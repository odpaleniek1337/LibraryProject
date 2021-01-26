#include <Rent.h>

Rent::Rent() {

}

Rent::~Rent() {

}

void Rent::setRent(Item item, std::shared_ptr<Renter> renter) {
    Rent::item = item;
    Rent::renter = renter;
    Rent::borrowedTime = time(NULL);
    time(&borrowedTime);
}

