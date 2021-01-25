#include "Item.h"

Item::Item(int id, string title, int maxDays, int quantity) : ID(id), title(title), maxDays(maxDays),
                                                                     quantity(quantity) {
    Item::setBorrowedTime();
}
Item::Item(){
    Item::ID = 0;
    Item::title = 'None';
    Item::maxDays = 0;
    Item::quantity = 0;
}

void Item::setBorrowedTime() {
    Item::borrowTime = "DD/MM/YYYY";
}

int Item::getID() {
    return Item::ID;
}

string Item::getBorrowedTime() {
    return Item::borrowTime;
}

int Item::getQuantity() {
    return Item::quantity;
}

Item::~Item() {

}
