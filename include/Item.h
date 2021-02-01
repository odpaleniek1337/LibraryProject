#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
using std::string;

class Item {
private:
    int ID;
    std::string title;
    std::string author;
    int quantity;
public:
    Item();
    Item(int id, std::string title, std::string author, int quantity);
    int getID();
    std::string getTitle();
    std::string getAuthor();
    int getQuantity();
    void takeItem();
    void returnItem();
    ~Item();
};
#endif //LIBRARY_ITEM_H
