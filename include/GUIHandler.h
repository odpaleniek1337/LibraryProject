#ifndef LIBRARY_GUIHANDLER_H
#define LIBRARY_GUIHANDLER_H
#include <QApplication>
#include <QtWidgets>
#include "DataBase.h"
#include "RentingManager.h"

class GUIHandler : public QMainWindow{
    Q_OBJECT
private:
    int rentersSize;
    int itemsSize;
    int rentsSize;
    std::shared_ptr<DataBase> base;
    std::shared_ptr<RentingManager> manager;
public:
    GUIHandler(std::shared_ptr<DataBase> base, std::shared_ptr<RentingManager> manager, QWidget *parent = nullptr);
    QTableView *usersView;
    QStandardItemModel usersModel;

    QTableView *itemsView;
    QStandardItemModel itemsModel;

    QTableView *rentsView;
    QStandardItemModel rentsModel;

    QComboBox *chooseBoxUser;
    QComboBox *chooseBoxItem;
    QComboBox *chooseBoxRent;
    QPushButton *addRentButton;
    QPushButton *deleteRentButton;

    QHBoxLayout *upperLayout;
    QHBoxLayout *middleLayout;
    QHBoxLayout *lowerLayout;
    QVBoxLayout *mainLayout;

    void updateRenters();
    void updateItems();
    void updateLayout();
    void updateRents();
    void createChooseButtonUsers();
    void createChooseButtonItems();
    void createChooseButtonRents();
    void createRentButtons();
    void updateRentersSize(int size);

    void updateItemsSize(int size);
    void updateRentsSize(int size);
    void updateChooseButtonRents();
    ~GUIHandler();

public slots:
    void addRentButton_clicked();
    void deleteRentButton_clicked();

};

#endif //LIBRARY_GUIHANDLER_H
