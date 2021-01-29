#include <Rent.h>

Rent::Rent() {

}

Rent::~Rent() {

}

void Rent::setRent(std::shared_ptr<Item> item, std::shared_ptr<Renter> renter) {
    Rent::item = item;
    Rent::renter = renter;
    Rent::borrowedTime = time(NULL);
    time(&borrowedTime);
    renter->addItem();
}

time_t Rent::getTime() {
    return Rent::borrowedTime;
}

std::shared_ptr<Renter> Rent::getRenter() {
    return Rent::renter;
}

std::shared_ptr<Item> Rent::getItem() {
    return Rent::item;
}

