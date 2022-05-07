/**
#################### BILAL AKKIL ####################
 **/

// lms.cpp

#include <iostream>
#include <stdexcept>
#include <string>
#include <limits>
#include "library.h"
using namespace std;

void library::insert()
{
    system("cls");

    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

    Node *new_node = new Node;

    cin.ignore();

    while (true)
    {
        cout << "\n\n Book ID: ";
        if (cin >> (new_node->id))
        {
            break;
        }
        else
        {
            cout << "\n Enter a valid Integer\n";
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    cin.ignore();

    cout << "\n\nEnter Book Name: ";
    getline(cin, new_node->name);

    cout << "\n\n author Name: ";
    getline(cin, new_node->author);

    cout << "\n\n Publisher Name: ";
    getline(cin, new_node->publisher);

    new_node->next_node = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *pointer = head;
        while (pointer->next_node != NULL)
        {
            pointer = pointer->next_node;
        }
        pointer->next_node = new_node;
    }
    cout << "\n\n\t\t\t New Book Inserted successfully";
}

void library::search()
{
    system("cls");
    int t_id, found = 0;
    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

    if (head == NULL)
    {
        cout << "\n\n Linked List is empty";
    }
    else
    {
        cout << "\n\n Book ID: ";
        cin >> t_id;
        Node *pointer = head;
        while (pointer != NULL)
        {
            if (t_id == pointer->id)
            {
                system("cls");
                cout << "\n\n\t\t\t--------------------------------------------------------";
                cout << "\n\n\t\t\t--------------Library Management System ----------------";
                cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

                cout << "\n\n Book ID: " << pointer->id;
                cout << "\n\n Book Name: " << pointer->name;
                cout << "\n\n Author Name: " << pointer->author;
                cout << "\n\n Publisher Name: " << pointer->publisher;
                found++;
            }
            pointer = pointer->next_node;
        }
        if (found == 0)
        {
            cout << "\n\n Book ID is Invalid.....";
        }
    }
}

void library::update()
{

    system("cls");
    int t_id, found = 0;

    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

    if (head == NULL)
    {
        cout << "\n\n Linked List is empty";
    }
    else
    {
        cout << "\n\n Book ID: ";
        cin >> t_id;
        Node *pointer = head;
        while (pointer != NULL)
        {
            if (t_id == pointer->id)
            {
                system("cls");

                cout << "\n\n\t\t\t--------------------------------------------------------";
                cout << "\n\n\t\t\t--------------Library Management System ----------------";
                cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

                while (true)
                {
                    cout << "\n\n Book ID: ";
                    if (cin >> (pointer->id))
                    {
                        break;
                    }
                    else
                    {
                        cout << "\n Enter a valid Integer\n";
                        cin.clear();
                        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    }
                }
                cin.ignore();

                cout << "\n\n Book Name: ";
                getline(cin, pointer->name);

                cout << "\n\n Author Name: ";
                getline(cin, pointer->author);

                cout << "\n\n Publisher Name: ";
                getline(cin, pointer->publisher);

                found++;
                cout << "\n\n\t\t\t update Book successfully";
            }
            pointer = pointer->next_node;
        }
        if (found == 0)
        {
            cout << "\n\n Book ID is Invalid.....";
        }
    }
}

void library::del()
{
    system("cls");
    int t_id, found = 0;

    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

    try
    {
        if (head == NULL)
        {

            throw underflow_error("\n\n Linked list is Empty");
        }
        else
        {
            cout << "\n\n Book ID: ";
            cin >> t_id;
            if (t_id == head->id)
            {
                Node *pointer = head;
                head = head->next_node;
                delete pointer;
                cout << "\n\n Delete book Successfully";
                found++;
            }
            else
            {
                Node *pre = head;
                Node *pointer = head;
                while (pointer != NULL)
                {
                    if (t_id == pointer->id)
                    {
                        pre->next_node = pointer->next_node;
                        delete pointer;
                        cout << "\n\n Delete Book successfully";
                        found++;
                        break;
                    }
                    pre = pointer;
                    pointer = pointer->next_node;
                }
            }
            if (found == 0)
            {
                cout << "\n\n Book ID is Invalid";
            }
        }
    }
    catch (underflow_error &error)
    {
        cout << "\nException occured" << endl;
        cout << error.what();
    }
}

void library::sort()
{

    if (head == NULL)
    {

        system("cls");
        cout << "\n\n\t\t\t--------------------------------------------------------";
        cout << "\n\n\t\t\t--------------Library Management System ----------------";
        cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

        cout << "\nLinked list is Empty";
        _getch();
        menu();
    }
    int count = 0, t_id;
    string t_name, t_author, t_publisher;
    Node *pointer = head;
    while (pointer != NULL)
    {
        count++;
        pointer = pointer->next_node;
    }
    for (int i = 0; i <= count; i++)
    {
        Node *pointer = head;
        for (int j = 1; j < count; j++)
        {
            if (pointer->id > pointer->next_node->id)
            {

                // Save data into Temporory Variable
                t_id = pointer->id;
                t_name = pointer->name;
                t_author = pointer->author;
                t_publisher = pointer->publisher;

                // Save data into Current Node
                pointer->id = pointer->next_node->id;
                pointer->name = pointer->next_node->name;
                pointer->author = pointer->next_node->author;
                pointer->publisher = pointer->next_node->publisher;

                // Save data into Next Node
                pointer->next_node->id = t_id;
                pointer->next_node->name = t_name;
                pointer->next_node->author = t_author;
                pointer->next_node->publisher = t_publisher;
            }
            pointer = pointer->next_node;
        }
    }
}

void library::show()
{
    system("cls");

    cout << "\n\n\t\t\t--------------------------------------------------------";
    cout << "\n\n\t\t\t--------------Library Management System ----------------";
    cout << "\n\n\t\t\t--------------------BILAL AKKIL-------------------------";

    Node *pointer = head;
    while (pointer != NULL)
    {

        cout << "\n\n Book ID: " << pointer->id;
        cout << "\n\n Book Name: " << pointer->name;
        cout << "\n\n Author Name: " << pointer->author;
        cout << "\n\n Publisher Name: " << pointer->publisher;
        cout << "\n\n\t\t\t--------------------------------------------------------";
        pointer = pointer->next_node;
    }
}
