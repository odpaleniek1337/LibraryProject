#include "Staff.h"

Staff::Staff(int id, std::string name)
        : Renter(id, name, 5, 0) {
}

Staff::~Staff() {

}

std::string Staff::toString() {
    std::string output = "Professor Renter Mr ";
    output.append(Renter::getName());
    output.append(" with ID: ");
    output.append(std::to_string(Renter::getID()));
    output.append(" rented ");
    output.append(std::to_string(Renter::getCurrentItems()));
    output.append("/5 items");
    return output;
}

