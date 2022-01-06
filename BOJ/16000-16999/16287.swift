import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let w = input[0]
let n = input[1]
let weights = readLine()!.split(separator: " ").map{ Int(String($0))! }

var dp = Array(repeating: false, count: 799995)

func solution() -> Bool {
    for i in (0..<n-1) {
        // 다음과 같이 두 개를 뽑는다: (i, [i+1...]에서 한 개)
        for j in (i+1..<n) {
            let sum = weights[i] + weights[j]
            
            guard sum < w else { continue }
            
            if dp[w - sum] { return true }  // [0...i-1]에서 두 개를 뽑아 w-sum을 만들 수 있었는지 체크
        }
        
        // 다음과 같이 두 개를 뽑는다: ([0...i-1]에서 한 개, i)
        for j in (0..<i) {
            let sum = weights[i] + weights[j]
            
            guard sum < w else { continue }
            
            dp[sum] = true  // 뽑은 두 개로 만들 수 있는 sum들을 기록해둠
        }
    }
    
    return false
}

print(solution() ? "YES" : "NO")
