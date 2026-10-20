#include <iostream>
#include <string>
using namespace std;

struct Node {
    string folderName;
    Node* prev;
    Node* next;
};

Node* HEAD = NULL;
Node* CURRENT = NULL;

void insertFront(string name) {
    Node* newNode = new Node{name, NULL, HEAD};
    if (HEAD != NULL) HEAD->prev = newNode;
    HEAD = CURRENT = newNode;
    cout << "Opened '" << name << "' at the beginning.\n";
}

void insertEnd(string name) {
    Node* newNode = new Node{name, NULL, NULL};
    if (HEAD == NULL) {
        HEAD = CURRENT = newNode;
    } else {
        Node* temp = HEAD;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Opened '" << name << "' at the end.\n";
}

void insertPosition(string name, int pos) {
    if (pos == 1) { insertFront(name); return; }
    Node* temp = HEAD;
    for (int i = 1; temp != NULL && i < pos - 1; i++) temp = temp->next;
    
    if (temp == NULL) {
        cout << "Invalid position!\n";
        return;
    }
    Node* newNode = new Node{name, temp, temp->next};
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    cout << "Opened '" << name << "' at position " << pos << ".\n";
}

void deleteFront() {
    if (HEAD == NULL) { cout << "Navigation history is empty.\n"; return; }
    Node* temp = HEAD;
    HEAD = HEAD->next;
    if (HEAD != NULL) HEAD->prev = NULL;
    if (CURRENT == temp) CURRENT = HEAD;
    cout << "Deleted first folder: " << temp->folderName << "\n";
    delete temp;
}

void deleteEnd() {
    if (HEAD == NULL) { cout << "Navigation history is empty.\n"; return; }
    if (HEAD->next == NULL) { deleteFront(); return; }
    Node* temp = HEAD;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    if (CURRENT == temp) CURRENT = temp->prev;
    cout << "Deleted last folder: " << temp->folderName << "\n";
    delete temp;
}

void deletePosition(int pos) {
    if (pos == 1) { deleteFront(); return; }
    Node* temp = HEAD;
    for (int i = 1; temp != NULL && i < pos; i++) temp = temp->next;
    
    if (temp == NULL) { cout << "Invalid position!\n"; return; }
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (CURRENT == temp) CURRENT = HEAD;
    cout << "Deleted folder at position " << pos << ": " << temp->folderName << "\n";
    delete temp;
}

void search(string name) {
    Node* temp = HEAD;
    int pos = 1;
    while (temp != NULL) {
        if (temp->folderName == name) {
            cout << "Folder '" << name << "' found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Folder not found.\n";
}

void display() {
    if (HEAD == NULL) { cout << "Navigation history is empty.\n"; return; }
    Node* temp = HEAD;
    cout << "Navigation History: ";
    while (temp != NULL) {
        cout << temp->folderName << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void movePrevious() {
    if (CURRENT != NULL && CURRENT->prev != NULL) {
        CURRENT = CURRENT->prev;
        cout << "Moved Back to: " << CURRENT->folderName << "\n";
    } else {
        cout << "No previous folder exists.\n";
    }
}

void moveNext() {
    if (CURRENT != NULL && CURRENT->next != NULL) {
        CURRENT = CURRENT->next;
        cout << "Moved Forward to: " << CURRENT->folderName << "\n";
    } else {
        cout << "No next folder exists.\n";
    }
}
