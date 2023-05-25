#include "Customer.h"
Customer::Customer()
{
}
Customer::Customer(string ID, string name, string sex, int age, string phone, string email, string address) : People(ID, name, sex, age, phone, email, address)
{
}
void Customer::readFilePeople(ifstream &inFile)
{
    char x;
    inFile >> x;
    getline(inFile, this->ID, ',');
    getline(inFile, this->name, ',');
    getline(inFile, this->sex, ',');
    inFile >> this->age;
    inFile >> x;
    getline(inFile, this->phone, ',');
    getline(inFile, this->email, ',');
    getline(inFile, this->address, ',');
}
void Customer::exportFilePeople(ofstream &outFile)
{
    outFile << 2 << ",";
    outFile << this->ID << ",";
    outFile << this->name << ",";
    outFile << this->sex << ",";
    outFile << this->age << ",";
    outFile << this->phone << ",";
    outFile << this->email << ",";
    outFile << this->address << ",";
}
void Customer::input()
{
    cin.ignore();
    cout << "\t\t\t\tEnter Customer ID(CCCD/Passport): ";
    getline(cin, ID);
    cout << "\t\t\t\tEnter Customer Name: ";
    getline(cin, name);
    standardizeName(name);
    cout << "\t\t\t\tEnter Customer Sex: ";
    cin >> sex;
    standardizeName(sex);
    cout << "\t\t\t\tEnter Customer Age: ";
    cin >> age;
    cin.ignore();
    cout << "\t\t\t\tEnter Customer Phone: ";
    getline(cin, phone);
    cout << "\t\t\t\tEnter Customer Email: ";
    getline(cin, email);
    cout << "\t\t\t\tEnter Customer Address: ";
    getline(cin, address);
    standardizeName(address);
    cout << "\t\t\t\tCustomer created." << endl;
}
void Customer::output()
{
    cout << "\t\t\t\tID(CCCD/Passport) :" << ID << endl;
    cout << "\t\t\t\tName : " << name << endl;
    cout << "\t\t\t\tSex : " << sex << endl;
    cout << "\t\t\t\tAge : " << age << endl;
    cout << "\t\t\t\tPhone : " << phone << endl;
    cout << "\t\t\t\tEmail : " << email << endl;
    cout << "\t\t\t\tAdress : " << address << endl;
}
Customer::~Customer(){}