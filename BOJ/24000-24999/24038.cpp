#include <iostream>
#include <map>
#include <cmath>

using namespace std;

string S;

pair<char, int> solve(int lo, int hi, char turn) {
    char next_turn = turn == 'I' ? 'O' : 'I';
    
    // 1. 양 끝이 모두 상대 것인 경우: turn의 패배
    if (S[lo] == S[hi] && S[lo] != turn) return {next_turn, hi - lo + 2};
    
    // 2. 양 끝 중 하나만 자기 것인 경우: 선택권 없이 자기 것을 제거해야 함
    if (S[lo] != S[hi]) {
        if (S[lo] == turn) return solve(lo+1, hi, next_turn);
        else return solve(lo, hi-1, next_turn);
    }
    
    // 3. 양 끝이 모두 자기 것인 경우: 둘 중 더 이득인 쪽을 제거해야 함
    // OO...O 이거나 II...I이면 이김, 이러한 상황으로 만들어야 함.
    int lo_combo = lo, hi_combo = hi;
    while (lo_combo < hi && S[lo_combo] != S[lo_combo+1]) lo_combo++;
    while (hi_combo > lo && S[hi_combo] != S[hi_combo-1]) hi_combo--;
    
    // 3-1. IO가 계속 번갈아 나오는 경우: turn의 수가 1개 더 많으므로 승리
    // 3-2. 현재 플레이어만 이기는 케이스(OO...O)를 만들 수 있는 경우: 현재 플레이어의 승리
    // 3-3. 반대 플레이어만 이기는 케이스를 만들 수 있는 경우: 상대 플레이어의 승리
    // 3-4. 둘 다 이기는 케이스를 만들 수 있는 경우: 현재 플레이어가 선을 쥐고 있으므로 현재 플레이어의 승리
    
    if (lo_combo == hi) {
        return {turn, 1};
    }
    else if (S[lo_combo] == S[hi_combo] && S[lo_combo] == turn) {
        return {turn, max(hi_combo - lo + 1, hi - lo_combo + 1)};
    }
    else if (S[lo_combo] == S[hi_combo] && S[lo_combo] == next_turn) {
        return {next_turn, hi_combo - lo_combo};
    }
    else {
        if (S[lo_combo] == turn) return {turn, hi - lo_combo + 1};
        else return {turn, hi_combo - lo + 1};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> S;
        
        pair<char, int> result = solve(0, S.size()-1, 'I');
        cout << "Case #" << t << ": ";
        cout << result.first << " " << result.second << "\n";
    }

    return 0;
}
