#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

string solution(string keylog) {
    stack<char> forth;  
    stack<char> back;   
    
    for (auto c: keylog) {
        switch (c) {
            case '-':
                if (!forth.empty()) forth.pop();
                break;
            case '<':
                if (!forth.empty()) {
                    back.push(forth.top());
                    forth.pop();
                }
                break;
            case '>':
                if (!back.empty()) {
                    forth.push(back.top());
                    back.pop();
                }
                break;
            default:
                forth.push(c);
                break;
        }
    }
    
    string ret = "";
    
    while (!forth.empty()) {
        ret += forth.top();
        forth.pop();
    }
    
    reverse(ret.begin(), ret.end());
    
    while (!back.empty()) {
        ret += back.top();
        back.pop();
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << solution(s) << "\n";
    }

    return 0;
}
