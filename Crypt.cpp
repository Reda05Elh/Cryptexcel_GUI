#include "window.h"
#include <iostream>
#include <limits>
#include <time.h>
void remv();


int crypto(QString Filepath,Window &win){
    srand(time(NULL));
    remv();

    QFile::copy(Filepath, QDir::currentPath()+"/data.xlsx");
    QFile::copy(":/Resource/com.cmd", QDir::currentPath()+"/com.cmd");
    QFile::copy(":/Resource/CSVToxlsx.vbs", QDir::currentPath()+"/CSVToxlsx.vbs");
    QProcess::startDetached(QDir::currentPath()+"/com.cmd");
    QString save = QFileDialog::getExistingDirectory(&win,"select where you want to save your Encrypted File");
    while(!QFile(QDir::currentPath()+"/data.csv").exists()){

    };

    QThread::sleep(8);

    QFile inFile(QDir::currentPath()+"/data.csv");
    char c;
    if(!inFile.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", inFile.errorString());
    }
    QFile outFile(save+"/Encrypted.Cryptex");
    if(!outFile.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", outFile.errorString());
    }
    QTextStream out(&outFile);
    while(!inFile.atEnd()){
    inFile.read(&c,sizeof (c));
    c = CHAR_MAX - c;
    out << c;
    }
    outFile.flush();
    inFile.close();
    outFile.close();


    QFile::remove(QDir::currentPath()+"/data.csv");
    QFile::remove(QDir::currentPath()+"/data.xlsx");
    QFile::remove(QDir::currentPath()+"/com.cmd");
    QFile::remove(QDir::currentPath()+"/CSVToxlsx.vbs");

    return 1;
}

void remv(){

}


