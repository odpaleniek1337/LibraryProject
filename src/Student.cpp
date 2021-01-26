#include <Student.h>

Student::Student(int id, std::string name)
        : Renter(id, name, 15, 0){

}

Student::~Student() {

}

std::string Student::toString() {
    std::string output = "Student Renter Mr ";
    output.append(Renter::getName());
    output.append(" with ID: ");
    output.append(std::to_string(Renter::getID()));
    output.append(" rented ");
    output.append(std::to_string(Renter::getCurrentItems()));
    output.append("/15 items");
    return output;
}

