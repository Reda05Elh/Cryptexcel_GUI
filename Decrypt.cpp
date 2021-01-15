#include "window.h"
#include <iostream>
#include <limits>
#include <time.h>
void remv();


int decrypto(QString Filepath,Window &win){
    srand(time(NULL));
    remv();
    QFile::copy(Filepath, QDir::currentPath()+"/Encrypt.txt");
    QFile::copy(":/Resource/recom.cmd", QDir::currentPath()+"/recom.cmd");
    QFile::copy(":/Resource/CSVToxlsx.vbs", QDir::currentPath()+"/CSVToxlsx.vbs");

    QFile inFile(QDir::currentPath()+"/Encrypt.txt");
    if(!inFile.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "error", inFile.errorString());
    }

    QFile outFile(QDir::currentPath()+"/Data.csv");
    if(!outFile.open(QIODevice::WriteOnly)){
        QMessageBox::information(0, "error", outFile.errorString());
    }
    QTextStream out(&outFile);
    char c;
    while(!inFile.atEnd()){
        inFile.getChar(&c);
        c = CHAR_MAX - c;
        out << c;
    }
    outFile.flush();
    outFile.close();
    inFile.close();

    QProcess::startDetached(QDir::currentPath()+"//recom.cmd");
    QString save = QFileDialog::getExistingDirectory(&win,"select where you want to save your Decrypted File");
    QThread::sleep(10);
    while(!QFile(QDir::currentPath()+"/Data.xlsx").exists()){
    };

    QFile::remove(QDir::currentPath()+"//Data.csv");
    QFile::remove(QDir::currentPath()+"/Encrypt.txt");
    QFile::copy(QDir::currentPath()+"/Data.xlsx", save+"/Data.xlsx");
    QFile::remove(QDir::currentPath()+"/Data.xlsx");
    QFile::remove(QDir::currentPath()+"/CSVToxlsx.vbs");
    QFile::remove(QDir::currentPath()+"/com.cmd");

    return 1;
}
