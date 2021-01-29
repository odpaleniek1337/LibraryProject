#include <Rent.h>
#include <iostream>

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

time_t Rent::getTime() {
    return Rent::borrowedTime;
}

