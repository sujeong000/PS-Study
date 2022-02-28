#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> S;
    
    int open = 0;
    int close = 0;
    
    for(int i=0; i<S.size(); i++) {
        if (S[i] == '(') open++;
        else close++;
    }
    
    int result;
    
    if (open > close) {
        int top = -1;
        int cnt_open = 0;
        
        for(int i=S.size()-1; i>=0; i--) {
            if (S[i] == ')') top++;
            else {
                cnt_open++;
                
                if (top < 0) {
                    result = cnt_open;
                    break;
                }
                else top--;
            }
        }
    }
    else {
        int top = -1;
        int cnt_close = 0;
        
        for(int i=0; i<S.size(); i++) {
            if(S[i] == '(') top++;
            else {
                cnt_close++;
                
                if (top < 0) {
                    result = cnt_close;
                    break;
                }
                else top--;
            }
        }
    }
    
    cout << result;
    
    return 0;
}
