#include "GUIHandler.h"

GUIHandler::GUIHandler(std::shared_ptr<DataBase> base, std::shared_ptr<RentingManager> manager, QWidget *parent) : QMainWindow(parent){
    GUIHandler::base = base;
    GUIHandler::manager = manager;
    updateRentersSize(base->getRentersSize());
    updateItemsSize(base->getItemsSize());
    updateRentsSize(manager->getSize());
    updateRenters();
    updateItems();
    updateRents();
    createChooseButtonUsers();
    createChooseButtonItems();
    createRentButtons();
    updateLayout();
}

void GUIHandler::updateRenters() {
    usersView = new QTableView();
    usersModel.setHorizontalHeaderLabels({QApplication::translate("users", "ID"),
                                          QApplication::translate("users", "Name"),
                                          QApplication::translate("users", "CurrentItems"),
                                          QApplication::translate("users", "MaxItems")});

    QList<QStandardItem*> newUsersData;
    for (int i = 0; i < rentersSize; i++) {
        std::shared_ptr<Renter> currentRenterptr = base->getRenter(i);
        newUsersData.clear();
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getID())));
        newUsersData.append(new QStandardItem(QString::fromStdString(currentRenterptr->getName())));
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getCurrentItems())));
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getMaxItems())));
        usersModel.appendRow(newUsersData);
    }

    usersView->setModel(&usersModel);
    usersView->verticalHeader()->hide();

}

void GUIHandler::updateItems() {
    itemsView = new QTableView();
    itemsModel.setHorizontalHeaderLabels({QApplication::translate("items", "ID"),
                                          QApplication::translate("items", "Name"),
                                          QApplication::translate("items", "Author"),
                                          QApplication::translate("items", "MaxDays"),
                                          QApplication::translate("items", "Available")});

    QList<QStandardItem*> newItemsData;
    for (int j = 0; j < itemsSize; j++) {
        std::shared_ptr<Item> currentItemptr = base->getItem(j);
        newItemsData.clear();
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getID())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getTitle())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getAuthor())));
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getDays())));
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getQuantity())));
        itemsModel.appendRow(newItemsData);
    }

    itemsView->setModel(&itemsModel);
    itemsView->verticalHeader()->hide();
}


void GUIHandler::updateRents() {//nie widac, ze dziala bo nie ma zadnych rentow jeszcze
    rentsView = new QTableView();
    rentsModel.setHorizontalHeaderLabels({QApplication::translate("rents", "Renter"),
                                          QApplication::translate("rents", "Title")});

    QList<QStandardItem*> newRentsData;
    for (int i = 0; i < rentsSize; i++) {
        std::shared_ptr<Rent> currentRentptr = manager->getRent(i);
        newRentsData.clear();
        newRentsData.append(new QStandardItem(QString::fromStdString(currentRentptr->getRenter()->getName())));
        newRentsData.append(new QStandardItem(QString::fromStdString(currentRentptr->getItem()->getTitle())));
        rentsModel.appendRow(newRentsData);
    }

    rentsView->setModel(&rentsModel);
    rentsView->verticalHeader()->hide();

}

void GUIHandler::updateLayout() {

    upperLayout = new QHBoxLayout();
    upperLayout->addWidget(usersView); //creating upperpart of layout
    upperLayout->addWidget(itemsView);

    middleLayout = new QHBoxLayout();
    middleLayout->addWidget(rentsView);
    middleLayout->addWidget(deleteRentButton);

    lowerLayout = new QHBoxLayout(); //creating lowerpart of layout
    lowerLayout->addWidget(chooseBoxUser);
    lowerLayout->addWidget(chooseBoxItem);
    lowerLayout->addWidget(addRentButton);

    mainLayout = new QVBoxLayout();

    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(middleLayout);
    mainLayout->addLayout(lowerLayout);

    auto central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void GUIHandler::createChooseButtonUsers() {
    chooseBoxUser = new QComboBox;
    for(int k=0;k<rentersSize;k++)
    chooseBoxUser->addItem(QString::fromStdString(base->getRenter(k)->getName()));
}

void GUIHandler::createChooseButtonItems() {
    chooseBoxItem = new QComboBox;
    for(int k=0;k<itemsSize;k++)
        chooseBoxItem->addItem(QString::fromStdString(base->getItem(k)->getTitle()));
}

void GUIHandler::createRentButtons() {
    addRentButton = new QPushButton("Add Rent");
    deleteRentButton = new QPushButton("Delete Rent");

}

void GUIHandler::updateRentersSize(int size) {
    rentersSize = size;
}

void GUIHandler::updateItemsSize(int size) {
    itemsSize = size;
}

void GUIHandler::updateRentsSize(int size) {
    rentsSize = size;
}

GUIHandler::~GUIHandler() {

}

