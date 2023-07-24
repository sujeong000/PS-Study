#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcRainwaterInColumn(int c, vector<int>& heights) {
    vector<int>::iterator s = heights.begin();
    vector<int>::iterator e = heights.end();
    
    // 둘러싸고 있는 양쪽 블록 중 각각 가장 높은 블록을 구함
    int left_max = *max_element(s, s + c);
    int right_max = *max_element(s + c + 1, e);
    
    // 그 중 더 낮은 블록 높이까지 빗물이 고임
    int limit = min(left_max, right_max);
    int accumulated_rainwater = max(0, limit - heights[c]);
    
    return accumulated_rainwater;
}

int solution(int H, int W, vector<int>& heights) {
    int answer = 0;
    
    // 양 끝 열에는 고일 수 없음
    for (int i = 1; i < (W - 1); i++) {
        answer += calcRainwaterInColumn(i, heights);
    }
    
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, W;
    vector<int> heights;
    
    cin >> H >> W;
    heights.resize(W);
    for (int i = 0; i < W; i++) {
        cin >> heights[i];
    }
    
    cout << solution(H, W, heights);

    return 0;
}
