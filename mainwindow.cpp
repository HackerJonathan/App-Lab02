#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "reservation.h"

#include <QMessageBox>

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
    ui->windowStack->setCurrentIndex(0);

    updateCost();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//------------------------------------------------------------------------- PAGE ONE

//Reservation name.
void MainWindow::on_nameTextEdit_textChanged()
{
    myReservation.setName(ui->nameTextEdit->toPlainText());
    ui->testText->setText(myReservation.name());

    //Enable/disable next button based on name input.
    ui->nextButtonA->setEnabled(myReservation.name() != "");
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

//Date and length settings.
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

//Parking checkbox.
void MainWindow::on_parkingCheck_stateChanged(int arg1)
{
    myReservation.setParking(arg1);
    ui->testText->setText(QString::number(myReservation.parking()));
    updateCost();
}

//Cost calculations.
void MainWindow::updateCost()
{
    int cost = myReservation.calculateCost();
    ui->costText->setText("$" + QString::number(cost) + " US");
}

//Moving to the second page.
//Also updates cost summary labels.
void MainWindow::on_nextButtonA_clicked()
{
    ui->windowStack->setCurrentIndex(1);
    ui->labelName->setText(myReservation.name());
    ui->labelChargeRoom->setText(QString::number(myReservation.chargeRoom()));
    ui->labelChargeTaxes->setText(QString::number(myReservation.chargeTaxes()));
    ui->labelChargeParking->setText(QString::number(myReservation.chargeParking()));
    ui->labelChargeResort->setText(QString::number(myReservation.chargeResort()));
    ui->labelChargeTotal->setText(QString::number(myReservation.calculateCost()));
}

//------------------------------------------------------------------------- PAGE TWO

//Back to the first page.
void MainWindow::on_backButtonB_clicked()
{
    ui->windowStack->setCurrentIndex(0);
}

//Paying with credit card info.
void MainWindow::on_visaButton_clicked()
{

}
void MainWindow::on_masterCardButton_clicked()
{

}
void MainWindow::on_discoverButton_clicked()
{

}
void MainWindow::on_amExpressButton_clicked()
{
  
}
void MainWindow::on_payButtonB_clicked()
{
    //CHECKS STILL TO DO:
    //  Only enable button when all information is filled in.
    //  Alternate message if expiration date is before current date.
    //  Alternate message if invalid credit card number.

    QMessageBox msgBox;
    msgBox.setText("Payment recieved!\n\nTotal Cost: $" + QString::number(myReservation.calculateCost()));
    msgBox.setWindowTitle(" ");
    msgBox.exec();

    ui->windowStack->setCurrentIndex(2);
    ui->labelSummary->setText(myReservation.printSummary());
}

//------------------------------------------------------------------------- PAGE THREE


void MainWindow::on_buttonExit_clicked()
{
    QApplication::quit();
}
