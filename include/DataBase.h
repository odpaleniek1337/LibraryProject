#ifndef LIBRARY_DATABASE_H
#define LIBRARY_DATABASE_H
#include "Renter.h"
#include "Item.h"
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

typedef std::shared_ptr<Renter> renter;
typedef std::shared_ptr<Item> item;

class DataBase{
private:
    std::vector<renter> renters;
    std::vector<item> items;
public:
    DataBase();
    ~DataBase();
    void readFile();
    void addRenter(renter newRenter);
    void addItem(item newItem);
    renter getRenter(int id);
    item getItem(int id);
};

#endif //LIBRARY_DATABASE_H
