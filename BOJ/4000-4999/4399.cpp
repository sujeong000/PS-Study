#include <iostream>
#include <algorithm>

using namespace std;

string sol[1001];   // sol[i] = 길이가 i인 x

void make_palinedrome(string s) {
    // 문자열 s를 총 길이 len인 팰린드롬으로 만들기 위한 x를 구한다.
    // 그러한 x는 유일하다.
    for (int len=s.size(); len<=2*s.size(); len++) {
        string x = "";
        
        for (int i=len/2-1; i>=0; i--) {
            if (len-1-i < s.size()) {
                if (s[i] != s[len-1-i]) {
                    x = "Z";
                    break;
                }
            }
            else {
                x += s[i];
            }
        }

        if (x == "Z") continue;
        
        if (sol[x.size()] == "Z") sol[x.size()] = x;
        else {
            if (sol[x.size()] == x) sol[x.size()] = "Z";    // 둘 다 팰린드롬으로 만들면 안됨
            else sol[x.size()] = min(sol[x.size()], x);
        }
    }
}

string find_x(string A, string B) {
    if (A == B) return "No Solution.";
    if (A.size() > B.size()) swap(A, B);
    
    // 둘 중 하나만 팰린드롬으로 만드는 가장 짧은 x를 찾는다.
    make_palinedrome(A);
    make_palinedrome(B);
    
    
    for (int i=0; i<=A.size(); i++) {   // 길이 0인 x도 가능하다;
        if (sol[i] != "Z") return sol[i];
    }
    
    // 길이가 len(A) 이하인 x를 찾지 못했으면,
    // 길이가 2*len(A)+1 인 팰린드롬을 만들어준다.
    reverse(A.begin(), A.end());
    
    if (sol[A.size()+1] == "a"+A) return "b"+A;
    else return min(sol[A.size()+1], "a"+A);
}

void init_testcase() {
    for (int i=0; i<1001; i++) sol[i] = "Z";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    string A, B;
    
    while (getline(cin, A)) {
        getline(cin, B);
        
        init_testcase();
        cout << find_x(A, B) << "\n";  
    }

    return 0;
}
