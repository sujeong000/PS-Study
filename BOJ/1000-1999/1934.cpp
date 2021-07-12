#include <iostream>

using namespace std;

int gcd(int A, int B) {
	if (B == 0) return A;
	return gcd(B, A % B);
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);

		cout << a * b / gcd(a, b) << "\n";
	}
	
}
