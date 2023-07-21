#include <string>
#include <vector>

using namespace std;

struct PayResult {
    int purchase_cost;  // 이모티콘 구매 비용
    int subscription;   // 이모티콘 플러스 서비스 가입 여부
    
    PayResult& operator+=(const PayResult& pr) {
        purchase_cost += pr.purchase_cost;
        subscription += pr.subscription;
        return *this;
    }
    
    bool operator<(PayResult& pr) const {
        // 플러스 서비스 가입자를 최대한 늘리는 것이 우선
        if (subscription != pr.subscription) return subscription < pr.subscription;
        return purchase_cost < pr.purchase_cost;
    }
};

struct User {
    int percentage; // 이모티콘 구매 기준 비율
    int threshold;  // 서비스가입 기준 가격
};

PayResult max(PayResult& lhs, PayResult& rhs) {
    return (lhs < rhs) ? rhs: lhs;
}

// 각 이모티콘의 할인율이 sales일 때 user의 구매 결과를 구하는 함수
PayResult calcPayResult(User user, vector<int>& emoticons, vector<int>& sales) {
    PayResult result = {0, 0};
    
    // 총 구매 금액 계산
    for (int i=0; i<emoticons.size(); i++) {
        if (sales[i] >= user.percentage) {
            result.purchase_cost += emoticons[i] * (100 - sales[i]) / 100;
        }
    }
    
    // threshold 이상인 경우 플러스 서비스 가입
    if (result.purchase_cost >= user.threshold) {
        result.purchase_cost = 0;
        result.subscription = 1;
    }
    
    return result;
}

// 각 이모티콘의 할인율이 sales일 때 전체 사용자의 구매 결과를 구하는 함수
PayResult calcTotalPayResult(vector<User>& users, vector<int>& emoticons, vector<int>& sales) {
    PayResult result = {0, 0};
    
    for (auto user: users) {
        result += calcPayResult(user, emoticons, sales);
    }
    
    return result;
}

// 비트마스크로 나타낸 n개의 이모티콘에 대한 할인율을 퍼센트로 변환하여 percentages 벡터에 담는 함수
void bitmaskToPercentage(int n, int mask, vector<int>& percentages) {
    percentages.resize(n, 0);
    
    for (int i=0; i<n; i++) {
        // 00=10%, 01=20%, 10=30%, 11=40%
        int submask = mask % 4; mask /= 4;
        percentages[i] = (submask + 1) * 10;
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    // User 구조체 변환
    
    int un = users.size();
    vector<User> n_users(un);
    
    for (int i=0; i<un; i++) {
        n_users[i] = {users[i][0], users[i][1]};
    }
    
    
    // 브루트포스 - 각 이모티콘의 할인률을 설정하는 모든 경우의 수를 시도해보고 최댓값을 찾음
    
    int en = emoticons.size();
    PayResult max_result = {0, 0};
    vector<int> sales;
    
    // 4가지의 할인율을 가질 수 있으므로, 이모티콘 1개당 2비트 필요
    for (int mask = 0; mask < (1 << 2*en); mask++) {
        bitmaskToPercentage(en, mask, sales);
        PayResult temp_result = calcTotalPayResult(n_users, emoticons, sales);
        max_result = max(max_result, temp_result);
    }
    
    
    answer.push_back(max_result.subscription);
    answer.push_back(max_result.purchase_cost);
    
    return answer;
}
