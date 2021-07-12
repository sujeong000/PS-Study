#include <iostream>
#include <string>

using namespace std;

int main() {
	string target;
	cin >> target;

	int N;
	cin >> N;

	int ans = 0;
	for (int i = 0; i < N; i++) {
		string curr;
		cin >> curr;

		curr = curr + curr;
		ans += (curr.find(target) != string::npos);
	}

	cout << ans;
}
