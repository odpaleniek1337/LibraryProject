#ifndef LIBRARY_GUIHANDLER_H
#define LIBRARY_GUIHANDLER_H
#include <QApplication>
#include <QtWidgets>
#include "DataBase.h"

class GUIHandler : public QMainWindow{
    Q_OBJECT
private:
    int rentersSize;
    int itemsSize;
    std::shared_ptr<DataBase> base;
public:
    GUIHandler(std::shared_ptr<DataBase> base, QWidget *parent = nullptr);
    void updateRentersSize(int size);
    void updateItemsSize(int size);
    void updateItems(QTableView &itemsView);
    ~GUIHandler();
};

#endif //LIBRARY_GUIHANDLER_H
