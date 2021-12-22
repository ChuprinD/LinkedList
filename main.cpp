#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <initializer_list>

#include "linkedList.h"

using namespace std;

int main()
    {
    LinkedList<int> list ({1, 2, 3}); 
    
    int num = -1;
    int elem = 0;
    int index = 0;
    bool exit = 1;
    while (exit)
        {
        system("CLS");
        cout << "0  - exit\n";
        cout << "1  - checking the list for emptiness\n";
        cout << "2  - adding an item to the top of the list\n";
        cout << "3  - adding an item to the end of the list\n";
        cout << "4  - adding an element to a position with a specified index\n";
        cout << "5  - deleting the first node\n";
        cout << "6  - deleting the last node\n";
        cout << "7  - deleting a node by a given index\n";
        cout << "8  - deleting a node by a given value\n";
        cout << "9  - search for a node position in the list by a given value\n";
        cout << "10 - print list\n";
        cin >> num;
        switch (num)
            {
            case 0: 
                exit = 0;
                break;
            case 1: 
                cout << (list.empty() ? "Empty\n":"Not empty\n");
                break;

            case 2: 
                cout << "Enter elem\n";
                cin >> elem;
                list.push_front(elem);
                cout << list << '\n';
                break;

            case 3:
                cout << "Enter elem\n";
                cin >> elem;
                list.push_back(elem);
                cout << list << '\n';
                break;

            case 4:
                cout << "Enter elem\n";
                cin >> elem;
                cout << "Enter index\n";
                cin >> index;
                list.insert(index, elem);
                cout << list << '\n';
                break;

            case 5:
                list.pop_front();
                cout << list << '\n';
                break;

            case 6:
                list.pop_back(); 
                cout << list << '\n';
                break;

            case 7:
                cout << "Enter index\n";
                cin >> index;
                list.erase(index);
                cout << list << '\n';
                break;

            case 8:
                cout << "Enter elem\n";
                cin >> elem;
                list.erase_value(elem);
                cout << list << '\n';
                break;

            case 9:
                cout << "Enter elem\n";
                cin >> elem;
                cout << "Index = " << list.find(elem) << '\n';
                break;

            case 10:
                cout << list << '\n';
                break;

            }
        cout << "Push any button to continue\n";
        _getch();
        }

    }