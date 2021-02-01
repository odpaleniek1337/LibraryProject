#include "Movie.h"

Movie::Movie(int id, std::string title, std::string director) : Item(id, title, director,  5) {
}

Movie::~Movie() {

}

std::string Movie::toString() {
    std::string output = "Movie - ";
    output.append(Item::getTitle());
    output.append(" directed by ");
    output.append(Item::getAuthor());
    output.append(" with ID: ");
    output.append(std::to_string(Item::getID()));
    output.append(". Current quantity: ");
    output.append(std::to_string(Item::getQuantity()));
    return output;
}