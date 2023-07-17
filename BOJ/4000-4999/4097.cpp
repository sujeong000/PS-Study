#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (1) {
        int N;
        cin >> N;
        if (N == 0) break;
        
        vector<int> profits(N+1, 0);
        for (int i=1; i<=N; i++) cin >> profits[i];
        
        // dp[i]: i일로 끝나는 구간 중 최고수익 구간의 수익
        vector<int> dp(N+1);
        int max_profit = -(1e5+1);
        for (int i=1; i<=N; i++) {
            // (i-1)일로 끝나는 구간에 i일을 더하기 or i일로 구간 새로 시작
            dp[i] = max(dp[i-1] + profits[i], profits[i]);
            max_profit = max(max_profit, dp[i]);
        }
        
        cout << max_profit << "\n";
    }
}
