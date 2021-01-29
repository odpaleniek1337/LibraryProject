#include "RentingManager.h"
#include <iostream>

void RentingManager::addRent(Rent newRent) {
    std::shared_ptr<Rent> rent = std::make_shared<Rent>(newRent);
    RentingManager::rentedItems.push_back(rent);
}

void RentingManager::deleteRent(Rent oldRent/*time_t szef*/) {
    time_t returnTime;
    returnTime = time(NULL);//get_time from jakas funkcja (MANAGER JEDNAK XD)
    time(&returnTime);
    returnTime += 25;
    std::cout<<difftime(returnTime, oldRent.getTime())<<std::endl;
    Rent rent = *RentingManager::rentedItems.back();//tutaj powinno byc ze po id bierze np
    rent.getRenter()->returnItem();
    std::cout<<rent.getRenter()->getName()<<" returned "<<rent.getItem()->getTitle()<<std::endl;
    //zapisz ze dana ksiazka spowrotem zwrocona
    //print penalty, info abour who rented etc
    //no czy ten wektor ma jakies itemy wtedy moze popnac
    RentingManager::rentedItems.pop_back();
}

RentingManager::RentingManager() {

}

RentingManager::~RentingManager() {

}
