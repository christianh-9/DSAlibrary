#include <iostream>
#include "include/Menu.h"
using namespace std;

int main() {

    int option;
    do {
        displayMenu();
        cin >> option;

        while (!(cin) || option < 1 || option > 7) {
            cout << "Enter a valid option 1-7: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1:{
                playlistDemo();
                break;
            }
            case 2: {
                bookReturnDemo();
                break;
            }
            case 3: {
                taskDemo();
                break;
            }
            case 4: {
                networkDemo();
                break;
            }
            case 5: {
                productDemo();
                break;
            }
            case 6: {
                studentDemo();
                break;
            }
            case 7: {
                cout << "Thank you for using the DSA Library!";
                break;
            }
        }
    } while (option != 7);
    return 0;
}

