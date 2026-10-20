#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;
string historyStack[MAX];
int top = -1;

bool isFull() {
    return top == MAX - 1;
}

bool isEmpty() {
    return top == -1;
}

void visitPage(string page) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot visit new page.\n";
        return;
    }
    historyStack[++top] = page;
    cout << "Visited: " << page << "\n";
}

void goBack() {
    if (isEmpty()) {
        cout << "Stack Underflow! No history to go back to.\n";
        return;
    }
    cout << "Leaving: " << historyStack[top--] << "\n";
    if (!isEmpty()) cout << "Current page is now: " << historyStack[top] << "\n";
}

void showCurrentPage() {
    if (isEmpty()) cout << "Stack is empty. No current page.\n";
    else cout << "Current Page: " << historyStack[top] << "\n";
}

void displayHistory() {
    if (isEmpty()) {
        cout << "Stack is empty. No history.\n";
        return;
    }
    cout << "Browser History:\n";
    for (int i = top; i >= 0; i--) {
        cout << historyStack[i] << "\n";
    }
}

int main() {
    int choice;
    string page;
    do {
        cout << "\n1.Visit Page 2.Go Back 3.Current Page 4.History 5.Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter URL: "; cin >> page; visitPage(page); break;
            case 2: goBack(); break;
            case 3: showCurrentPage(); break;
            case 4: displayHistory(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}
