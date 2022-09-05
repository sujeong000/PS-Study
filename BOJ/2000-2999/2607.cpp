#include <iostream>
#include <vector>

using namespace std;

int N;
string S;
vector<int> s_alpha_cnt;

vector<int> countAlphabet(string s) {
    vector<int> ret(26, 0);
    
    for (auto c: s) {
        ret[c-'A']++;
    }
    
    return ret;
}

bool check(string word) {
    vector<int> word_alpha_cnt = countAlphabet(word);
    vector<int> diff;
    
    for (int i=0; i<26; i++) {
        if (word_alpha_cnt[i] != s_alpha_cnt[i]) {
            diff.push_back(word_alpha_cnt[i] - s_alpha_cnt[i]);
        }
    }
    
    // 같은 구성을 갖는 경우
    if (diff.empty()) return true;
    // 한 문자를 더하거나 빼는 경우
    if (diff.size() == 1 && abs(diff[0]) == 1) return true;
    // 하나의 문자를 다른 문자로 바꾸는 경우
    if (diff.size() == 2 && abs(diff[0]) == 1 && diff[0] + diff[1] == 0) return true;
    
    return false;
}

int solution() {
    int ret = 0;
    
    s_alpha_cnt = countAlphabet(S);
    
    for (int i=0; i<N-1; i++) {
        string temp;
        cin >> temp;
        
        if (check(temp)) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> S;

    cout << solution();
    
    return 0;
}
