#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "AccountList.h"
#include "Function.h"
using namespace std;
class BookTicket
{
private:
    string idUser;
    int idBill;
    string trip;
    int quantity;
    float unitPrice;
    string departure;
    string detination;
    string flyDay;
    string flyReturn;
    string seatClass;
    string AirlineName;
    float totalPayment;

public:
    BookTicket();
    BookTicket(string, int, string, string, string, string, string, int, string, string, float, float);
    void setIdUser(string);
    string getIdUser();
    void setIdBill(int);
    int getIdBill();
    void setTrip(string);
    string getTrip();
    void setDeparture(string);
    string getDeparture();
    void setDetination(string);
    string getDetination();
    void setflyDay(string);
    string getflyDay();
    void setflyReturn(string);
    string getflyReturn();
    void setQuantity(int);
    int getQuantity();
    void setAirlineName(string);
    string getAirlineName();
    void setSeatClass(string);
    string getSeatClass();
    void setUnitPrice(float);
    float getUnitPrice();
    void setTotalPayment(float);
    float getTotalPayment();
    int idTicket();
    void input(ACCOUNTSLIST &, int);
    void output();
    string getID();
    void readFileBookTicket(ifstream &);
    void exportFileBookTicket(ofstream &);
    ~BookTicket();
};