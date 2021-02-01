#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H
#include "Item.h"

class Book : public Item {
private:
public:
    Book(int id,std::string title, std::string author);
    virtual std::string toString() override;
    ~Book();
};
#endif //LIBRARY_BOOK_H
