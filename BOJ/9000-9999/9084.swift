import Foundation

var N = 0, M = 0
var arr = [Int]()
var cache = [[Int64]]()

func dp(idx: Int, price: Int) -> Int64 {
    if idx == N { return price == 0 ? 1 : 0 }
    
    var ret = cache[idx][price]
    if ret != -1 { return ret }
    
    ret = 0
    var cnt = 0
    
    while price - arr[idx] * cnt >= 0 {
        ret += dp(idx: idx+1, price: price - arr[idx] * cnt)
        cnt += 1
    }
    
    cache[idx][price] = ret
    
    return ret
}

func initTestcase() {
    cache = Array(repeating: Array(repeating: -1, count: 10_001), count: 21)
}

func solution() {
    var resultString = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        initTestcase()
        
        N = Int(readLine()!)!
        arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
        M = Int(readLine()!)!
        
        let result = dp(idx: 0, price: M)
        resultString.write("\(result)\n")
        
        T -= 1
    }
    
    print(resultString)
}

solution()
