#include "Book.h"

Book::Book(int id,string title, string author, int quantity) : Item(id, title,30, quantity) {
    Book::author = author;
}

Book::~Book() {}

string Book::getAuthor()  {
    return author;
}


