#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog2.h"

#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox q(this);
    q.setText("Hello, World!");
    q.exec();
}


void MainWindow::on_pushButton_clicked()
{
    QString s;
    bool ok = false;

    while(s.isEmpty()) {
        s = QInputDialog::getText(this, "Please input your name",
                                  "Please input your name",
                                  QLineEdit::Normal,
                                  QString(), &ok);
        if(!ok) {
            return;
        }

        if(s.isEmpty()) {
            QMessageBox::critical(this, "Error",
                                  "You must enter your name!");
        }
    }

    QMessageBox q(this);
    q.setText("Hello " + s);
    q.exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About...", "Hello World version 0.42beta");
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->label_2->setText(QString::number(value));
}


void MainWindow::on_pushButton_3_clicked()
{
    Dialog2 d;

    d.exec();
}

