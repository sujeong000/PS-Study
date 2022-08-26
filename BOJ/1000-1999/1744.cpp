#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
int one_cnt;
vector<ll> positives, negatives;

ll optimize(const vector<ll>& nums) {
    ll sum = 0;
    int n = nums.size();
    
    for (int i=0; i<n; i+=2) {
        if (i == n-1) sum += nums[i];
        else sum += nums[i] * nums[i+1];
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        ll temp;
        cin >> temp;
        if (temp == 1) one_cnt++;
        else if (temp > 0) positives.push_back(temp);
        else negatives.push_back(temp);
    }
    
    sort(positives.begin(), positives.end(), greater<ll>());
    sort(negatives.begin(), negatives.end());
    
    ll ans = optimize(positives) + optimize(negatives) + one_cnt;
    
    cout << ans;
    
    return 0;
}
