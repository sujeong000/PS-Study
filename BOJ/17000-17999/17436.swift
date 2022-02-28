import Foundation

var N = 0, M: Int64 = 0
var arr = [Int64]()

func gcd(_ a: Int64, _ b: Int64) -> Int64 {
    if b == 0 { return a }
    return gcd(b, a%b)
}

func lcm(_ a: Int64, _ b: Int64) -> Int64 {
    return a * b / gcd(a, b)
}

func lcm(_ mask: Int) -> Int64 {
    var LCM: Int64 = 1
    
    for i in 0..<N {
        guard ((1 << i) & mask) != 0 else { continue }
        LCM = lcm(max(arr[i], LCM), min(arr[i], LCM))
    }
    
    return LCM
}

func countOne(_ mask: Int) -> Int64 {
    var count: Int64 = 0
    
    for i in 0..<N {
        if ((1 << i) & mask) != 0 { count += 1 }
    }
    
    return count
}

func countUnion() -> Int64 {
    var ret = M
    
    for i in 0..<(1 << N) {
        if countOne(i) % 2 == 0 { ret -= M / lcm(i) }
        else { ret += M / lcm(i) }
    }
    
    return ret
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    N = Int(input[0])
    M = input[1]
    
    arr = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    
    let result = countUnion()
    print(result)
}

solution()
