#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H;
vector<int> up, down; // up=종유석, down=석순

pair<int, int> optimize() {
    pair<int, int> ret = {N, 1};
    
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    
    for (int h=0; h<H; h++) {
        int down_cnt = down.size() - (upper_bound(down.begin(), down.end(), 0.5+h) - down.begin());
        int up_cnt = upper_bound(up.begin(), up.end(), 0.5+h) - up.begin();
        int total_cnt = up_cnt + down_cnt;
        
        if (total_cnt < ret.first) ret = {total_cnt, 1};
        else if (total_cnt == ret.first) ret.second++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> H;
    
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        
        if (i % 2 == 0) down.push_back(temp);
        else up.push_back(H-temp);
    }
    
    auto ans = optimize();
    cout << ans.first << " " << ans.second;

    return 0;
}
