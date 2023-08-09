#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

string s;
stack<int> st;

void pushOpening(int p) {
    st.push(p);
}

bool findOpening(int p) {
    int sum = 0;
    
    while (!st.empty() && st.top() != p) {
        if (st.top() < 0) return false;
        // 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
        sum += st.top(); st.pop();
    }
    
    // 여는 괄호를 찾지 못한 경우 -> 불가능
    if (st.empty()) return false;
    st.pop();
    
    // ‘(X)’ 의 괄호값은 2×값(X) 으로 계산된다.
    // ‘[X]’ 의 괄호값은 3×값(X) 으로 계산된다.
    if (sum == 0) st.push(-p);
    else st.push(sum * -p);
    
    return true;
}

int calcStack() {
    int ret = 0;
    
    while (!st.empty()) {
        // 괄호가 남아있는 경우 -> 불가능
        if (st.top() < 0) return 0;
        // 올바른 괄호열 X와 Y가 결합된 XY의 괄호값은 값(XY)= 값(X)+값(Y) 로 계산된다.
        ret += st.top(); st.pop();
    }
    
    return ret;
}

int solution() {
    for (auto p: s) {
        if (p == '(') {
            // ‘()’ 인 괄호열의 값은 2이다.
            pushOpening(-2);
        }
        else if (p == '[') {
            // ‘[]’ 인 괄호열의 값은 3이다.
            pushOpening(-3);
        }
        else if (p == ')') {
            if (!findOpening(-2)) return 0;
        }
        else {
            if (!findOpening(-3)) return 0;
        }
    }
    
    return calcStack();
}

int main() {
    cin >> s;
    cout << solution();
    
    return 0;
}
