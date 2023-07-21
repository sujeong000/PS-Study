#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dp = n-1;   // 배달할 거리가 남아있는 집 중 가장 먼 곳
    int pp = n-1;   // 수거할 거리가 남아있는 집 중 가장 먼 곳
    int truck = cap;  // 트럭에 실린 물건 수
    
    while (dp >= 0 || pp >= 0) {
        int dist = 0;
        
        // 배달은 갈 때
        while (truck > 0 && dp >= 0) {
            // 배달
            int amount = min(truck, deliveries[dp]);
            deliveries[dp] -= amount;
            truck -= amount;
            
            // 가장 먼 곳 업데이트
            if (amount != 0) dist = max(dist, dp+1);
            
            // dp번 집에 모든 배달을 완료한 경우 포인터 업데이트
            if (deliveries[dp] == 0) dp--;
        }
        
        // 배달할 곳이 없는 경우 트럭 비우고 출발
        if (dp == -1) truck = 0;
        
        // 수거는 올 때
        while (truck < cap && pp >= 0) {
            // 수거
            int amount = min(cap - truck, pickups[pp]);
            pickups[pp] -= amount;
            truck += amount;
            
            // 가장 먼 곳 업데이트
            if (amount != 0) dist = max(dist, pp+1);
    
            // pp번 집에서 모든 수거를 완료한 경우 포인터 업데이트
            if (pickups[pp] == 0) pp--;
        }
        
        // 물류창고로 돌아옴
        answer += dist * 2;
        truck = cap;
    }
    
    return answer;
}
