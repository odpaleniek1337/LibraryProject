#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Item.h"

class Book : public Item {
private:
    string author;
public:
    Book(int id,string title, string author, int quantity);
    string getAuthor();
    ~Book();
};
#endif //LIBRARY_BOOK_H
