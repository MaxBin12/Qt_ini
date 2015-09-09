#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QSettings"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
        //Qt中使用QSettings类读写ini文件
        //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
        QSettings *configIniWrite = new QSettings("./conf.ini", QSettings::IniFormat);
        //向ini文件中写入内容,setValue函数的两个参数是键值对
        //向ini文件的第一个节写入内容,ip节下的第一个参数
        QString who = ui->textEdit->toPlainText();
        QString where = ui->textEdit_2->toPlainText();
        QString when = ui->textEdit_3->toPlainText();
        QString what = ui->textEdit_4->toPlainText();
        configIniWrite->setValue("/Configure/when", when);
        //向ini文件的第一个节写入内容,ip节下的第二个参数
        configIniWrite->setValue("/Configure/where", where);
        //向ini文件的第二个节写入内容,port节下的第一个参数
        configIniWrite->setValue("/Configure/who", who);
        configIniWrite->setValue("/Configure/what", what);
        //写入完成后删除指针
        delete configIniWrite;
}

void MainWindow::on_pushButton_2_clicked()
{
       QSettings *configIniRead = new QSettings("./conf.ini", QSettings::IniFormat);
       //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
       QString who = configIniRead->value("/Configure/who").toString();
       QString where = configIniRead->value("/Configure/where").toString();
       QString when = configIniRead->value("/Configure/when").toString();
       QString what = configIniRead->value("/Configure/what").toString();
       ui->textEdit->insertPlainText(who);
       ui->textEdit_2->insertPlainText(where);
       ui->textEdit_3->insertPlainText(when);
       ui->textEdit_4->insertPlainText(what);
       //读入入完成后删除指针
       delete configIniRead;
}
