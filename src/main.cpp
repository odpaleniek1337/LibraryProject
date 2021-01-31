#include "RentingManager.h"
#include "DataBase.h"
#include <QApplication>
#include <QtWidgets>

using std::fstream;
using std::ios;
using std::stringstream;
using std::shared_ptr;
using std::make_shared;


int main(int argc, char *argv[]) {
    RentingManager es;
    DataBase base;
    es.deleteRent(1);
    es.deleteRent(2);
    base.readFile();

    int rentersSize = base.getRentersSize();
    int itemsSize = base.getItemsSize();

    QApplication app(argc, argv);
    QWidget window;
    window.resize(1080, 720);

    QTableView *usersView = new QTableView();

    QStandardItemModel usersModel;
    usersModel.setHorizontalHeaderLabels({QApplication::translate("users", "ID"),
                                          QApplication::translate("users", "Name"),
                                          QApplication::translate("users", "CurrentItems"),
                                          QApplication::translate("users", "MaxItems")});
    //users
    QList<QStandardItem*> newUsersData;
    for (int i = 0; i < rentersSize; i++) {
        std::shared_ptr<Renter> currentRenterptr = base.getRenter(i);
        newUsersData.clear();
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getID())));
        newUsersData.append(new QStandardItem(QString::fromStdString(currentRenterptr->getName())));
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getCurrentItems())));
        newUsersData.append(new QStandardItem(QString::number(currentRenterptr->getMaxItems())));
        usersModel.appendRow(newUsersData);
    }//add users to layout

    usersView->setModel(&usersModel);
    usersView->verticalHeader()->hide();
    //usersView->horizontalHeader()->setStretchLastSection(false);

    QTableView *itemsView = new QTableView();

    QStandardItemModel itemsModel;
    itemsModel.setHorizontalHeaderLabels({QApplication::translate("items", "ID"),
                                          QApplication::translate("items", "Name"),
                                          QApplication::translate("items", "Author"),
                                          QApplication::translate("items", "MaxDays"),
                                          QApplication::translate("items", "Available")});

    QList<QStandardItem*> newItemsData;
    for (int j = 0; j < itemsSize; j++) {
        std::shared_ptr<Item> currentItemptr = base.getItem(j);
        newItemsData.clear();
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getID())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getTitle())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getAuthor())));
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getDays())));
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getQuantity())));
        itemsModel.appendRow(newItemsData);
    }//add users to layout

    itemsView->setModel(&itemsModel);
    itemsView->verticalHeader()->hide();

    QHBoxLayout *upperLayout = new QHBoxLayout();
    upperLayout->addWidget(usersView);
    upperLayout->addWidget(itemsView);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(upperLayout);
    window.setLayout(mainLayout);

    window.show();
    window.setWindowTitle(QApplication::translate("users", "Library"));
    return app.exec();
}