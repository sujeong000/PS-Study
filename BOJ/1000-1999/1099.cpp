#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int INF = 987654321;

int N;
string sentence, words[51];
int cache[51], check_cache[51][51];

// check(start_idx, word_idx): sentence[start_idx]부터 word_idx번 단어를 매칭시키는 비용
int check(int start_idx, int word_idx) {
    int& ret = check_cache[start_idx][word_idx];
    if (ret != -1) return ret;
    
    string word = words[word_idx];
    if (start_idx + word.size() > sentence.size()) return ret = INF;
    
    ret = 0;
    vector<int> alpha(26);  // 알파벳별 등장 횟수 기록
    for (int i=0; i<word.size(); i++) {
        int word_c = word[i] - 'a';
        int sentence_c = sentence[start_idx+i] - 'a';
        
        alpha[word_c]++;
        alpha[sentence_c]--;
        if (word_c != sentence_c) ret++;
    }
    
    for (int i=0; i<26; i++) {
        if (alpha[i] != 0) return ret = INF;
    }
    
    return ret;
}

// dp(idx) : 부분문자열 sentence[idx...]의 최소 비용
int dp(int idx) {
    if (idx >= sentence.size()) return 0;
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    // 모든 단어들에 매칭 시킨 뒤 최소 비용을 찾는다
    ret = INF;
    for (int i=0; i<N; i++) {
        int cost = check(idx, i);
        if (cost != INF) ret = min(ret, cost + dp(idx+words[i].size()));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    memset(check_cache, -1, sizeof(check_cache));
    
    cin >> sentence;
    cin >> N;
    for (int i=0; i<N; i++) cin >> words[i];
    
    int ans = dp(0);
    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}
