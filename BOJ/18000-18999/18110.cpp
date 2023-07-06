#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int calcAvg(vector<int>& v, int lo, int hi) {
    int sum = 0;
    
    for (int i=lo; i<=hi; i++) {
        sum += v[i];
    }
    
    return round((float)sum / (hi - lo + 1));
}

int main()
{
    int n, answer;
    vector<int> opinions;
    
    cin >> n;
    opinions.resize(n);
    for (int i=0; i<n; i++) {
        cin >> opinions[i];
    }
    
    sort(opinions.begin(), opinions.end());
    
    if (n == 0) {
        answer = 0;
    }
    else {
        int excluded = round(0.15 * n);
        answer = calcAvg(opinions, excluded, n-excluded-1);
    }
    
    cout << answer;
}
