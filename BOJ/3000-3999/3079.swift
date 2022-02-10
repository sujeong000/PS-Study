import Foundation

var N = 0, M = 0
var T = [Int64]()

func decision(time: Int64) -> Bool { // time 시간 내에 N명을 모두 심사하는 것이 가능한가?
    var maxCount: Int64 =  0         // time 시간 동안 최대로 심사할 수 있는 사람 수
    
    for cost in T {                  // 모든 심사관이 쉬지 않고 심사한다.
        maxCount += time / cost
    }
    
    return maxCount >= M
}

func optimize() -> Int64 {
    var lo: Int64 = 0, hi = T[0] * Int64(M)
    
    // 반복문 불변식 : !decision(lo) && decision(hi)
    for _ in 0..<100 {
        let mid = (lo + hi) / 2
        if decision(time: mid) { hi = mid }
        else { lo = mid }
    }
    
    return hi
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    T = Array(repeating: 0, count: N)
    
    for i in 0..<N {
        T[i] = Int64(readLine()!)!
    }
    
    let result = optimize()
    print(result)
}

solution()
