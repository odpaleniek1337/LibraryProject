#include "Book.h"

Book::Book(int id,std::string title, std::string author) : Item(id, title,author,  10) {
}

Book::~Book() {}



