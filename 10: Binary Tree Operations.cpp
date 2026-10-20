#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* root = NULL;

void insert(int value) {
    Node* newNode = createNode(value);
    if (root == NULL) {
        root = newNode;
        cout << "Inserted " << value << " as root.\n";
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp->left == NULL) {
            temp->left = newNode;
            cout << "Inserted " << value << " as left child of " << temp->data << ".\n";
            return;
        } else {
            q.push(temp->left);
        }
        
        if (temp->right == NULL) {
            temp->right = newNode;
            cout << "Inserted " << value << " as right child of " << temp->data << ".\n";
            return;
        } else {
            q.push(temp->right);
        }
    }
}

bool search(int value) {
    if (root == NULL) return false;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp->data == value) return true;
        
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    return false;
}

Node* findDeepestNode() {
    if (root == NULL) return NULL;
    queue<Node*> q;
    q.push(root);
    Node* temp = NULL;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    return temp;
}

void deleteDeepestNode(Node* deepest) {
    if (root == NULL) return;
    if (root == deepest) {
        delete root;
        root = NULL;
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if (temp->left == deepest) {
            temp->left = NULL;
            delete deepest;
            return;
        } else if (temp->left != NULL) {
            q.push(temp->left);
        }
        
        if (temp->right == deepest) {
            temp->right = NULL;
            delete deepest;
            return;
        } else if (temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

bool deleteNode(int value) {
    if (root == NULL) return false;
    
    if (root->left == NULL && root->right == NULL) {
        if (root->data == value) {
            delete root;
            root = NULL;
            return true;
        }
        return false;
    }
    
    queue<Node*> q;
    q.push(root);
    Node* targetNode = NULL;
    Node* temp = NULL;
    
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        
        if (temp->data == value) targetNode = temp;
        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
    
    if (targetNode != NULL) {
        Node* deepest = findDeepestNode();
        targetNode->data = deepest->data;
        deleteDeepestNode(deepest);
        return true;
    }
    return false;
}

int main() {
    int choice, val;
    do {
        cout << "\n1. Insert  2. Search  3. Delete  4. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; insert(val); break;
            case 2: 
                cout << "Enter value: "; cin >> val; 
                if(search(val)) cout << val << " found in tree.\n";
                else cout << val << " not found.\n";
                break;
            case 3:
                cout << "Enter value to delete: "; cin >> val;
                if(deleteNode(val)) cout << val << " deleted successfully.\n";
                else cout << val << " not found. Deletion failed.\n";
                break;
            case 4: break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 4);
    return 0;
}
