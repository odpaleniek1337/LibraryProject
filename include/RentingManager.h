#ifndef LIBRARY_RENTINGMANAGER_H
#define LIBRARY_RENTINGMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Rent.h"
using std::string;
using std::vector;

typedef std::shared_ptr<Rent> bItem;

class RentingManager {
private:
    vector<bItem> rentedItems;
    double idRent;
public:
    RentingManager();
    ~RentingManager();
    void addRent(Rent newRent);
    void deleteRent(int id);
    bItem getRent(int id);
    double getSize();
    double getIDRent();
};
#endif //LIBRARY_RENTINGMANAGER_H