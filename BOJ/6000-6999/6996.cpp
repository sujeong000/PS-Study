#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> A;
vector<char> B;

int main() {
    int testcase;
    cin >> testcase;
    
    while (testcase--) {
        A.clear(); B.clear();

        bool res = true;
        string s1, s2;
        cin >> s1 >> s2;

        if (s1.size() != s2.size()) res = false;
        else {
            int n = s1.size();
            for (int i = 0; i < n; i++) {
                A.push_back(s1[i]); B.push_back(s2[i]);
            }

            sort(A.begin(), A.end()); sort(B.begin(), B.end());

            for (int i = 0; i < n; i++) {
                if (A[i] != B[i]) {
                    res = false;
                    break;
                }
            }
        }
        
        if(res) cout << s1 << " & " << s2 << " are anagrams.\n";
        else cout << s1 << " & " << s2 << " are NOT anagrams.\n";
    }
}
