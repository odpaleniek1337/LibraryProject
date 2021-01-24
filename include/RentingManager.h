#ifndef LIBRARY_RENTINGMANAGER_H
#define LIBRARY_RENTINGMANAGER_H
#include <vector>
#include <memory>
#include <string>
#include "Renter.h"

using std::string;
using std::vector;

class BorrowedItem;
typedef std::shared_ptr<BorrowedItem> bItem;

class RentingManager {
private:
    vector<bItem> rentedItems;
public:
    RentingManager(string repository);
    ~RentingManager();
    void addRent(BorrowedItem newItem,Renter renter);
    void deleteRent(BorrowedItem oldItem,Renter renter);
};
#endif //LIBRARY_RENTINGMANAGER_H