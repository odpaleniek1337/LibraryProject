#include "RentingManager.h"
#include <iostream>

void RentingManager::addRent(Rent newRent) {
    double size = RentingManager::getSize();
    newRent.setID(size+1);
    std::shared_ptr<Rent> rent = std::make_shared<Rent>(newRent);
    RentingManager::rentedItems.push_back(rent);
}

void RentingManager::deleteRent(int id) {
    time_t returnTime;
    returnTime = time(NULL);//get_time from jakas funkcja (MANAGER JEDNAK XD)
    time(&returnTime);
    returnTime += 25;
    Rent rent = *RentingManager::rentedItems.back();//tutaj powinno byc ze po id bierze np //id-1 powinno byc, bo zaczniemy id od 1,2,3,4,5 etc a nie 0,1,2,3,4
    std::cout<<difftime(returnTime, rent.getTime())<<std::endl;
    rent.getRenter()->returnItem();
    rent.getItem()->returnItem();
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

double RentingManager::getSize() {
    return RentingManager::rentedItems.size();
}

bItem RentingManager::getRent(int id) {
    return rentedItems.at(id);
}
