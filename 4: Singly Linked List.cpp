#include <iostream>
#include <string>
using namespace std;

struct Node {
    string memberName;
    Node* next;
};

Node* HEAD = NULL;

void insertBeginning(string name) {
    Node* newNode = new Node();
    newNode->memberName = name;
    newNode->next = HEAD;
    HEAD = newNode;
    cout << "Inserted at beginning.\n";
}

void insertEnd(string name) {
    Node* newNode = new Node();
    newNode->memberName = name;
    newNode->next = NULL;
    if (HEAD == NULL) {
        HEAD = newNode;
    } else {
        Node* temp = HEAD;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted at end.\n";
}

void displayList() {
    if (HEAD == NULL) {
        cout << "Membership list is empty.\n";
        return;
    }
    Node* temp = HEAD;
    cout << "Club Members: ";
    while (temp != NULL) {
        cout << temp->memberName << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void deleteBeginning() {
    if (HEAD == NULL) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = HEAD;
    HEAD = HEAD->next;
    cout << "Deleted: " << temp->memberName << "\n";
    delete temp;
}

// Minimal main menu for demonstration
int main() {
    int choice;
    string name;
    do {
        cout << "\n1.Add Beginning 2.Add End 3.Display 4.Delete Beginning 5.Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter name: "; cin >> name; insertBeginning(name); break;
            case 2: cout << "Enter name: "; cin >> name; insertEnd(name); break;
            case 3: displayList(); break;
            case 4: deleteBeginning(); break;
            case 5: break;
            default: cout << "Invalid\n";
        }
    } while (choice != 5);
    return 0;
}
