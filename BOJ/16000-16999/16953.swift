import Foundation

var A = 0, B = 0
var cache = [Int:Int]()

func dp(_ n: Int) -> Int {
    if n > B { return 987654321 }
    if n == B { return 1 }
    
    if let ret = cache[n] { return ret }
    
    cache[n] = 1 + min(dp(n*2), dp(n*10+1))
    
    return cache[n]!
}

func solution() -> String {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    A = input[0]
    B = input[1]
    
    let result = dp(A)
    return result >= 987654321 ? "-1" : "\(result)"
}

print(solution())
