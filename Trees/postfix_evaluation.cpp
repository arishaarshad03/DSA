#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* top = nullptr;

void push(char val) {
    Node* newnode = new Node;
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

char pop() {
    if (top == nullptr) {
        cout << "stack underflow\n";
        return '\0';
    }
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

char peek() {
    if (top == nullptr) return '\0';
    return top->data;
}

struct INode {
    int data;
    INode* next;
};

INode* top2 = nullptr;

void push2(int val) {
    INode* newnode = new INode;
    newnode->data = val;
    newnode->next = top2;
    top2 = newnode;
}

int pop2() {
    if (top2 == nullptr) {
        cout << "stack underflow\n";
        return 0;
    }
    INode* temp = top2;
    int val = temp->data;
    top2 = top2->next;
    delete temp;
    return val;
}

int precedence(char opr) {
    switch (opr) {
        case '|': return 1;
        case '&': return 2;
        case '<':
        case '>':
        case '=':
        case '!': return 3;
        case '+':
        case '-': return 4;
        case '*':
        case '/':
        case '%': return 5;
        default: return 0;
    }
}


string convert(string infix) {
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z')) {
            postfix += c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (top != nullptr && peek() != '(') {
                postfix += pop();
            }
            if (top != nullptr) pop(); // remove '('
        }

        else {
            while (top != nullptr &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }

    while (top != nullptr) {
        postfix += pop();
    }

    return postfix;
}


int evaluatePostfix(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (c >= '0' && c <= '9') {
            push2(c - '0');
        }
        else {
            int val2 = pop2();
            int val1 = pop2();

            if (c == '+') push2(val1 + val2);
            else if (c == '-') push2(val1 - val2);
            else if (c == '*') push2(val1 * val2);
            else if (c == '/') push2(val1 / val2);
            else if (c == '%') push2(val1 % val2);
        }
    }

    return pop2();
}


int main() {
    string infix;

    cout << "Enter infix: ";
    cin >> infix;

    string postfix = convert(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}