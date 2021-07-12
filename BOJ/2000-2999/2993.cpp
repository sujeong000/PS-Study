#include <iostream>
#include <string>

using namespace std;

// 문자열 s의 start부터 end를 뒤집는다
void reverse_string(string& s, int start, int end) {
	int length = end - start + 1;
	for (int i = 0; i < length / 2; i++) {
		swap(s[start + i], s[end - i]);
	}
}

// S를 p에서 한번, q에서 한번 잘라 세 부분으로 쪼개 새 단어 만들기
string make_new_string(string s, int p, int q) {
	reverse_string(s, 0, p);
	reverse_string(s, p + 1, q);
	reverse_string(s, q + 1, s.length() - 1);

	return s;
}

int main() {
	string s;
	cin >> s;

	string min_string = s;
	// a에서 한 번, b에서 한 번 자름
	for (int a = 0; a < s.length() - 2; a++) {
		for (int b = a+1; b < s.length() - 1; b++) {
			min_string = min(min_string, make_new_string(s, a, b));
		}
	}

	cout << min_string;
}
