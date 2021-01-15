#include "window.h"

int main(int argc, char* argv[]){

    QApplication app(argc,argv);
    app.setApplicationDisplayName("Cryptexcel");
    app.setWindowIcon(QIcon("C://Users//Pc//Documents//icon.png"));
    Window win;
    win.setFixedSize(250,400);
    win.show();
    return app.exec();
}
