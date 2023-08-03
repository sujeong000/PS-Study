#include <iostream>

using namespace std;

int k;
char signs[10];
int pick[10];
bool is_used[10];
string max_ans = "0000000000", min_ans = "9999999999";

string pickToString() {
    string ret = "";
    for (int i=0; i<=k; i++) {
        ret += pick[i] + '0';
    }
    return ret;
}

void updateAnswer() {
    string ans = pickToString();
    max_ans = max(max_ans, ans);
    min_ans = min(min_ans, ans);
}

void backtrack(int idx) {
    if (idx > k) updateAnswer();
    
    for (int i=0; i<10; i++) {
        if (is_used[i]) continue;
        if (signs[idx-1] == '<' && pick[idx-1] > i) continue;
        else if (signs[idx-1] == '>' && pick[idx-1] < i) continue;
        
        is_used[i] = true;
        pick[idx] = i;
        backtrack(idx+1);
        is_used[i] = false;
    }
}

int main()
{
    cin >> k;
    for (int i=0; i<k; i++) cin >> signs[i];
    
    backtrack(0);
    
    cout << max_ans << "\n" << min_ans;

    return 0;
}
