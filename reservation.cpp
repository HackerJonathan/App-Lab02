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

//Getters and Setters Definitions
QString Reservation::name() const
{
    return _name;
}
//HI
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
