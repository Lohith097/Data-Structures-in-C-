#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct SinglyLinkedList {
    Node* head = nullptr;

    void insertFront(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at front.\n";
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at end.\n";
    }

    void insertPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            insertFront(value);
            return;
        }
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of range!\n";
            delete newNode; 
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " at position " << pos << ".\n";
        }
    }

    void deleteFront() {
        if (head == nullptr) {
            cout << "List is empty (Underflow).\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from front.\n";
        delete temp; 
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty (Underflow).\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Deleted " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deletePosition(int pos) {
        if (head == nullptr) {
            cout << "List is empty (Underflow).\n";
            return;
        }
        if (pos < 1) {
            cout << "Invalid position!\n";
            return;
        }
        if (pos == 1) {
            deleteFront();
            return;
        }
        Node* temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range!\n";
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next; 
        cout << "Deleted " << nodeToDelete->data << " from position " << pos << ".\n";
        delete nodeToDelete; 
    }

    bool search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << pos << ".\n";
                return true;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element " << key << " not found.\n";
        return false;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Current List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, pos;
    do {
        cout << "\nSINGLY LINKED LIST MENU\n";
        cout << "1. Insert Front\n2. Insert End\n3. Insert at Position\n";
        cout << "4. Delete Front\n5. Delete End\n6. Delete at Position\n";
        cout << "7. Search\n8. Traversal (Display)\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value to insert at front: "; cin >> value; list.insertFront(value); break;
            case 2: cout << "Enter value to insert at end: "; cin >> value; list.insertEnd(value); break;
            case 3: cout << "Enter value and position: "; cin >> value >> pos; list.insertPosition(value, pos); break;
            case 4: list.deleteFront(); break;
            case 5: list.deleteEnd(); break;
            case 6: cout << "Enter position to delete: "; cin >> pos; list.deletePosition(pos); break;
            case 7: cout << "Enter value to search: "; cin >> value; list.search(value); break;
            case 8: list.display(); break;
            case 9: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 9);
    return 0;
}
