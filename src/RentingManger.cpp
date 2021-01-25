#include "RentingManager.h"

void RentingManager::addRent(Rent newRent) {
    std::shared_ptr<Rent> rent = std::make_shared<Rent>(newRent);
    RentingManager::rentedItems.push_back(rent);
}

void RentingManager::deleteRent(Rent oldRent/*time_t szef*/) {
    Rent rent = *RentingManager::rentedItems.back();
    //get current time- calculate days something was rented
    //rent.renter
    //print penalty, info abour who rented etc
    //no czy ten wektor ma jakies itemy wtedy moze popnac
    RentingManager::rentedItems.pop_back();
}

RentingManager::RentingManager() {

}

RentingManager::~RentingManager() {

}
