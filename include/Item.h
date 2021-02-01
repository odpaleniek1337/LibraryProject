#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
using std::string;

class Item {
private:
    int ID;
    int quantity;
    std::string title;
    std::string author;
public:
    Item();
    Item(int id, std::string title, std::string author, int quantity);
    int getID();
    int getQuantity();
    std::string getTitle();
    std::string getAuthor();
    virtual std::string toString() = 0;
    void takeItem();
    void returnItem();
    ~Item();
};
#endif //LIBRARY_ITEM_H
