#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <string>
using std::string;

class Item {
private:
    int ID;
    string title;
    int maxDays;
    int quantity;

public:
    Item();
    Item(int id, string title, int maxDays, int quantity);
    int getID();
    string getTitle();
    int getQuantity();
    ~Item();
};
#endif //LIBRARY_ITEM_H
