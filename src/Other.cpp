#include "Other.h"
#include "Renter.h"

Other::Other(int id, std::string name)
        : Renter(id, name, 2, 0){
}

std::string Other::toString(){
    std::string output = "Casual Renter Mr ";
    output.append(Renter::getName());
    output.append(" with ID: ");
    output.append(std::to_string(Renter::getID()));
    output.append(" rented ");
    output.append(std::to_string(Renter::getCurrentItems()));
    output.append("/2 items");
    return output;
}

Other::~Other() {

}

