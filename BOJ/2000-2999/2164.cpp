#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);

	while (1) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}

		q.pop();

		if (q.size() == 1) {
			cout << q.front();
			break;
		}

		q.push(q.front()); q.pop();
	}
}
