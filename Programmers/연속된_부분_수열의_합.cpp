#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int lo = 0, hi = 0, sum = sequence[0];
    
    while (lo <= hi && hi < sequence.size()) {
        if (sum == k) {
            if (answer.empty() || (answer[1] - answer[0] > hi - lo)) {
                answer = {lo, hi}; 
            }
        }
        
        if (sum < k) {  // k보다 작은 경우 더 추가해야 함
            hi++;
            sum += sequence[hi];
        }
        else {  // k보다 큰 경우 빼야 함
            sum -= sequence[lo];
            lo++;
        }
    }
    
    return answer;
}
