#include "BookTicket.h"

BookTicket::BookTicket(){};
BookTicket::BookTicket(string idUser, int idBill, string trip, string departure, string detination, string flyDay, string flyReturn, int quantity, string AirlineName, string seatClass, float unitPrice, float totalPayment)
{
    this->idUser = idUser;
    this->idBill = idBill;
    this->trip = trip;
    this->departure = departure;
    this->detination = detination;
    this->flyDay = flyDay;
    this->flyReturn = flyReturn;
    this->quantity = quantity;
    this->AirlineName = AirlineName;
    this->seatClass = seatClass;
    this->unitPrice = unitPrice;
    this->totalPayment = totalPayment;
}
void BookTicket::setIdUser(string idUser)
{
    this->idUser = idUser;
}
string BookTicket::getIdUser()
{
    return idUser;
}
void BookTicket::setIdBill(int idBill)
{
    this->idBill = idBill;
}
int BookTicket::getIdBill()
{
    return idBill;
}
void BookTicket::setTrip(string trip)
{
    this->trip = trip;
}
string BookTicket::getTrip()
{
    return trip;
}
void BookTicket::setDeparture(string departure)
{
    this->departure = departure;
}
string BookTicket::getDeparture()
{
    return departure;
}
void BookTicket::setDetination(string)
{
    this->detination = detination;
}
string BookTicket::getDetination()
{
    return detination;
}
void BookTicket::setflyDay(string)
{
    this->flyDay = flyDay;
}
string BookTicket::getflyDay()
{
    return flyDay;
}
void BookTicket::setflyReturn(string flyReturn)
{
    this->flyReturn = flyReturn;
}
string BookTicket::getflyReturn()
{
    return flyReturn;
}
void BookTicket::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int BookTicket::getQuantity()
{
    return quantity;
}
void BookTicket::setUnitPrice(float unitPrice)
{
    this->unitPrice = unitPrice;
}
void BookTicket::setAirlineName(string)
{
    this->AirlineName = AirlineName;
}
string BookTicket::getAirlineName()
{
    return AirlineName;
}
void BookTicket::setSeatClass(string seatClass)
{
    this->seatClass = seatClass;
}
string BookTicket::getSeatClass()
{
    return seatClass;
}
float BookTicket::getUnitPrice()
{
    return unitPrice;
}
void BookTicket::setTotalPayment(float)
{
    this->totalPayment = totalPayment;
}
float BookTicket::getTotalPayment()
{
    return totalPayment;
}
int BookTicket::idTicket()
{
    int ramdom;
    ramdom = rand();
    return ramdom;
}

void BookTicket::readFileBookTicket(ifstream &inFile)
{
    char x;
    getline(inFile, this->idUser, ',');
    inFile >> this->idBill;
    inFile >> x;
    getline(inFile, this->trip, ',');
    getline(inFile, this->departure, ',');
    getline(inFile, this->detination, ',');
    getline(inFile, this->flyDay, ',');
    getline(inFile, this->flyReturn, ',');
    inFile >> this->quantity;
    inFile >> x;
    getline(inFile, this->AirlineName, ',');
    getline(inFile, this->seatClass, ',');
    inFile >> this->unitPrice;
    inFile >> x;
    inFile >> this->totalPayment;
    inFile.ignore();
}
void BookTicket::exportFileBookTicket(ofstream &outFile)
{
    idBill = idTicket();
    outFile << this->idUser << ",";
    outFile << idBill << ",";
    outFile << this->trip << ",";
    outFile << this->departure << ",";
    outFile << this->detination << ",";
    outFile << this->flyDay << ",";
    outFile << this->flyReturn << ",";
    outFile << this->quantity << ",";
    outFile << this->AirlineName << ",";
    outFile << this->seatClass << ",";
    outFile << this->unitPrice << ",";
    outFile << this->totalPayment << ",";
}

void BookTicket::input(ACCOUNTSLIST &acc, int index)
{
    this->idUser = acc.getAccountsList()[index]->getId();
    cout << "\n\n\t\t\t\tTRIP" << endl;
    cout << "\t\t\t\t1. One way"
         << "     "
         << "2. Round-trip" << endl;
    int selection;
    cout << "\t\t\t\tPlease enter your selection: ";
    cin >> selection;
    if (selection == 1)
    {
        trip = "One way";
    }
    if (selection == 2)
    {
        trip = "Round-trip";
    }
    cin.ignore();
    cout << "\t\t\t\tPoint of departure: ";
    getline(cin, departure);
    standardizeName(departure);
    cout << "\t\t\t\tDestination: ";
    getline(cin, detination);
    standardizeName(detination);
    cout << "\t\t\t\tDate of departure(DD/MM/YYYY): ";
    cin >> flyDay;
    if (selection == 2)
    {
        cout << "\t\t\t\tDate of destination(DD/MM/YYYY): ";
        cin >> flyReturn;
    }
    cout << "\t\t\t\tNumber of passengers: ";
    cin >> quantity;
    cout << "\t\t\t\tName of Airline: ";
    cin.ignore();
    getline(cin, AirlineName);
    standardizeName(AirlineName);
    cout << "\t\t\t\tSeat class(Trader/Common): ";
    cin >> seatClass;
    standardizeName(seatClass);
    cout << "\t\t\t\tTicket price: ";
    cin >> unitPrice;
    if (selection == 1)
    {
        totalPayment = quantity * unitPrice;
    }
    if (selection == 2)
    {
        totalPayment = quantity * unitPrice * 2;
    }
}
string BookTicket::getID()
{
    return this->idUser;
}
void BookTicket::output()
{
    // cout << "\t\t\t\tCustomer ID: " << this->idUser << endl;
    cout << "\t\t\t\tBook Ticket ID: " << this->idBill << endl;
    cout << "\t\t\t\tOne way/ Round-trip: " << this->trip << endl;
    cout << "\t\t\t\tPoint of departure: " << this->departure << endl;
    cout << "\t\t\t\tDestination: " << this->detination << endl;
    cout << "\t\t\t\tDate of departure(DD/MM/YYYY): " << this->flyDay << endl;
    cout << "\t\t\t\tDate of destination(DD/MM/YYYY): " << this->flyReturn << endl;
    cout << "\t\t\t\tNumber of passengers: " << this->quantity << endl;
    cout << "\t\t\t\tName of Airline: " << this->AirlineName << endl;
    cout << "\t\t\t\tSeat class(Trader/Common): " << this->seatClass << endl;
    cout << "\t\t\t\tTicket price: " << this->unitPrice << endl;
    cout << "\t\t\t\tTotal Payment: " << totalPayment << endl;
}
BookTicket::~BookTicket() {}