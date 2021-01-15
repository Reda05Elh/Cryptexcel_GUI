#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <string>
#include <QChar>
#include <QThread>

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();
   void loading();
public slots:
   void Encrypt();
   void Decrypt();
   void about();

};

#endif // WINDOW_H
