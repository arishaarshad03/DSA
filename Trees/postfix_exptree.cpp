#include<iostream>
using namespace std;

#define SIZE 100

struct ETNode {
    char data;
    ETNode* left;
    ETNode* right;
};
// ---------------- ARRAY STACK ----------------
ETNode* stack[SIZE];
int top = -1;

void pushNode(ETNode* node) {
    if (top >= SIZE - 1) {
        cout << "Tree stack overflow\n";
        return;
    }
    stack[++top] = node;
}

ETNode* popNode() {
    if (top < 0) {
        cout << "Tree stack underflow\n";
        return nullptr;
    }
    return stack[top--];
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

ETNode* buildTree(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        ETNode* temp = new ETNode;
        temp->data = c;
        temp->left = nullptr;
        temp->right = nullptr;

        if (isOperand(c)) {
            pushNode(temp);
        }
        else {
            temp->right = popNode();
            temp->left  = popNode();
            pushNode(temp);
        }
    }

    return popNode();
}

void inorder(ETNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}

void preorder(ETNode* root) {
    if (root == nullptr) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);
}

void postorder(ETNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    ETNode* root = buildTree(postfix);

    cout << "Inorder   : ";
    inorder(root);
    cout << endl;

    cout << "Preorder  : ";
    preorder(root);
    cout << endl;

    cout << "Postorder : ";
    postorder(root);
    cout << endl;

    return 0;
}