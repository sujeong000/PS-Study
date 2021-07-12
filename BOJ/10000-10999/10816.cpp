#include <iostream>
#include <cstring>
#include <map>

using namespace std;

map<int, long> mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (mp.find(x) == mp.end()) mp.insert(make_pair(x, 1));
		else mp[x]++;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		if (mp.find(x) == mp.end()) cout << 0 << " ";
		else cout << mp[x] << " ";
	}
}
