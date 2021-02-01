#include <Rent.h>

Rent::Rent() {

}

Rent::~Rent() {

}

void Rent::setRent(std::shared_ptr<Item> item, std::shared_ptr<Renter> renter) {
    //if quantity > 0;
    Rent::item = item;
    Rent::renter = renter;
    time_t currentTime;
    time(&currentTime);
    Rent::borrowedTime = localtime(&currentTime);
    renter->addItem();
    item->takeItem();
}

tm* Rent::getTime() {
    return Rent::borrowedTime;
}

std::shared_ptr<Renter> Rent::getRenter() {
    return Rent::renter;
}

std::shared_ptr<Item> Rent::getItem() {
    return Rent::item;
}

void Rent::setID(double id) {
    Rent::id = id;

}
double Rent::getID() {
    return Rent::id;

}

