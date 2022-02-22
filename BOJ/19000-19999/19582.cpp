#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long limit[100000], prize[100000];

bool skip_before() {
    long long sum = 0;
    long long max_prize = 0;
    bool did_skip = false;
    
    for(int i=0; i<N; i++) {
        if (sum > limit[i]) {
            if (did_skip) return false;
            else {
                sum -= max_prize;
                did_skip = true;
                
                if (sum > limit[i]) return false;
            }
        }
        
        max_prize = max(max_prize, prize[i]);
        sum += prize[i];
    }
    
    return true;
}

bool skip_now() {
    long long sum = 0;
    bool did_skip = false;
    
    for(int i=0; i<N; i++) {
        if (sum > limit[i]) {
            if (did_skip) return false;
            else {
                sum -= prize[i];
                did_skip = true;
            }
        }
        
        sum += prize[i];
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> limit[i] >> prize[i];
    }
    
    if (skip_before() || skip_now()) cout << "Kkeo-eok";
    else cout << "Zzz";

    return 0;
}
