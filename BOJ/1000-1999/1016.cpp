#include <iostream>

using namespace std;

long long MIN, MAX;
bool check[1000001];

long long solution() {
    long long cnt = MAX - MIN + 1;
    long long i = 2;
    
    while (i*i <= MAX) {
        long long x = i*i * (MIN / (i*i));
        if (x < MIN) x += i*i;
        
        while (x <= MAX) {
            if (!check[x - MIN]) {
                check[x - MIN] = true;
                cnt--;
            }
            
            x += i*i;
        }
        
        i++;
    }
    
    return cnt;
}

int main()
{
    cin >> MIN >> MAX;
    
    cout << solution();
    
    return 0;
}

