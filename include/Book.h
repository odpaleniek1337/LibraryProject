#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "BorrowedItem.h"

class Book : public BorrowedItem {
private:
    string author;
public:
    Book(int ID, string title, string author, int quantity);
    ~Book();
};
#endif //LIBRARY_BOOK_H
