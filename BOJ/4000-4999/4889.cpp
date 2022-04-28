#include <iostream>

using namespace std;

int make_balanced(string s) {
    int ret = 0;
    int top = -1;
    
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '{') {
            top++;
        } else {
            if (top == -1) {
                ret++;
                top++;
            }
            else top--;
        }
    }
    
    ret += (top+1)/2;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int t=1; ;t++) {
        string s;
        cin >> s;
        
        if (s[0] == '-') break;
        
        cout << t << ". ";
        cout << make_balanced(s);
        cout << "\n";
    }

    return 0;
}
