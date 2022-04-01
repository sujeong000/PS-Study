#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

int T, V;
ll cache[44];

// 높이 height짜리 AVL tree로 만들기 위한 최소 노드 개수
ll min_num_of_vertex(int height) {
    if (height == 1) return 1;
    if (height == 2) return 2;
    
    ll& ret = cache[height];
    if (ret != -1) return ret;
    
    return ret = min_num_of_vertex(height-1) + min_num_of_vertex(height-2) + 1;
}

int find_max_height(int v) {
    for (int i=1; i<44; i++) {
        if (min_num_of_vertex(i) > v) return i-1;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(cache, -1, sizeof(cache));

    cin >> T;
    while (T--) {
        cin >> V;
        cout << find_max_height(V) << "\n";
    }

    return 0;
}
