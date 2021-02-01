#include "RentingManager.h"

void RentingManager::addRent(Rent newRent) {
    newRent.setID(RentingManager::getIDRent()+1);
    RentingManager::idRent++;
    std::shared_ptr<Rent> rent = std::make_shared<Rent>(newRent);
    RentingManager::rentedItems.push_back(rent);
}

void RentingManager::deleteRent(int id) {
    std::shared_ptr<Rent> deletedRent = RentingManager::getRent(id);
    deletedRent->getRenter()->returnItem();
    deletedRent->getItem()->returnItem();
    RentingManager::rentedItems.erase(rentedItems.begin()+id);
}

RentingManager::RentingManager() {
    RentingManager::idRent=0;
}

RentingManager::~RentingManager() {

}

int RentingManager::getSize() {
    return RentingManager::rentedItems.size();
}

bItem RentingManager::getRent(int id) {
    return rentedItems.at(id);
}

int RentingManager::getIDRent() {
    return RentingManager::idRent;
}
