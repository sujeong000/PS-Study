#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<char> lq, rq;

void L() {
    if (lq.empty()) return;
    rq.push(lq.top());
    lq.pop();
}

void D() {
    if (rq.empty()) return;
    lq.push(rq.top());
    rq.pop();
}

void B() {
    if (lq.empty()) return;
    lq.pop();
}

void P(char c) {
    lq.push(c);
}

string calcString() {
    string ret = "";
    
    while (!lq.empty()) {
        rq.push(lq.top());
        lq.pop();
    }
    
    while (!rq.empty()) {
        ret += rq.top();
        rq.pop();
    }
    
    return ret;
}

int main() {
    string S;
    int M;
    
    cin >> S;
    for (auto c: S) {
        lq.push(c);
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
