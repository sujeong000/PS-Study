#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int A[4000], B[4000], C[4000], D[4000];
vector<int> sum;

void match_CD() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            sum.push_back(C[i] + D[j]);
        }
    }
    
    sort(sum.begin(), sum.end());
}

long long make_zero() {
    long long count = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int target = -(A[i] + B[j]);
            count += upper_bound(sum.begin(), sum.end(), target)
                    - lower_bound(sum.begin(), sum.end(), target);
        }
    }
    
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int a, b, c, d;
    for (int i=0; i<N; i++) {
        cin >> a >> b >> c >> d;
        A[i] = a; B[i] = b; C[i] = c; D[i] = d;
    }
    
    match_CD();
    cout << make_zero();

    return 0;
}
