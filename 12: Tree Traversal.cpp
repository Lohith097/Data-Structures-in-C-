#include <iostream>
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

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    
    cout << "Inorder Traversal:   ";
    inorder(root);
    cout << "\n";
    
    cout << "Preorder Traversal:  ";
    preorder(root);
    cout << "\n";
    
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << "\n";
    
    Node* emptyRoot = NULL;
    cout << "\nTraversal of an Empty Tree: ";
    inorder(emptyRoot); 
    cout << "(No output)\n";

    return 0;
}
