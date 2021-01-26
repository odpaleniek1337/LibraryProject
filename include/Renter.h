#ifndef LIBRARY_RENTER_H
#define LIBRARY_RENTER_H
#include <string>
using std::string;

class Renter {
private:
    int ID;
    std::string name;
    int maxItems;
    int currentItems;
public:
    Renter();
    Renter(int id, std::string name, int maxItems, int currentItems);
    std::string getName();
    int getID();
    virtual std::string toString() = 0;
    int getCurrentItems();
};
#endif //LIBRARY_RENTER_H