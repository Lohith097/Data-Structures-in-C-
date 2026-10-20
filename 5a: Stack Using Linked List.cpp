#include <iostream>
using namespace std;

struct Node {
    int kitID;
    Node* next;
};

Node* TOP = NULL;

void push(int id) {
    Node* newNode = new Node();
    newNode->kitID = id;
    newNode->next = TOP;
    TOP = newNode;
    cout << "Kit ID " << id << " pushed onto stack.\n";
}

void pop() {
    if (TOP == NULL) {
        cout << "Stack is empty (Underflow).\n";
        return;
    }
    Node* temp = TOP;
    TOP = TOP->next;
    cout << "Popped Kit ID: " << temp->kitID << " for verification.\n";
    delete temp;
}

void peek() {
    if (TOP == NULL) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Top available Kit ID: " << TOP->kitID << "\n";
    }
}

void display() {
    if (TOP == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = TOP;
    cout << "Current Stack (Top to Bottom): ";
    while (temp != NULL) {
        cout << temp->kitID << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void search(int id) {
    if (TOP == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = TOP;
    int pos = 1;
    while (temp != NULL) {
        if (temp->kitID == id) {
            cout << "Kit ID " << id << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Kit ID " << id << " not found in stack.\n";
}

void isEmpty() {
    if (TOP == NULL) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack contains electronic kits (Not empty).\n";
    }
}

int main() {
    int choice, id;
    do {
        cout << "\n--- STACK (RETURNED KITS) MENU ---\n";
        cout << "1. Push 2. Pop 3. Top (Peek) 4. Display 5. Search 6. isEmpty 7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter Kit ID: "; cin >> id; push(id); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Enter Kit ID to search: "; cin >> id; search(id); break;
            case 6: isEmpty(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
