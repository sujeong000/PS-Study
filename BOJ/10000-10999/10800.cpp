#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
    int sz, color, idx;
} Ball;

int N;
vector<Ball> balls;

bool cmp(const Ball& lhs, const Ball& rhs) {
    if (lhs.sz != rhs.sz) return lhs.sz < rhs.sz;
    if (lhs.color != rhs.color) return lhs.color < rhs.color;
    return lhs.idx < rhs.idx;
}

vector<int> solution() {
    vector<int> ans(N, 0);
    vector<int> color_sum(N+1, 0);   // color_sum[color] = color색인 공들의 사이즈 합
    int i = 0;
    int total_sum = 0;
    
    // 사이즈 오름차순 정렬
    sort(balls.begin(), balls.end(), cmp);
    
    for (auto ball: balls) {
        // ball보다 작은 모든 공들에 대해
        while (balls[i].sz < ball.sz) {
            Ball small_ball = balls[i];
            total_sum += small_ball.sz;
            color_sum[small_ball.color] += small_ball.sz;
            i++;
        }
        
        // (ball보다 작으면서 다른 색의 공들) = (ball보다 작은 모든 공들) - (ball보다 작으면서 같은 색의 공들)
        ans[ball.idx] = total_sum - color_sum[ball.color];
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int c, s;
        cin >> c >> s;
        balls.push_back({s, c, i});
    }
    
    auto ans = solution();
    for (auto x: ans) cout << x << "\n";

    return 0;
}
