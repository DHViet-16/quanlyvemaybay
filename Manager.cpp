#include "Manager.h"
Manager::Manager()
{
}
Manager::Manager(string ID, string name, string sex, int age, string phone, string email, string address) : People(ID, name, sex, age, phone, email, address)
{
}
void Manager::readFilePeople(ifstream &inFile)
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
void Manager::exportFilePeople(ofstream &outFile)
{
    outFile << 1 << ",";
    outFile << this->ID << ",";
    outFile << this->name << ",";
    outFile << this->sex << ",";
    outFile << this->age << ",";
    outFile << this->phone << ",";
    outFile << this->email << ",";
    outFile << this->address << ",";
}
void Manager::input()
{
    cin.ignore();
    cout << "\t\t\t\tEnter Manager ID: ";
    getline(cin, ID);
    cout << "\t\t\t\tEnter Manager Name: ";
    cin.ignore();
    getline(cin, name);
    standardizeName(name);
    cout << "\t\t\t\tEnter Manager Sex: ";
    cin >> sex;
    standardizeName(sex);
    cout << "\t\t\t\tEnter Manager Age: ";
    cin >> age;
    cin.ignore();
    cout << "\t\t\t\tEnter Manager Phone: ";
    getline(cin, phone);
    cout << "\t\t\t\tEnter Manager Email: ";
    cin >> email;
    cout << "\t\t\t\tEnter Manager Address: ";
    cin.ignore(); 
    getline(cin, address);
    standardizeName(address);
    cout << "\t\t\t\tManager created." << endl;
}
void Manager::output()
{
    cout << "\t\t\t\tID : " << ID << endl;
    cout << "\t\t\t\tName : " << name << endl;
    cout << "\t\t\t\tSex : " << sex << endl;
    cout << "\t\t\t\tAge : " << age << endl;
    cout << "\t\t\t\tPhone : " << phone << endl;
    cout << "\t\t\t\tEmail : " << email << endl;
    cout << "\t\t\t\tAdress : " << address << endl;
}
Manager::~Manager() {}