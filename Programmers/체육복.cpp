#include <string>
#include <vector>

using namespace std;

vector<int> countDresses(int n, const vector<int>& lost, const vector<int>& reserve) {
    vector<int> ret(n+1, 1);
    
    for (auto student: lost) ret[student]--;
    for (auto student: reserve) ret[student]++;
    
    return ret;
}

int optimize(int n, vector<int>& dresses) {
    int ret = 0;
    
    for (int i=1; i<=n; i++) {
        if (dresses[i] != 0) continue;
        
        if (i > 1 && dresses[i-1] == 2) {
            dresses[i-1]--;
            dresses[i]++;
        }
        else if (i < n && dresses[i+1] == 2) {
            dresses[i+1]--;
            dresses[i]++;
        }
    }
    
    for (int i=1; i<=n; i++) {
        if (dresses[i] > 0) ret++;
    }
    
    return ret;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> dresses = countDresses(n, lost, reserve);
    answer = optimize(n, dresses);
    
    return answer;
}
