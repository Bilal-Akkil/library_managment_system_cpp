/**
#################### BILAL AKKIL ####################
 **/

// library.h

#pragma once
#include <conio.h>

#define getch() _getch()
using namespace std;
class library
{
private:
    struct Node
    {
        int id;
        string name, author, publisher;
        Node *next_node;
    };

public:
    Node *head = NULL;

    void menu();

    void insert();
    void search();
    void update();
    void del();
    void sort();
    void show();
};