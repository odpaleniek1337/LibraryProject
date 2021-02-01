#include <Rent.h>

Rent::Rent() {

}

Rent::~Rent() {

}

void Rent::setRent(std::shared_ptr<Item> item, std::shared_ptr<Renter> renter) {
    Rent::item = item;
    Rent::renter = renter;
    renter->addItem();
    item->takeItem();
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

