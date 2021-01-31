#include "Item.h"

Item::Item(int id, string title, int maxDays, int quantity) : ID(id), title(title), maxDays(maxDays),
                                                                     quantity(quantity) {
}
Item::Item(){
    Item::ID = 0;
    Item::title = "None";
    Item::maxDays = 0;
    Item::quantity = 0;
}

int Item::getID() {
    return Item::ID;
}


int Item::getQuantity() {
    return Item::quantity;
}

Item::~Item() {

}

string Item::getTitle() {
    return Item::title;
}

void Item::takeItem() {
    Item::quantity--;

}

void Item::returnItem() {
    Item::quantity++;
}

int Item::getDays() {
    return Item::maxDays;
}
