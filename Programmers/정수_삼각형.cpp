#include <string>
#include <vector>

using namespace std;

const int MAX = 500;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    vector<vector<int>> dp(N, vector<int>(N, 0));
    
    for (int i=0; i<N; i++) {
        dp[N-1][i] = triangle[N-1][i];
    }
    for (int i=N-2; i>=0; i--) {
        for (int j=0; j<N; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    
    return answer = dp[0][0];
}
