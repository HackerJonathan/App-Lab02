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

//ui->dateEdit->setDate(QDate::currentDate());
//ui->dateEdit->setDate(QDate::currentDate())

//Updating _name based on input in the name textbox.
void MainWindow::on_nameTextEdit_textChanged()
{
    myReservation.setName(ui->nameTextEdit->toPlainText());
    ui->testText->setText(myReservation.name()); //Outputting to test to check
}

void MainWindow::on_radioSizeA_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_size(0);
        ui->testText->setText(QString::number(myReservation.type_size()));
    }
}

void MainWindow::on_radioSizeB_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_size(1);
        ui->testText->setText(QString::number(myReservation.type_size()));
    }
}

void MainWindow::on_radioViewA_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_view(0);
        ui->testText->setText(QString::number(myReservation.type_view()));
    }
}

void MainWindow::on_radioViewB_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_view(1);
        ui->testText->setText(QString::number(myReservation.type_view()));
    }
}

void MainWindow::on_startDate_userDateChanged(const QDate &date)
{
    myReservation.setDate(date);
    ui->testText->setText((myReservation.date()).toString());
}
