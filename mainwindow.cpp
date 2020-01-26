#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"

using namespace std;

//Main window things.
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

//Declaration of our reservation (used in the app).
Reservation myReservation;

//Updating _name based on input in the name textbox.
void MainWindow::on_nameTextEdit_textChanged()
{
    myReservation.setName(ui->nameTextEdit->toPlainText());
    ui->testText->setText(myReservation.name());
}
