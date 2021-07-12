#include <iostream>
#include <cmath>

using namespace std;

int solve(int a, int b) {
	//cout << a << " " << b << "\n";
	long long height_a = ceil(sqrt(a));
	long long height_b = ceil(sqrt(b));
	if (height_a == height_b) return abs(a - b);

	long long middle_a = height_a * height_a - height_a + 1;
	long long middle_b = height_b * height_b - height_b + 1;
	long long delta_a = a - middle_a;
	long long delta_b = b - middle_b;

	int move = 0;
	if (!(height_a % 2 == 0 && a % 2 == 0) || (height_a % 2 == 1 && a % 2 == 1)) {
		if (delta_a < delta_b) a++;
		else a--;

		move++;
	}
	
	move++;
	return move + solve((height_a + 1) * (height_a + 1) - (height_a * height_a - a + 1), b);
	
}

int main() {
	int A, B;
	cin >> A >> B;
	if (A > B) swap(A, B);

	cout << solve(A, B);
}
