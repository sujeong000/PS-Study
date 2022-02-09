import Foundation

var n = 0, k = 0
var coins = Array(repeating: 0, count: 101)
var dp = Array(repeating: Int64(0), count: 10_001)

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    n = input[0]
    k = input[1]
    
    for i in 0..<n { coins[i] = Int(readLine()!)! }
    
    dp[0] = 1
    
    for i in 0..<n {
        let coin = coins[i]
        
        for sum in 1...k {
            guard coin <= sum else { continue }
            dp[sum] += dp[sum - coin]
            if dp[sum] >= (1 << 31) { dp[sum] = 0 }
        }
    }
    
    print(dp[k])
}

solution()
