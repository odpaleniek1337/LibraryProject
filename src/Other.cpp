#include "Other.h"
#include "Renter.h"

Other::Other(int id, std::string name)
        : Renter(id, name, 5, 0){
}

std::string Other::toString(){
    std::string output = "Casual Renter Mr ";
    output.append(Renter::getName());
    output.append(" with ID: ");
    output.append(std::to_string(Renter::getID()));
    output.append(" rented ");
    output.append(std::to_string(Renter::getCurrentItems()));
    output.append("/5 items");
    return output;
}

Other::~Other() {

}

