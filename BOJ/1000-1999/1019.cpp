#include <iostream>

using namespace std;

int N;
int cnt[11];

void count(int x, int power) {
    while (x > 0) {
        cnt[x % 10] += power;
        x /= 10;
    }
}

int main()
{
    cin >> N;
    
    int s = 1, e = N, power = 1;
    
    while (s <= e) {
        while (e % 10 != 9 && s <= e) count(e--, power);
        if (s > e) break;
        while (s % 10 != 0 && s <= e) count(s++, power);
        
        s /= 10;
        e /= 10;
        
        for (int i=0; i<=9; i++) cnt[i] += (e - s + 1) * power;
        
        power *= 10;
    }
    
    for (int i=0; i<=9; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}
