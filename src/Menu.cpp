//
// Created by Christian Hong on 4/28/25.
//

#include "../include/Menu.h"
#include <iostream>
#include <limits>
using namespace std;

void displayMenu() {
    cout << "1. Linked List (Playlist)\n";
    cout << "2. Stack (Book Return)\n";
    cout << "3. Queue (Task Scheduler)\n";
    cout << "4. Graph (Social Network)\n";
    cout << "5. Hash Table (Product Inventory)\n";
    cout << "6. Binary Search Tree(Student ID System)\n";
    cout << "7. Exit\n";
    cout << "Choose an option 1-7:\n";
}

void playlistDemo() {
    int option;
    LinkedList list;
    string song;

    do {
        cout << "\nPlaylist Manager:\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. View Playlist\n";
        cout << "4. Back to Main Menu\n";
        cout << "Choose an option 1-4:\n";
        cin >> option;


        while (!(cin) || option < 1 || option > 4) {
            cout << "Enter a valid option 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1: {
                cout << "Enter a song to add to your playlist: ";
                cin.ignore();
                getline(cin, song);
                list.insertAtFront(song);
                cout << song << " has been added!\n";
                break;
            }
            case 2: {
                cout << "Enter a song to delete from your playlist: ";
                cin.ignore();
                getline(cin, song);
                if (list.search(song)) {
                    list.deleteItem(song);
                    cout << song << " has been deleted!\n";
                }
                else {
                    cout << song << " was not found\n";
                }
                break;
            }
            case 3: {
                list.printItems();
                break;
            }
            case 4: {
                cout << '\n';
                return;
            }
        }
    } while (option != 4);
}

void bookReturnDemo() {
    int option;
    Stack stack;
    string book;

    do {
        cout << "\nBook Return System:\n";
        cout << "1. Return a book (Add to stack)\n";
        cout << "2. Process return for last returned book\n";
        cout << "3. View top book\n";
        cout << "4. View all returned books\n";
        cout << "5. Back to main menu\n";
        cout << "Choose an option 1-5:\n";
        cin >> option;

        while (!(cin) || option < 1 || option > 5) {
            cout << "Enter a valid option 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1: {
                cout << "Enter a book to return: ";
                cin.ignore();
                getline(cin,book);
                stack.push(book);
                cout << book << " has been returned!\n";
                break;
            }
            case 2: {
                book = stack.peek();
                if (book.empty()) {
                    cout << "Stack is empty\n";
                }
                else {
                    cout << "Processing next returned book: " << stack.pop() << '\n';
                }
                break;
            }
            case 3: {
                string returnBook = stack.peek();
                if (returnBook == "") {
                    cout << "Stack is empty\n";
                }
                else {
                    cout << "Recent returned book: " << stack.peek() << '\n';
                }
                break;
            }
            case 4: {
                stack.printStack();
                break;
            }
            case 5: {
                cout << '\n';
                return;
            }
        }
    } while (option != 5);
}

void taskDemo() {
    Queue queue;
    int option;
    string task;

    do {
        cout << "\nTask Scheduler:\n";
        cout << "1. Add new task\n";
        cout << "2. Process next task\n";
        cout << "3. View next task\n";
        cout << "4. View all tasks\n";
        cout << "5. Back to main menu\n";
        cout << "Choose an option 1-5:\n";
        cin >> option;

        while (!(cin) || option < 1 || option > 5) {
            cout << "Enter a valid option 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1: {
                cout << "Enter a task to add\n";
                cin.ignore();
                getline(cin,task);
                queue.enqueue(task);
                cout << task << " has been added!\n";
                break;
            }
            case 2: {
                task = queue.dequeue();
                if (task.empty()) {
                    cout << "No tasks to process\n";
                }
                else {
                    cout << task << " has been finished\n";
                }
                break;
            }
            case 3: {
                if (queue.peek().empty()) {
                    cout << "No pending tasks\n";
                }
                else {
                    cout << "Next task to finish: " << queue.peek() << '\n';
                }
                break;
            }
            case 4: {
                queue.printQueue();
                break;
            }
            case 5: {
                cout << '\n';
                return;
            }
        }
    } while (option != 5);

}

