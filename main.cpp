/**
#################### BILAL AKKIL ####################
 **/

// main.cpp

#include <iostream>
#include <conio.h>
#include "library.h"
#include "lms.cpp"

void library::menu()
{
f:
    system("cls");
    int choice;
    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";
    cout << "\n\n 1. Insert New record";
    cout << "\n\n 2. Search Record";
    cout << "\n\n 3. Update Record";
    cout << "\n\n 4. Delete Record";
    cout << "\n\n 5. Show all Record";
    cout << "\n\n 6. Exit";
    cout << "\n\n Enter Your Choice: ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        insert();
        break;

    case 2:
        search();
        break;

    case 3:
        update();
        break;

    case 4:
        del();
        break;

    case 5:
        sort();
        show();
        break;

    case 6:
        exit(0);

    default:
        cout << "\n\n This command is not available, Press Enter To Try Again...";
    }
    _getch();
    goto f;
}

int main()
{
    library obj;
    obj.menu();
}
