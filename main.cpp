#include <iostream>
#include <initializer_list>

#include "linkedList.h"

using namespace std;

int main()
    {
    LinkedList<int> list ({1, 2, 3}); 
    
    int num = -1;
    int elem = 0;
    int index = 0;
    while (true)
        {
        cin >> num;
        switch (num)
            {
            case 0: 
                break;
            case 1: 
                cout << list.empty() ? "Empty":"Not empty";

            case 2: 
                cout << "Enter elem\n";
                cin >> elem;
                list.push_front(elem);
                cout << list;

            case 3:
                cout << "Enter elem\n";
                cin >> elem;
                list.push_back(elem);
                cout << list;

            case 4:
                cout << "Enter elem\n";
                cin >> elem;
                cout << "Enter index\n";
                cin >> index;
                list.insert(index, elem);
                cout << list;

            case 5:
                list.pop_front();

            case 6:
                list.pop_back(); 

            case 7:

            }
        }

    }