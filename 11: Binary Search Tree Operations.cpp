#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

void insert(int key) {
    if (root == NULL) {
        Node* newNode = new Node();
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        cout << "Inserted " << key << " as root.\n";
        return;
    }
    
    Node* current = root;
    Node* parent = NULL;
    
    while (current != NULL) {
        parent = current;
        if (key == current->data) {
            cout << "Duplicate value " << key << " not allowed.\n";
            return;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    
    Node* newNode = new Node();
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    
    if (key < parent->data) {
        parent->left = newNode;
        cout << "Inserted " << key << " as left child of " << parent->data << ".\n";
    } else {
        parent->right = newNode;
        cout << "Inserted " << key << " as right child of " << parent->data << ".\n";
    }
}

bool search(int key) {
    Node* current = root;
    while (current != NULL) {
        if (key == current->data) {
            return true;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}

Node* findMin(Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

int main() {
    int choice, val;
    do {
        cout << "\n1. Insert  2. Search  3. Delete  4. Inorder Display  5. Exit\nChoice: ";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> val; insert(val); break;
            case 2: 
                cout << "Enter value: "; cin >> val; 
                if(search(val)) cout << val << " found in BST.\n";
                else cout << val << " not found in BST.\n";
                break;
            case 3:
                cout << "Enter value to delete: "; cin >> val;
                if(search(val)) {
                    root = deleteNode(root, val);
                    cout << val << " deleted successfully.\n";
                } else {
                    cout << "Element not found.\n";
                }
                break;
            case 4: 
                cout << "Inorder Traversal: "; inorder(root); cout << "\n"; 
                break;
            case 5: break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 5);
    return 0;
}
