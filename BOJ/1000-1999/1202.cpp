#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, less<int>> max_pq;

int N, K;
int p;
vector<pair<int, int>> gems;
vector<int> backpacks;

int fillBackpack(int index) {
    while (p < N && gems[p].first <= backpacks[index])  {    // 배낭에 들어갈 수 있는 보석 전부 우선순위큐에 삽입
        max_pq.push(gems[p++].second);
    }
    
    if (max_pq.empty()) {
        return 0;
    }
    else {
        int ret = max_pq.top(); max_pq.pop();   // 들어갈 수 있는 보석 중 최대 가치인 것을 담음
    return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int w, v, c;
	
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        cin >> w >> v;
        gems.push_back({w, v});
    }
    
    for (int i = 0; i < K; i++) {
        cin >> c;
        backpacks.push_back(c);
    }
    
    sort(gems.begin(), gems.end());             // 무게 오름차순 정렬
    sort(backpacks.begin(), backpacks.end());   // 용량 오름차순 정렬
    
    long long result = 0;
    
    for (int i = 0; i< K; i++) {
        result += (long long)fillBackpack(i);              // 배낭을 순서대로 채움
    }
    
    cout << result;

    return 0;
}
