#include "RentingManager.h"
#include <iostream>

void RentingManager::addRent(Rent newRent) {
    newRent.setID(RentingManager::getIDRent()+1);
    RentingManager::idRent++;
    std::shared_ptr<Rent> rent = std::make_shared<Rent>(newRent);
    RentingManager::rentedItems.push_back(rent);
}

void RentingManager::deleteRent(int id) {
    //time_t returnTime;
    //returnTime = time(NULL);//get_time from jakas funkcja (MANAGER JEDNAK XD)
    //time(&returnTime);
    //returnTime += 25;
    std::shared_ptr<Rent> deletedRent = RentingManager::getRent(id);
    deletedRent->getRenter()->returnItem();
    deletedRent->getItem()->returnItem();
    RentingManager::rentedItems.erase(rentedItems.begin()+id);
    //std::cout<<difftime(returnTime, rent.getTime())<<std::endl;
    //std::cout<<rent.getRenter()->getName()<<" returned "<<rent.getItem()->getTitle()<<std::endl;
    //zapisz ze dana ksiazka spowrotem zwrocona
    //print penalty, info abour who rented etc
    //no czy ten wektor ma jakies itemy wtedy moze popnac
    //RentingManager::rentedItems.pop_back();
}

RentingManager::RentingManager() {
    RentingManager::idRent=0;
}

RentingManager::~RentingManager() {

}

double RentingManager::getSize() {
    return RentingManager::rentedItems.size();
}

bItem RentingManager::getRent(int id) {
    return rentedItems.at(id);
}

double RentingManager::getIDRent() {
    return RentingManager::idRent;
}
