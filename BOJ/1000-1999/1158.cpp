#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";
	while (1) {
		for (int i = 0; i < K-1; i++) {
			int x = q.front(); q.pop();
			q.push(x);
		}
		cout << q.front(); q.pop();

		if (q.empty()) break;
		cout << ", ";
	}
	cout << ">";
}
