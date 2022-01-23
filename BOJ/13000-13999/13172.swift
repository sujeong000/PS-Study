import Foundation

let MOD: Int64 = 1_000_000_007

func gcd(a: Int64, b: Int64) -> Int64 {
    if b == 0 { return a }
    
    return gcd(a: b, b: a % b)
}

func pow(n: Int64, x: Int64) -> Int64 {
    if x == 1 { return n % MOD }
    
    let half = pow(n: n, x: x/2)
    
    if x % 2 == 0 {
        return half * half % MOD
    } else {
        return ((half * half) % MOD * n) % MOD
    }
}

func modularInverse(n: Int64) -> Int64 {
    return pow(n: n, x: MOD - 2)
}

func solution() -> String {
    let M = Int(readLine()!)!
    
    var result: Int64 = 0
    
    for _ in 0..<M {
        let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
        var b = input[0]
        var a = input[1]
        
        let gcd = gcd(a: max(a, b), b: min(a, b))
        a /= gcd
        b /= gcd
        
        result += (a * modularInverse(n: b) % MOD) % MOD
        result %= MOD
    }
    
    return "\(result)"
}

print(solution())
