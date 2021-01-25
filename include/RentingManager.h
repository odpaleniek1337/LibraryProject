#ifndef LIBRARY_RENTINGMANAGER_H
#define LIBRARY_RENTINGMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Rent.h"

using std::string;
using std::vector;

class Rent;
typedef std::shared_ptr<Rent> bItem;

class RentingManager {
private:
    vector<bItem> rentedItems;
public:
    RentingManager();
    ~RentingManager();
    void addRent(Rent newRent);
    void deleteRent(Rent oldRent);
};
#endif //LIBRARY_RENTINGMANAGER_H