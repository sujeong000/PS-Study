#include <iostream>

using namespace std;

int gcd(int A, int B) {
	if (B == 0) return A;
	return gcd(B, A % B);
}

int main() {
	int A, B;
	cin >> A >> B;
	if (A < B) swap(A, B);

	int gcdAB = gcd(A, B);
	cout << gcdAB << "\n";
	cout << A * B / gcdAB;
}
