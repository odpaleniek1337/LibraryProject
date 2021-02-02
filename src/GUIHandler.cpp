#include "GUIHandler.h"
#include <iostream>

GUIHandler::GUIHandler(const std::shared_ptr<DataBase>& base, std::shared_ptr<RentingManager> manager, QWidget *parent) : QMainWindow(parent){
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
    createChooseButtonRents();
    createSaveButton();
    createRentButtons();
    updateChooseButtonRents();
    updateLayout();
}

void GUIHandler::updateRenters() {
    usersView = new QTableView();
    usersModel.clear();
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
    itemsModel.clear();
    itemsModel.setHorizontalHeaderLabels({QApplication::translate("items", "ID"),
                                          QApplication::translate("items", "Title"),
                                          QApplication::translate("items", "Author"),
                                          QApplication::translate("items", "Available")});

    QList<QStandardItem*> newItemsData;
    for (int j = 0; j < itemsSize; j++) {
        std::shared_ptr<Item> currentItemptr = base->getItem(j);
        newItemsData.clear();
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getID())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getTitle())));
        newItemsData.append(new QStandardItem(QString::fromStdString(currentItemptr->getAuthor())));
        newItemsData.append(new QStandardItem(QString::number(currentItemptr->getQuantity())));
        itemsModel.appendRow(newItemsData);
    }

    itemsView->setModel(&itemsModel);
    itemsView->verticalHeader()->hide();
}


void GUIHandler::updateRents() {
    rentsView = new QTableView();
    rentsModel.clear();
    rentsModel.setHorizontalHeaderLabels({QApplication::translate("rents", "ID"),
                                          QApplication::translate("rents", "Renter"),
                                          QApplication::translate("rents", "Title")});

    QList<QStandardItem*> newRentsData;
    for (int i = 0; i < rentsSize; i++) {
        std::shared_ptr<Rent> currentRentptr = manager->getRent(i);
        newRentsData.clear();
        newRentsData.append(new QStandardItem(QString::number(currentRentptr->getID())));
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

    middleLayout = new QHBoxLayout(); //creating middlepart of layout
    middleLayout->addWidget(rentsView);
    middleLayout->addWidget(chooseBoxRent);
    middleLayout->addWidget(deleteRentButton);
    middleLayout->addWidget(saveButton);

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

void GUIHandler::createChooseButtonRents() {
    chooseBoxRent = new QComboBox;
}
void GUIHandler::updateChooseButtonRents() {
    chooseBoxRent->clear();
    for (int k = 0; k < rentsSize; k++) {
        chooseBoxRent->addItem(QString::number(manager->getRent(k)->getID()));
    }
}

void GUIHandler::createRentButtons() {
    addRentButton = new QPushButton(this);
    addRentButton->setText("Borrow");
    connect(addRentButton, SIGNAL(clicked()),this,SLOT(addRentButton_clicked()));
    deleteRentButton = new QPushButton(this);
    deleteRentButton->setText("Delete Rent");
    connect(deleteRentButton, SIGNAL(clicked()),this,SLOT(deleteRentButton_clicked()));
}

void GUIHandler::createSaveButton(){
    saveButton = new QPushButton(this);
    saveButton->setText("Save to File");
    connect(saveButton, SIGNAL(clicked()),this,SLOT(saveButton_clicked()));

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

void GUIHandler::addRentButton_clicked() {
    int userID = chooseBoxUser->currentIndex();
    int itemID = chooseBoxItem->currentIndex();
    std::shared_ptr<Renter> newRenter = GUIHandler::base->getRenter(userID);
    std::shared_ptr<Item> newItem = GUIHandler::base->getItem(itemID);
    if ( (newRenter->getCurrentItems() < newRenter->getMaxItems() ) && ( newItem->getQuantity() > 0 ) ) {
        Rent newRent;
        newRent.setRent(newItem, newRenter);
        GUIHandler::manager->addRent(newRent);
        GUIHandler::updateRentsSize(manager->getSize());
        GUIHandler::updateRenters();
        GUIHandler::updateItems();
        GUIHandler::updateRents();
        GUIHandler::updateChooseButtonRents();
        std::cout<<newRenter->getName()<<" borrowed "<<newItem->getTitle()<<std::endl;
    }
    else {
        QMessageBox msgBox;
        std::string text = newRenter->getName() + " cannot borrow " + newItem->getTitle() + "!";
        msgBox.setText(QString::fromStdString(text));
        msgBox.exec();
        std::cout<<"Limit reached! "<<newRenter->getName() + " cannot borrow " + newItem->getTitle() +"!"<<std::endl;
    }
}

void GUIHandler::deleteRentButton_clicked() {
    int rentID = chooseBoxRent->currentIndex();
    if(manager->getSize()>0){
        std::cout<<manager->getRent(rentID)->getRenter()->getName()<<" returned "<<manager->getRent(rentID)->getItem()->getTitle()<<std::endl;
        GUIHandler::manager->deleteRent(rentID);
        GUIHandler::updateRentsSize(manager->getSize());
        GUIHandler::updateRenters();
        GUIHandler::updateItems();
        GUIHandler::updateRents();
        GUIHandler::updateChooseButtonRents();
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("No rents left to delete!");
        msgBox.exec();
        std::cout<<"No Rents left to delete"<<std::endl;
    }
}

void GUIHandler::saveButton_clicked() {
    GUIHandler::base->saveFile(*GUIHandler::manager);
}

GUIHandler::~GUIHandler() {

}
