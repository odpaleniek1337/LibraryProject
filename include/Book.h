#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Item.h"

class Book : public Item {
private:
public:
    Book(int id,std::string title, std::string author, int quantity);
    ~Book();
};
#endif //LIBRARY_BOOK_H
