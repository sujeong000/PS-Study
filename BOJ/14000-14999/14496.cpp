#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int adj[1001][1001];
int d[1001];
const int INF = 987654321;
queue<int> q;
int N, M, a, b;

int dijkstra(int start, int end) {
	for (int i = 1; i < 1001; i++) d[i] = INF;
	d[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next = 1; next <= N; next++) {
			if (adj[cur][next]) {
				if (d[next] > d[cur] + 1) {
					d[next] = d[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	return d[end];
}

int main() {
	cin >> a >> b;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		adj[x][y] = adj[y][x] = 1;
	}

	int ans = dijkstra(a, b);
	cout << ((ans == INF) ? -1 : ans);
}
