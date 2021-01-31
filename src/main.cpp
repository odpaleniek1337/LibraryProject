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
    //es.deleteRent(1);
    //es.deleteRent(2);
    base.readFile();

    QApplication app(argc, argv);
    QWidget window;
    window.resize(1080, 720);
    window.show();
    window.setWindowTitle(QApplication::translate("childwidget", "Library"));
    QLabel *users = new QLabel(QApplication::translate("childwidget", "List of Users"), &window);
    users->show();
    return app.exec();
}