#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int maxVal = -1000001;
	int minVal = 1000001;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		maxVal = max(maxVal, x);
		minVal = min(minVal, x);
	}

	cout << minVal << " " << maxVal;
}
