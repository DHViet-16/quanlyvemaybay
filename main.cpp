#include <iostream>
#include <vector>
#include <string.h>
#include "AccountList.h"
#include "Admin.h"
#include "User.h"
#include "PeopleList.h"
#include "BookTicketList.h"
#include "Function.h"

ACCOUNTSLIST accountsList;
PEOPLELIST PeopleList;
BookTicketList bookticketslist;

using namespace std;

void menuAdmin(int index)
{
    while (true)
    {
        showMainMenuAdmin();
        int selection;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 11)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 11 (OUTPUT ALL TICKET)\n";
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                PeopleList.getPeopleList()[PeopleList.findPeopleById(bookticketslist.getBookTicketList()[i].getID())]->output();
                bookticketslist.getBookTicketList()[i].output();
                cout << "\t\t\t\t---------------------------------------------" << endl;
            }
            cout << "\n\t\t\t\t";
            system("pause");
        }
        if (selection == 12)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 12 (OUTPUT TICKET BY ID)\n";
            string idUser;
            cout << "\t\t\t\tBill you want to find is: ";
            getline(cin, idUser);
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                if (idUser == bookticketslist.getBookTicketList()[i].getID())
                {
                    PeopleList.getPeopleList()[PeopleList.findPeopleById(idUser)]->output();
                    bookticketslist.getBookTicketList()[i].output();
                    cout << "\t\t\t\t---------------------------------------------" << endl;
                }
            }
            cout << "\n\t\t\t\t";
            system("pause");
        }
        if (selection == 13)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 13 (OUTPUT SORT TICKETS BY TOTAL PAYMENT)\n";
            bookticketslist.sortBookTicketListbyTotalpayment();
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                PeopleList.getPeopleList()[PeopleList.findPeopleById(bookticketslist.getBookTicketList()[i].getID())]->output();
                bookticketslist.getBookTicketList()[i].output();
                cout << "\t\t\t\t---------------------------------------------" << endl;
            }
            cout << "\n\t\t\t\t";
            system("pause");
        }
        if (selection == 2)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 2 (OUTPUT YOUR INFORMATION)\n";
            PeopleList.getPeopleList()[PeopleList.findPeopleById(accountsList.getAccountsList()[index]->getId())]->output();
            cout << "\n\t\t\t\tPress any key to return to MENU . . .";
            getch();
        }
        if (selection == 3)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 3 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n\t\t\t\tEnter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n\t\t\t\tDUPLICATED USER NAME ERROR!";
                    cout << "\n\t\t\t\tPlease re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 4)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 4 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n\t\t\t\tEnter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\n\t\t\t\tINCORRECT PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\n\t\t\t\tEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\n\t\t\t\tNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange password successfully! Press any key to continue. . .";
        }
        if (selection == 5)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 5 (BOOK TICKET)\n";
            bookticketslist.input(accountsList, index);
            bookticketslist.exportFIle();
        }
        if (selection == 6)
        {
            system("cls");
            showMainMenuAdmin();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 6 (CHECK YOUR TICKET)\n";
            string accountId = accountsList.getAccountsList()[index]->getId(); // Lấy ID của tài khoản
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                if (bookticketslist.getBookTicketList()[i].getID() == accountId)
                {
                    bookticketslist.getBookTicketList()[i].output();
                    cout << "\t\t\t\t-------------------------------" << endl;
                }
            }
            cout << "\n\t\t\t\t";
            system("pause");
        }
        if (selection == 000)
        {
            cout << "\n\t\t\t\tDo you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
void menuUser(int index)
{
    while (true)
    {
        showMainMenuUser();
        int selection;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR SELECTION: ";
        cin >> selection;
        cin.ignore();
        if (selection == 1)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 1 (OUTPUT YOUR INFORMATION)\n";
            PeopleList.getPeopleList()[PeopleList.findPeopleById(accountsList.getAccountsList()[index]->getId())]->output();
            cout << "\n\t\t\t\tPress any key to return to MENU . . .";
            getch();
        }
        if (selection == 2)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOSE OPTION 2 (CHANGE YOUR USER NAME)\n";
            string newUserName;
            cout << "\n\t\t\t\tEnter your new user name: ";
            getline(cin, newUserName);
            do
            {
                if (accountsList.checkDuplicatedUsername(newUserName) == true)
                {
                    cout << "\n\t\t\t\tDUPLICATED USER NAME ERROR!";
                    cout << "\n\t\t\t\tPlease re-enter your new user name: ";
                    getline(cin, newUserName);
                }
            } while (accountsList.checkDuplicatedUsername(newUserName) == true);
            accountsList.getAccountsList()[index]->changeUserName(newUserName);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange username successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 3)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOSE OPTION 3 (CHANGE YOUR PASSWORD)\n";
            string oldPassword;
            cout << "\n\t\t\t\tEnter your old password: ";
            cin >> oldPassword;
            if (accountsList.getAccountsList()[index]->getPassword() != oldPassword)
            {
                cout << "\n\t\t\t\tINCORRECT PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your old password: ";
                cin >> oldPassword;
            }
            string newPassword;
            cout << "\n\t\t\t\tEnter your new password: ";
            cin >> newPassword;
            if (accountsList.getAccountsList()[index]->getPassword() == newPassword)
            {
                cout << "\n\t\t\t\tNEW PASSWORD MUST BE DIFFERENT WITH OLD PASSWORD!";
                cout << "\n\t\t\t\tPlease re-enter your new password: ";
                cin >> newPassword;
            }
            accountsList.getAccountsList()[index]->changePassword(newPassword);
            accountsList.exportFile();
            cout << "\n\t\t\t\tChange password successfully! Press any key to continue. . .";
            getch();
            break;
        }
        if (selection == 4)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 4 (BOOK TICKET)\n";
            bookticketslist.input(accountsList, index);
            bookticketslist.exportFIle();
        }
        if (selection == 5)
        {
            system("cls");
            showMainMenuUser();
            cout << "\n\t\t\t\tYOU HAVE CHOOSE OPTION 5 (CHECK YOUR TICKET)\n";
            string accountId = accountsList.getAccountsList()[index]->getId(); // Lấy ID của tài khoản
            for (int i = 0; i < bookticketslist.getBookTicketList().size(); i++)
            {
                if (bookticketslist.getBookTicketList()[i].getID() == accountId)
                {
                    bookticketslist.getBookTicketList()[i].output();
                    cout << "\t\t\t\t-------------------------------" << endl;
                }
            }
            cout << "\n\t\t\t\t";
            system("pause");
        }
        if (selection == 000)
        {
            cout << "\n\t\t\t\tDo you want to log out? [Yes/No]: ";
            string answer;
            getline(cin, answer);
            standardizeName(answer);
            if (answer == "Yes")
            {
                showExitMenu();
                break;
            }
        }
    }
}
int passAccount()
{
    string username, password;
    cout << "\n\t\t\t\tEnter your username: ";
    cin >> username;
    cout << "\n\t\t\t\tEnter your password: ";
    cin >> password;
    if (accountsList.checkAccount(username, password) != -1)
        return accountsList.checkAccount(username, password);
    return -1;
}
void signup()
{
    PeopleList.input(accountsList);
    PeopleList.exportFile();
    accountsList.exportFile();
}
int main()
{
    PeopleList.readFile();
    bookticketslist.readFile();
    accountsList.readFile();
    showName();
    cout << "\n\t\t\t\t";
    system("pause");
    while (true)
    {
        system("cls");
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << "\n\t\t\t\t  |         MANAGEMENT OF AIR TICKET       |";
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << endl;
        cout << "\n\t\t\t\t+------------+"
             << "                 "
             << "+-------------+";
        cout << "\n\t\t\t\t|  1. LOGIN  |"
             << "                 "
             << "|  2.SIGN UP  |";
        cout << "\n\t\t\t\t+------------+"
             << "                 "
             << "+-------------+";
        int option;
        cout << "\n\t\t\t\tPLEASE ENTER YOUR OPTION: ";
        cin >> option;
        if (option == 2)
        {
            signup();
        }
        system("cls");
        cout << "\n\t\t\t\t  +----------------------------------------+";
        cout << "\n\t\t\t\t  |         MANAGEMENT OF AIR TICKET       |";
        cout << "\n\t\t\t\t  +----------------------------------------+";
        int index = passAccount();
        if (index != -1)
        {
            cout << "\n\t\t\t\tLogin successfully! Press any key to continue!";
            if (accountsList.getAccountsList()[index]->getFormat() == 1)
            {
                menuAdmin(index);
                //                system("pause");
            }
            else
            {
                menuUser(index);
            }
        }
        else
        {
            cout << "\n\t\t\t\t YOUR ACCOUNT ISN'T EXISTING! PLEASE CONTACT ADMINISTRATOR TO CREATE AN ACOUNT NOW!";
            cout << "\n\t\t\t\t";
            system("pause");
        }
    }
    return 0;
}
