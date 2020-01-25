#ifndef RESERVATION_H
#define RESERVATION_H

#include <QMainWindow>
#include <QDate>
#include <string>

using namespace std;

//Reservation class declaration.
class Reservation
{
public:
    Reservation(); //Constructor

    //Getters and Setters
    string name() const;
    void setName(const string &name);
    int type_size() const;
    void setType_size(int type_size);
    int type_view() const;
    void setType_view(int type_view);
    QDate date() const;
    void setDate(const QDate &date);
    int length() const;
    void setLength(int length);
    int num_adults() const;
    void setNum_adults(int num_adults);
    int num_children() const;
    void setNum_children(int num_children);
    bool parking() const;
    void setParking(bool parking);

private: //Member variables
    string _name; //Reservation name
    int _type_size; //2 Queen or 1 King
    int _type_view; //Standard or Atrium

    QDate _date; //Starting date
    int _length; //Length of stay

    int _num_adults; //Number of adults staying
    int _num_children; //Number of children staying

    bool _parking; //Needs parking?
};

#endif // RESERVATION_H
