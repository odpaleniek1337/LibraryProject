#include "Book.h"

Book::Book(int id,std::string title, std::string author) : Item(id, title,author,  10) {
}

Book::~Book() {}

std::string Book::toString() {
    std::string output = "Book - ";
    output.append(Item::getTitle());
    output.append(" written by ");
    output.append(Item::getAuthor());
    output.append(" with ID: ");
    output.append(std::to_string(Item::getID()));
    output.append(". Current quantity: ");
    output.append(std::to_string(Item::getQuantity()));
    return output;
}


