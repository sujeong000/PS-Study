#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int M, N;

// 모든 조카에게 길이 n짜리를 나눠줄 수 있는가
bool possible(int n) {
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        cnt += arr[i] / n;
    }
    return cnt >= M;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    // 최적화문제를 결정문제로 바꾸기
    // 불변식: possible(lo) && !possible(hi)
    int lo = 0, hi = 1000000001;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (possible(mid)) lo = mid;
        else hi = mid;
    }

    cout << lo;
}
