#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    
    long long stackTop = -1, sum = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') stackTop++;
        else {
            if (s[i-1] == '(') sum += stackTop; // 레이저인 경우 쌓인 막대 개수만큼 조각이 추가됨
            else sum += 1;                      
            stackTop--;
        }
    }
    
    cout << sum;

    return 0;
}
