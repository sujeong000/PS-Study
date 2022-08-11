#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
string arr[51], gap[36];
bool shouldReplace[36];

int toInt(char base36) {
    if ('0' <= base36 && base36 <= '9') return base36 - '0';
    else return base36 - 'A' + 10;
}

string toString(int n) {
    if (n < 10) return to_string(n);
    else return string(1, 'A' + n - 10);
}

string add(string lhs, string rhs) {
    string ret = "";
    int l = lhs.size() - 1;
    int r = rhs.size() - 1;
    int carry = 0;
    
    while (l >= 0 && r >= 0) {
        int sum = toInt(lhs[l]) + toInt(rhs[r]) + carry;
        carry = sum / 36;
        ret += toString(sum % 36);
        
        l--; r--;
    }
    
    while (l >= 0) {
        int sum = toInt(lhs[l]) + carry;
        carry = sum / 36;
        ret += toString(sum % 36);
        
        l--;
    }
    
    while (r >= 0) {
        int sum = toInt(rhs[r]) + carry;
        carry = sum / 36;
        ret += toString(sum % 36);
        
        r--;
    }
    
    if (carry > 0) ret += toString(carry);
    reverse(ret.begin(), ret.end());
    
    return ret;
}

// 각 알파벳에 대해 Z로 바꿨을 때 얻을 수 있는 이득 계산
void calcGap() {
    for (int i=0; i<36; i++) gap[i] = "0";
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<arr[i].size(); j++) {
            int x = toInt(arr[i][j]);
            
            string s = arr[i].substr(j, arr[i].size()-j);
            s[0] = toString(35-x)[0];
            for (int k=1; k<s.size(); k++) s[k] = '0';
            if (s[0] == '0') s = "0";   // 00000은 그냥 0
            
            gap[x] = add(gap[x], s);
        }
    }
}

bool cmp(pair<string, int> lhs, pair<string, int> rhs) {
    if (lhs.first.size() != rhs.first.size()) return lhs.first.size() > rhs.first.size();
    else return lhs.first > rhs.first;
}

void replaceCharacter() {
    vector<pair<string, int>> v;
    
    for (int i=0; i<36; i++) {
        v.push_back({gap[i], i});
    }
    
    // Z로 바꿨을 때 이득이 큰 순서로 정렬
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<K; i++) {
        shouldReplace[v[i].second] = true;
    }
}

string sum() {
    string sum = "0";
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<arr[i].size(); j++) {
            int x = toInt(arr[i][j]);
            if (shouldReplace[x]) arr[i][j] = 'Z';
        }
        
        sum = add(sum, arr[i]);
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    cin >> K;
    
    calcGap();
    replaceCharacter();
    
    cout << sum();

    return 0;
}
