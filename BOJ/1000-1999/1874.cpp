#include <iostream>
#include <cstring>
#include <vector>
#include <stack>

using namespace std;

stack<int> stck;
vector<int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int next = 1;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (!stck.empty() && stck.top() == x) {
			stck.pop();
			res.push_back(0);
		}
		else if (next > x) {
			res.push_back(2);
			break;
		}
		else {
			while (next <= x) {
				stck.push(next++);
				res.push_back(1);
			}
			stck.pop();
			res.push_back(0);
		}
	}

	if (res.back() > 1) cout << "NO";
	else {
		for (int i = 0; i < res.size(); i++)
			if (res[i]) cout << "+\n";
			else cout << "-\n";
	}
}
