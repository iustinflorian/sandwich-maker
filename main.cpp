#include <iostream>
#include <fstream>
using namespace std;

class Node {
public:
    int data;
    Node* left, * right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

void preorderTraversal(Node* root, ofstream& outputFile) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr) {
        outputFile << root->data << " ";
        return;
    }
    outputFile << root->data << " ";
    preorderTraversal(root->left, outputFile);
    if (root->left != nullptr) {
        return;
    }
    preorderTraversal(root->right, outputFile);
}

void inorderTraversal(Node* root, ofstream& outputFile) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left, outputFile);

    if (root->data == 1) {
        // Stop the traversal when reaching the value 1 (root leaf node)
        outputFile << root->data << " ";
        return;
    }

    outputFile << root->data << " ";

    inorderTraversal(root->right, outputFile);
}

void postorderTraversal(Node* root, ofstream& outputFile) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left, outputFile);
    postorderTraversal(root->right, outputFile);
    outputFile << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    root->left->right->left->left = new Node(10);
    root->left->right->left->right = new Node(11);

    ofstream outputFile("default.txt");
    if (outputFile.is_open()) {
        outputFile << "(preorder)Primii trei clienti au primit sandwichul cu ingredientele: ";
        preorderTraversal(root, outputFile);
        outputFile << endl << "(inorder)Ceilalti trei clienti au primit sandwichul cu ingredientele: ";
        inorderTraversal(root, outputFile);
        outputFile << endl << "(postorder)Ultimii trei clienti au primit sandwichul cu ingredientele: ";
        postorderTraversal(root, outputFile);
        outputFile.close();
        cout << "Sandwich-ul a fost tiparit." << endl;
    }
    else {
        cout << "Eroare." << endl;
    }

    return 0;
}
