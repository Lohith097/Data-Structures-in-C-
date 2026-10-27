#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* last = NULL;
Node* currentDriver = NULL;

void addMember() {
    string name;
    cout << "Enter member name: ";
    cin >> name;

    Node* newNode = new Node();
    newNode->name = name;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
        currentDriver = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    cout << "Member added successfully.\n";
}

void removeMember() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    
    string name;
    cout << "Enter member name to remove: ";
    cin >> name;

    Node* current = last->next;
    Node* previous = last;
    bool found = false;

    do {
        if (current->name == name) {
            found = true;
            break;
        }
        previous = current;
        current = current->next;
    } while (current != last->next);

    if (found) {
        if (current == last && current->next == last) {
            last = NULL;
            currentDriver = NULL;
        } else if (current == last) {
            previous->next = current->next;
            last = previous;
        } else if (current == last->next) {
            last->next = current->next;
        } else {
            previous->next = current->next;
        }
        
        if (currentDriver == current) {
            currentDriver = current->next; 
        }
        delete current;
        cout << "Member removed successfully.\n";
    } else {
        cout << "Member not found.\n";
    }
}

void searchMember() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    
    string name;
    cout << "Enter member name to search: ";
    cin >> name;

    Node* temp = last->next;
    int position = 1;
    bool found = false;

    do {
        if (temp->name == name) {
            cout << "Member found at position " << position << ".\n";
            found = true;
            break;
        }
        temp = temp->next;
        position++;
    } while (temp != last->next);

    if (!found) {
        cout << "Member not found.\n";
    }
}

void displayMembers() {
    if (last == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    
    Node* temp = last->next;
    cout << "Driving Rotation: ";
    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != last->next);
    cout << "(Back to First Member)\n";
}

void assignNextDriver() {
    if (last == NULL || currentDriver == NULL) {
        cout << "Driving rotation is empty.\n";
        return;
    }
    cout << "Current Driver is: " << currentDriver->name << "\n";
    currentDriver = currentDriver->next;
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Member\n2. Remove Member\n3. Search Member\n";
        cout << "4. Display Driving Rotation\n5. Assign Next Driver\n6. Exit\nChoice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addMember(); break;
            case 2: removeMember(); break;
            case 3: searchMember(); break;
            case 4: displayMembers(); break;
            case 5: assignNextDriver(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice.\n";
        }
    } while (choice != 6);
    return 0;
}