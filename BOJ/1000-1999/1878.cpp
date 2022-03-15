#include <iostream>
#include <vector>

using namespace std;

long long N;
vector<int> lefts;
vector<int> rights;

int height(int sz) {
    int base = 1;
    int sum = 0;
    int h = 0;
    
    while (sum < sz) {
        sum += base;
        base *= 2;
        h++;
    }
    
    return h;
}

int power(int x) {
    if (x == 0) return 1;
    
    int ret = 1;
    for(int i=0; i<x; i++) ret *= 2;
    
    return ret;
}

void preorder(int lo, int hi, bool is_left) {
    if (lo > hi) return;
    if (lo == hi) {
        if (is_left) cout << lefts[lo] << " ";
        else cout << rights[lo] << " ";
        return;
    }
    
    int sz = hi - lo + 1;
    int h = height(sz);
    int remain = sz - (power(h-1) - 1);
    int bigger_subtree_size = power(h-2) - 1 + min(remain, power(h-2));
    
    int root;
    if (is_left) {
        root = lo + bigger_subtree_size;
        cout << lefts[root] << " ";
    }
    else {
        root = hi - bigger_subtree_size;
        cout << rights[root] << " ";
    }
    
    preorder(lo, root-1, is_left);
    preorder(root+1, hi, is_left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    if (N < 4 || (N % 2 == 0 && (N * (N+1) / 2) % 2 != 0)) {
        cout << -1 << "\n";
        return 0;
    }
    
    if (N == 5) {
        cout << "5 1\n2 4\n";
        return 0;
    }
    
    // N이 짝수: 끝과 끝을 묶음으로 생각해서 반으로 나누면 됨
    // N이 홀수: 중간수를 제외하고,
        // 1. 남은 수가 짝수개인 경우: 짝수와 똑같이 처리
        // 2. 남은 수가 홀수개인 경우: 가운데 6개만 제외하고 짝수와 똑같이 처리, 가운데 6개는 좌우우좌좌우로 나누면 합이 항상 같음.
    
    if (N % 2 == 0) {
        
        for (int i=1; i<=N/2; i++) {
            if (i % 2 != 0) lefts.push_back(i);
            else rights.push_back(i);
        }
        for (int i=N/2+1; i<=N; i++) {
            if (i % 2 != 0) rights.push_back(i);
            else lefts.push_back(i);
        }
    }
    else {
        for (int i=1; i<=N/2-3; i++) {
            if (i % 2 != 0) lefts.push_back(i);
            else rights.push_back(i);
        }
        
        if (N/2 % 2 != 0) {
            lefts.push_back(N/2-2);
            rights.push_back(N/2-1);
            rights.push_back(N/2);
            
            lefts.push_back(N/2+2);
            lefts.push_back(N/2+3);
            rights.push_back(N/2+4);
        }
        else {
            rights.push_back(N/2-2);
            lefts.push_back(N/2-1);
            rights.push_back(N/2);
            
            rights.push_back(N/2+2);
            lefts.push_back(N/2+3);
            rights.push_back(N/2+4);
        }
        
        for (int i=N/2+5; i<=N; i++) {
            if ((N - i + 1) % 2 != 0) lefts.push_back(i);
            else rights.push_back(i);
        }
    }
    
    preorder(0, lefts.size()-1, true);
    cout << "\n";
    preorder(0, rights.size()-1, false);
    cout << "\n";
    
    return 0;
}
