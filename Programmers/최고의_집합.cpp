#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) return {-1};
    
    int n_avg = n - s % n;
    vector<int> answer(n_avg, s/n);
    
    while (answer.size() < n) {
        answer.push_back(s/n+1);
    }
    
    return answer;
}