void networkDemo() {
    int option;
    Graph network;
    string name;

    do {
        cout << "\nSocial Network:\n";
        cout << "1. Add Person\n";
        cout << "2. Add Friendship (Connect)\n";
        cout << "3. Show friends of a person\n";
        cout << "4. Check connection between 2 people\n";
        cout << "5. Back to Main Menu\n";
        cout << "Choose an option 1-5:\n";
        cin >> option;

        while (!(cin) || option < 1 || option > 5) {
            cout << "Enter a valid option 1-5: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1: {
                cout << "Enter the name of the person you want to add: ";
                cin.ignore();
                getline(cin, name);
                network.addPerson(name);
                cout << name << " has been added!\n";
                break;
            }
            case 2: {
                string name2;
                cout << "Enter the two names you would like to connect\n";
                cout << "Person 1: ";
                cin.ignore();
                getline(cin, name);
                cout << "Person 2: ";
                getline(cin,name2);
                network.addFriendship(name, name2);
                cout << name << " and " << name2 << " are now friends!\n";
                break;
            }
            case 3: {
                cout << "Enter the name of the person to display their friends: ";
                cin.ignore();
                getline(cin, name);
                network.showFriends(name);
                break;
            }
            case 4: {
                string name, name2;
                cout << "Check if two people are friends:\n";
                cout << "Person 1: ";
                cin.ignore();
                getline(cin, name);
                cout << "Person 2: ";
                getline(cin,name2);

                if (network.isConnected(name, name2)) {
                    cout << name << " and " << name2 << " are connected!\n";
                }
                else {
                    cout << "They are not connected\n";
                }
                break;
            }
            case 5: {
                cout << '\n';
                return;
            }
        }
    }while (option != 5);
}

void productDemo() {
    int option;
    HashTable table;
    string product;
    int quantity;

    do {
        cout << "\nProduct Inventory:\n";
        cout << "1. Add/update product\n";
        cout << "2. Check product stock\n";
        cout << "3. Display all products\n";
        cout << "4. Back to Main Menu\n";
        cout << "Choose an option 1-4:\n";
        cin >> option;

        while (!(cin) || option < 1 || option > 4) {
            cout << "Enter a valid option 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }
        switch (option) {
            case 1: {
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, product);

                cout << "Enter quantity: ";
                while (!(cin >> quantity)) {
                    cout << "Please enter a valid integer quantity: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                table.addItem(product, quantity);
                break;
            }
            case 2: {
                cout << "Enter product name to check: ";
                cin.ignore();
                getline(cin, product);
                table.searchItem(product);
                break;
            }
            case 3: {
                table.displayAll();
                break;
            }
            case 4: {
                cout << '\n';
                return;
            }
        }
    } while (option != 4);
}

void studentDemo() {
    int option;
    BinaryTree tree;
    int id;

    do {
        cout << "\nStudent ID System:\n";
        cout << "1. Insert student ID\n";
        cout << "2. Search for ID\n";
        cout << "3. Display ID's in order (Sorted)\n";
        cout << "4. Back to Main Menu\n";
        cout << "Choose an option 1-4:\n";
        cin >> option;


        while (!(cin) || option < 1 || option > 4) {
            cout << "Enter a valid option 1-4: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }

        switch (option) {
            case 1: {
                cout << "Enter a student ID to insert: ";
                bool validInput = false;

                while (!validInput) {
                    if (cin >> id) {
                        validInput = true;
                    } else {
                        cout << "Enter only a valid integer ID: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }
                tree.insert(id);
                cout << "ID: " << id << " has been added!\n";
                break;
            }
            case 2: {
                cout << "Enter a student ID to search for: ";

                while (!(cin >> id)) {
                    cout << "Enter only a valid integer ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (tree.search(id)) {
                    cout << "Student " << id << " has been found!\n";
                } else {
                    cout << "Student " << id << " not found.\n";
                }
                break;
            }

            case 3: {
                tree.inOrder();
                break;
            }
            case 4: {
                cout << '\n';
                return;
            }
        }
    } while (option != 4);
}