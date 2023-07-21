#include <string>
#include <vector>

using namespace std;

vector<bool> binary;

// check(lo, hi): 이진트리를 중위순회한 결과가 binary일 때, 서브트리 [lo,hi]가 가능한 구조인지 검사하는 함수
bool check(int lo, int hi) {
    if (lo == hi) return true;
    
    int mid = (lo + hi) / 2;    // 루트
    int lc = (lo + mid-1) / 2;  // 왼쪽 자식
    int rc = (mid+1 + hi) / 2;  // 오른쪽 자식
    
    // 부모가 0인데 자식이 1인 것은 불가능
    if (!binary[mid] && (binary[lc] || binary[rc])) {
        return false;
    }

    return check(lo, mid-1) && check(mid+1, hi);
}

// calcIdealSize(curr_len): 현재 노드 개수가 curr_len개일 때, 포화이진트리로 만들 경우 전체 노드의 개수
int calcIdealSize(int curr_size) {
    for (int i=1; i<=6; i++) {
        // 포화이진트리의 노드 개수는 2^n - 1개
        int len = (1 << i) - 1;
        if (curr_size <= len) return len;
    }
    
    return -1;
}

// toBinary(n): 십진수 n을 이진수로 변환하는 함수
void toBinary(long long n) {
    while (n > 0) {
        binary.push_back(n % 2);
        n /= 2;
    }
    
    // 빈 곳은 모두 더미노드(0)로 채워서 포화이진트리로 만들기
    int ideal_size = calcIdealSize(binary.size());
    while (binary.size() < ideal_size) {
        binary.push_back(0);
    }
}

void initTestcase() {
    binary.clear();
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for (auto number: numbers) {
        initTestcase();
        
        toBinary(number);
        answer.push_back(check(0, binary.size()-1));
    }
    
    return answer;
}
