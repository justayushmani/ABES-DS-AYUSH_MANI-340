#include <iostream>
#include <cctype>   
#include <string>
using namespace std;

char stack[100];  
int top = -1;      

int priority(char a) {
    if (a == '(') {
        return 0;
    }
    if (a == '+' || a == '-') {
        return 1;
    }
    if (a == '*' || a == '/') {
        return 2;
    }
    if (a == '^') {
        return 3;
    }
    return -1;
}

void push(char a) {
    stack[++top] = a;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

int main() {
    string str = "(A+b-c*d)";
    string postfix = "";

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];

        if (isalnum(c)) { 
            postfix += c;
        } 
        else if (c == '(') {
            push(c);
        } 
        else if (c == ')') {
            while (stack[top] != '(') {
                postfix += pop();
            }
            pop();
        } 
        else { 
            while (top != -1 && priority(stack[top]) >= priority(c)) {
                postfix += pop();
            }
            push(c);
        }
    }
   while (top != -1) {
        postfix += pop();
    }

    cout << "Postfix: " << postfix << endl;
    return 0;
}
