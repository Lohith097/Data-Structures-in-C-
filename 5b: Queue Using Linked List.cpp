#include <iostream>
using namespace std;

struct Node {
    int studentID;
    Node* next;
};

Node* FRONT = NULL;
Node* REAR = NULL;

void enqueue(int id) {
    Node* newNode = new Node();
    newNode->studentID = id;
    newNode->next = NULL;
    if (FRONT == NULL) {
        FRONT = REAR = newNode;
    } else {
        REAR->next = newNode;
        REAR = newNode;
    }
    cout << "Student ID " << id << " registered (Enqueued).\n";
}

void dequeue() {
    if (FRONT == NULL) {
        cout << "Queue is empty (Underflow).\n";
        return;
    }
    Node* temp = FRONT;
    FRONT = FRONT->next;
    cout << "Called Student ID: " << temp->studentID << " for mentoring (Dequeued).\n";
    if (FRONT == NULL) {
        REAR = NULL;
    }
    delete temp;
}

void showFront() {
    if (FRONT == NULL) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Next student in line (Front): " << FRONT->studentID << "\n";
    }
}

void showRear() {
    if (REAR == NULL) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Last registered student (Rear): " << REAR->studentID << "\n";
    }
}

void display() {
    if (FRONT == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = FRONT;
    cout << "Current Queue: ";
    while (temp != NULL) {
        cout << temp->studentID << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void search(int id) {
    if (FRONT == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    Node* temp = FRONT;
    int pos = 1;
    while (temp != NULL) {
        if (temp->studentID == id) {
            cout << "Student ID " << id << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Student ID " << id << " not found in queue.\n";
}

void isEmpty() {
    if (FRONT == NULL) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue contains student records (Not empty).\n";
    }
}

int main() {
    int choice, id;
    do {
        cout << "\n--- QUEUE (MENTORING STUDENTS) MENU ---\n";
        cout << "1. Enqueue 2. Dequeue 3. Front 4. Rear 5. Display 6. Search 7. isEmpty 8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter Student ID: "; cin >> id; enqueue(id); break;
            case 2: dequeue(); break;
            case 3: showFront(); break;
            case 4: showRear(); break;
            case 5: display(); break;
            case 6: cout << "Enter Student ID to search: "; cin >> id; search(id); break;
            case 7: isEmpty(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}
