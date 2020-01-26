#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"

#include <cmath>

using namespace std;

//Declaration of our reservation (used in the app).
Reservation myReservation;

//Main window things.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initializing various defaults.
    ui->startDate->setDate(QDate::currentDate());
    ui->startDate->setDateRange(QDate::currentDate(), QDate::currentDate().addYears(1));

    updateCost();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Updating _name based on input in the name textbox.
void MainWindow::on_nameTextEdit_textChanged()
{
    myReservation.setName(ui->nameTextEdit->toPlainText());
    ui->testText->setText(myReservation.name());
}

//Room type settings.
void MainWindow::on_radioSizeA_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_size(sizeQueen);
        updatePeopleBounds();
        ui->testText->setText(QString::number(myReservation.type_size()));
        updateCost();
    }
}
void MainWindow::on_radioSizeB_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_size(sizeKing);
        updatePeopleBounds();
        ui->testText->setText(QString::number(myReservation.type_size()));
        updateCost();
    }
}
void MainWindow::on_radioViewA_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_view(viewStandard);
        ui->testText->setText(QString::number(myReservation.type_view()));
        updateCost();
    }
}
void MainWindow::on_radioViewB_clicked(bool checked)
{
    if (checked)
    {
        myReservation.setType_view(viewAtrium);
        ui->testText->setText(QString::number(myReservation.type_view()));
        updateCost();
    }
}

//Date/Length settings
void MainWindow::on_startDate_userDateChanged(const QDate &date)
{
    myReservation.setDate(date);
    ui->testText->setText((myReservation.date()).toString());
}
void MainWindow::on_lengthBox_valueChanged(int arg1)
{
    myReservation.setLength(arg1);
    ui->testText->setText(QString::number(myReservation.length()));
    updateCost();
}

//Numbers of people for the reservation.
void MainWindow::on_numAdultsBox_valueChanged(int arg1)
{
    myReservation.setNum_adults(arg1);
    updatePeopleBounds();
}
void MainWindow::on_numChildrenBox_valueChanged(int arg1)
{
    myReservation.setNum_children(arg1);
    updatePeopleBounds();
}
void MainWindow::updatePeopleBounds()
{
    int numAdults = myReservation.num_adults();
    int numChildren = myReservation.num_children();

    //Calculating max based on type.
    int maxPeople = 4;
    if (myReservation.type_size() == sizeKing)
    {
        //Adjust bounds if current number excceeds limit.
        maxPeople = 3;
        if (numAdults + numChildren > maxPeople)
        {
            if (numChildren > 0) { numChildren --; }
            else { numAdults --; }
        }
    }

    //Update maximums for both boxes to only allow valid combinations.
    ui->numAdultsBox->setMaximum(maxPeople - numChildren);
    ui->numChildrenBox->setMaximum(maxPeople - numAdults);
}

//Parking checkbox
void MainWindow::on_parkingCheck_stateChanged(int arg1)
{
    myReservation.setParking(arg1);
    ui->testText->setText(QString::number(myReservation.parking()));
    updateCost();
}

//Cost Calculations
void MainWindow::updateCost()
{
    int cost = myReservation.calculateCost();
    ui->costText->setText("$" + QString::number(cost) + " US");
}
