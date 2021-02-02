#include "RentingManager.h"
#include "DataBase.h"
#include <GUIHandler.h>


using namespace std;

int main(int argc, char *argv[]) {
    RentingManager manager;
    DataBase base;
    base.readFile(manager);
    //rents cant be seen because there are no rents currently made
    QApplication app(argc, argv);
    GUIHandler myGUI(std::make_shared<DataBase>(base), std::make_shared<RentingManager>(manager));
    myGUI.resize(1080,720);
    myGUI.setWindowTitle(QApplication::translate("main", "Library"));
    myGUI.show();
    return app.exec();
}