#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pair<int, int>> adj[100001];
queue<pair<int, int>> q;
bool visit[100001];

pair<pii, pii> find_first_and_second_diameter(int s) {
    memset(visit, 0, sizeof(visit));
    
    q.push({s, 0});
    visit[s] = true;
    
    pii diameter = {s, 0};
    pii second_diameter = {s, 0};
    
    while (!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        
        if (dist >= diameter.second) {
            second_diameter = diameter;
            diameter = q.front();
        }
        else if (dist > second_diameter.second) {
            second_diameter = q.front();
        }
        
        q.pop();
        
        for(int i=0; i<adj[curr].size(); i++) {
            int next = adj[curr][i].first;
            int weight = adj[curr][i].second;
            
            if (visit[next]) continue;
            
            q.push({next, dist + weight});
            visit[next] = true;
        }
    }
    
    return {diameter, second_diameter};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int s, e, w;
    
    for(int i=0; i<N-1; i++) {
        cin >> s >> e >> w;
        
        adj[s].push_back({e, w});
        adj[e].push_back({s, w});
    }
    
    pair<pii, pii> result1 = find_first_and_second_diameter(1);
    
    int start_node = result1.first.first;
    pair<pii, pii> result2 = find_first_and_second_diameter(start_node);
    
    int end_node = result2.first.first;
    pair<pii, pii> result3 = find_first_and_second_diameter(end_node);
    
    int second_diameter = max(result2.second.second, result3.second.second);
    
    cout << second_diameter;
    
    return 0;
}
