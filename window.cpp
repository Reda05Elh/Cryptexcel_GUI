#include "window.h"

int crypto(QString Filepath,Window &win);
int decrypto(QString Filepath,Window &win);

Window::Window() : QWidget()
{
    QPushButton *bot1 = new QPushButton("Encrypt");
    QPushButton *bot2 = new QPushButton("Decrypt");
    QPushButton *bot3 = new QPushButton("About");

    QVBoxLayout *lay = new QVBoxLayout;

    lay->addWidget(bot1);
    lay->addWidget(bot2);
    lay->addWidget(bot3);

    this->setLayout(lay);

    QObject::connect(bot1,SIGNAL(clicked()),this,SLOT(Encrypt()));
    QObject::connect(bot2,SIGNAL(clicked()),this,SLOT(Decrypt()));
    QObject::connect(bot3,SIGNAL(clicked()),this,SLOT(about()));


}

void Window::Encrypt(){

    QString Filepath = QFileDialog::getOpenFileName(this,"Select your xlsx/xls file",QString(),"xlsx/xls (*.xlsx *.xls)");

    if(!Filepath.isEmpty()){
     int test = QMessageBox::question(this, "", "<strong>Are you sure that you want to encrypt this file : </strong>\n" +Filepath, QMessageBox::Yes | QMessageBox::No);
        if((test == QMessageBox::Yes) && !Filepath.isEmpty()) {
            crypto(Filepath,*this);
        }
    }
}


void Window::Decrypt(){

    QString Filepath = QFileDialog::getOpenFileName(this,"Select your encrypted file",QString(),"(*.Cryptex)");

    if(!Filepath.isEmpty()){
     int test = QMessageBox::question(this, "", "<strong>Are you sure that you want to Decrypt this file : </strong>\n" +Filepath, QMessageBox::Yes | QMessageBox::No);
        if((test == QMessageBox::Yes) && !Filepath.isEmpty()) {
            decrypto(Filepath,*this);
        }
    }
}


void Window::about(){
 QMessageBox::information(this,"Cryptexcel","Developed by ELH Rida for learning purposes!");
}


