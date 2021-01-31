#include "GUIHandler.h"

GUIHandler::GUIHandler(std::shared_ptr<DataBase> base, QWidget *parent) : QMainWindow(parent){
    GUIHandler::base = base;
    updateRentersSize(base->getRentersSize());
    updateItemsSize(base->getItemsSize());
    updateRenters();
    updateItems();
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


void GUIHandler::updateLayout() {
    upperLayout = new QHBoxLayout();
    upperLayout->addWidget(usersView); //creating upperpart of layout
    upperLayout->addWidget(itemsView);

    lowerLayout = new QHBoxLayout(); //creating lowerpart of layout

    mainLayout = new QVBoxLayout();

    mainLayout->addLayout(upperLayout);
    mainLayout->addLayout(lowerLayout);

    auto central = new QWidget;
    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void GUIHandler::updateRentersSize(int size) {
    rentersSize = size;
}

void GUIHandler::updateItemsSize(int size) {
    itemsSize = size;
}

GUIHandler::~GUIHandler() {

}

