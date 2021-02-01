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
    int idRent;
public:
    RentingManager();
    ~RentingManager();
    void addRent(Rent newRent);
    void deleteRent(int id);
    bItem getRent(int id);
    int getSize();
    int getIDRent();
};
#endif //LIBRARY_RENTINGMANAGER_H