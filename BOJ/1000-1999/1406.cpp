#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> lst, rst;

void L() {
    if (lst.empty()) return;
    rst.push(lst.top());
    lst.pop();
}

void D() {
    if (rst.empty()) return;
    lst.push(rst.top());
    rst.pop();
}

void B() {
    if (lst.empty()) return;
    lst.pop();
}

void P(char c) {
    lst.push(c);
}

string calcString() {
    string ret = "";
    
    while (!lst.empty()) {
        rst.push(lst.top());
        lst.pop();
    }
    
    while (!rst.empty()) {
        ret += rst.top();
        rst.pop();
    }
    
    return ret;
}

int main() {
    string S;
    int M;
    
    cin >> S;
    for (auto c: S) {
        lst.push(c);
    }
    
    cin >> M;
    while (M--) {
        char cmd;
        cin >> cmd;
        
        if (cmd == 'L') L();
        else if (cmd == 'D') D();
        else if (cmd == 'B') B();
        else {
            char c;
            cin >> c;
            P(c);
        }
        
    }
    
    cout << calcString();
    
    return 0;
}
