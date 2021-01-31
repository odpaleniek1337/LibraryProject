#include "RentingManager.h"
#include "DataBase.h"
#include <GUIHandler.h>


using namespace std;

int main(int argc, char *argv[]) {
    RentingManager es;
    DataBase base;
    base.readFile();

    QApplication app(argc, argv);
    GUIHandler myGUI(std::make_shared<DataBase>(base));
    myGUI.resize(1080,720);
    myGUI.setWindowTitle(QApplication::translate("main", "Library"));
    myGUI.show();
    return app.exec();
}