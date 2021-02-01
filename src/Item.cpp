#include "Item.h"

Item::Item(int id, std::string title, std::string author, int quantity) : ID(id), title(title), author(author), quantity(quantity) {
}
Item::Item(){
    Item::ID = 0;
    Item::title = "None";
    Item::author = "None";
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

std::string Item::getTitle() {
    return Item::title;
}
std::string Item::getAuthor() {
    return Item::author;
}

void Item::takeItem() {
    Item::quantity--;

}

void Item::returnItem() {
    Item::quantity++;
}

