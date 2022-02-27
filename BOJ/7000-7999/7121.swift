import Foundation

var N: Int64 = 0
var M: Int64 = 0
var K: Int64 = 0

func gcd(_ a: Int64, _ b: Int64) -> Int64 {
    if b == 0 { return a }
    
    return gcd(b, a % b)
}

func lcm(_ a: Int64, _ b: Int64) -> Int64 {
    return a * b / gcd(a, b)
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    N = input[0] + 1
    M = input[1] + 1
    K = input[2]
    
    let neither = K / lcm(max(N, M), min(N, M))
    let notPainted = K / N - neither
    let notVarnished = K / M - neither
    let both = K - notPainted - notVarnished - neither
    
    print("\(both) \(neither) \(notVarnished) \(notPainted)")
}

solution()
