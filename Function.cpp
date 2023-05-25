#include "Function.h"
void standardizeName(string &s)
{
    int n = s.length();
    // Xóa khoảng trắng đầu và cuối xâu
    while (s[0] == ' ')
    {
        s.erase(s.begin() + 0); // Xoa ki tu tai vi tri 0
    }
    while (s[n - 1] == ' ')
    {
        s.erase(s.begin() + (n - 1)); // Xoa ki tu tai vi tri cuoi
    }
    // xoa khoang trang thua o giua cac tu
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    // viet hoa moi ki tu dau
    strlwr((char *)s.c_str()); // chuyen ve chuoi in thuong
    s[0] = s[0] - 32;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            s[i + 1] = s[i + 1] - 32;
        }
    }
}
void showName()
{
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|         MANAGEMENT OF AIR TICKET       |";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\n";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|   DANG HOANG VIET       | 2151150069   |";
    cout << "\n\t\t\t\t|   VO MINH HANH          | 2151150037   |";
    cout << "\n\t\t\t\t+----------------------------------------+";
}
void showMainMenuAdmin()
{
    system("cls");
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|         MANAGEMENT OF AIR TICKET       |";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\n";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|               MENU MANAGER              |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|          1x. Output Ticket              |";
    cout << "\n\t\t\t\t|           11. Output All Ticket         |";
    cout << "\n\t\t\t\t|           12. Output Ticket by ID       |";
    cout << "\n\t\t\t\t|           13. Output Sort Tickets       |"; 
    cout << "\n\t\t\t\t|                       by Total Payment  |";
    cout << "\n\t\t\t\t|          2. Output your information     |";
    cout << "\n\t\t\t\t|          3. Change your user name       |";
    cout << "\n\t\t\t\t|          4. Change your password        |";
    cout << "\n\t\t\t\t|          5. Book Ticket                 |";
    cout << "\n\t\t\t\t|          6. Check your ticket           |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|          Press 000 to log out           |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
}
void showMainMenuUser()
{
    system("cls");
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\t\t\t\t|         MANAGEMENT OF AIR TICKET       |";
    cout << "\n\t\t\t\t+----------------------------------------+";
    cout << "\n\n";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|              MENU CUSTOMER              |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|        1. Output your information       |";
    cout << "\n\t\t\t\t|        2. Change your user name         |";
    cout << "\n\t\t\t\t|        3. Change your password          |";
    cout << "\n\t\t\t\t|        4. Book Ticket                   |";
    cout << "\n\t\t\t\t|        5. Check your ticket             |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
    cout << "\n\t\t\t\t|        Press 000 to log out             |";
    cout << "\n\t\t\t\t+-----------------------------------------+";
}
void showExitMenu()
{
    cout << "\n\n";
    cout << "\t\t\t\t\tHAVE A GREAT WORKING DAY";
    cout << "\n\t\t\t\tTHANK YOU AND SEE YOU SOON" << endl;
}
