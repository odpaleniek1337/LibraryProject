#include "Book.h"

Book::Book(int id,std::string title, std::string author, int quantity) : Item(id, title,author, 30, quantity) {
}

Book::~Book() {}



