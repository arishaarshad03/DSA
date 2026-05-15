#include <iostream>
using namespace std;

// stack operations

#define N 100
char stack[N];

int top = -1;
void push (char data){
    if (top >= N-1){
        cout <<"stack overflow";
    }
    else{
        top ++;
        stack[top] = data;
    }
}
char pop(){
    if (top <0){
        cout <<"stack underflow";
        return 0;
    }
    char val = stack[top];
    top --;
    return val;
}

int precedence(char opr){
    switch(opr){
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

string convert(string infix){
    string postfix = "";

    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];

        // check if its operand or operator 
        if ((c >= 'A' && c <= 'Z')||(c >= 'a' && c <= 'z')||(c>= '0' && c<='9')){
            // its operand, write in postfix
            postfix = postfix + c;
        }
        else if (c == '('){
            push (c);
        }
        else if (c == ')' ){
            // keep popping until ( is found
            while (top != -1 && stack[top] != '('){
                postfix = postfix + pop();
            }
            // just delete (
            if (top != -1)
            pop();
        }
        else{
            while (top != -1 && stack[top] != '(' && precedence(stack[top])>= precedence(c)){
                postfix += pop();
            }
            push(c);
        }
    }
    while (top != -1){
        postfix += pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout<<"enter infix: ";
    cin>> infix;

    string postfix = convert(infix);
    cout <<postfix;

}