#include "reservation.h"

//Default Constructor
Reservation::Reservation()
{
    setName("");
    setType_size(0);
    setType_view(0);
    setDate(QDate::currentDate());
    setLength(1);
    setNum_adults(1);
    setNum_children(0);
    setParking(false);
}

//Cost Calculations
double Reservation::calculateCost()
{
    return chargeRoom() + chargeTaxes() + chargeParking() + chargeResort();
}
double Reservation::chargeRoom()
{
    double rate = 0; //Get the rate based on room type.
    if (_type_size == sizeQueen)
    {
        if (_type_view == viewStandard) { rate = costQS; }
        else { rate = costQA; }
    }
    else
    {
        if (_type_view == viewStandard) { rate = costKS; }
        else { rate = costKA; }
    }

    //Calculate cost based on input factors.
    return rate * _length;
}
double Reservation::chargeTaxes()
{
    return chargeRoom() * taxRate;
}
double Reservation::chargeParking()
{
    if (_parking)
    {
        return costParking * _length;
    }
    return 0.00;
}
double Reservation::chargeResort()
{
    return costResort * _length;
}

//Printing reservation summary.
QString Reservation::printSummary()
{
    //Getting description of room based on options.
    QString roomDescription;
    if (_type_size == sizeQueen)
    {
       roomDescription = "an atrium 2-Queen room.";
       if (_type_view == viewStandard)
       {
           roomDescription = "a standard 2-Queen room.";
       }
    }
    else
    {
        roomDescription = "an atrium 1-King room.";
        if (_type_view == viewStandard)
        {
            roomDescription = "a standard 1-King room.";
        }
    }

    //Building the output string.
    QString output = "You have reserved with the name: " + _name;
    output += "\n--- Starting " + this->date().toString() + " for " + QString::number(length()) + " day.";
    output += "\n--- Staying in " + roomDescription;
    output += "\n--- With " + QString::number(num_adults()) + " adults and " + QString::number(num_children()) + " children.";
    output += "\n--- $" + QString::number(calculateCost()) + " paid with credit card: XXXX";

    return output;
}

//Getters and Setters Definitions
QString Reservation::name() const
{
    return _name;
}
void Reservation::setName(const QString &name)
{
    _name = name;
}
int Reservation::type_size() const
{
    return _type_size;
}
void Reservation::setType_size(int type_size)
{
    _type_size = type_size;
}
int Reservation::type_view() const
{
    return _type_view;
}
void Reservation::setType_view(int type_view)
{
    _type_view = type_view;
}
QDate Reservation::date() const
{
    return _date;
}
void Reservation::setDate(const QDate &date)
{
    _date = date;
}
int Reservation::length() const
{
    return _length;
}
void Reservation::setLength(int length)
{
    _length = length;
}
int Reservation::num_adults() const
{
    return _num_adults;
}
void Reservation::setNum_adults(int num_adults)
{
    _num_adults = num_adults;
}
int Reservation::num_children() const
{
    return _num_children;
}
void Reservation::setNum_children(int num_children)
{
    _num_children = num_children;
}
bool Reservation::parking() const
{
    return _parking;
}
void Reservation::setParking(bool parking)
{
    _parking = parking;
}
