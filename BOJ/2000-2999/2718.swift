import Foundation

var N = 0
var cache = [[Int]]()

func dp(n: Int, bitmask: Int) -> Int {
    if n == N + 1 { return bitmask == 0 ? 1 : 0 }
    
    var ret = cache[n][bitmask]
    if ret != -1 { return ret }
    
    let next: [Int]
    switch bitmask {
    case 0: next = [0, 3, 9, 12, 15]
    case 1: next = [2, 8, 14]
    case 2: next = [1, 13]
    case 3: next = [0, 12]
    case 4: next = [8, 11]
    case 5: next = [10]
    case 6: next = [9]
    case 7: next = [8]
    case 8: next = [1, 4, 7]
    case 9: next = [0, 6]
    case 10: next = [5]
    case 11: next = [4]
    case 12: next = [0, 3]
    case 13: next = [2]
    case 14: next = [1]
    case 15: next = [0]
    default:
        next = []
    }
    
    ret = 0
    next.forEach{ ret += dp(n: n+1, bitmask: $0) }
     
    cache[n][bitmask] = ret
    
    return ret
}

func initTestcase() {
    cache = Array(repeating: Array(repeating: -1, count: 16), count: 1001)
}

func solution() {
    var resultString = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        initTestcase()
        
        N = Int(readLine()!)!
        
        resultString.write("\(dp(n: 1, bitmask: 0))\n")
        
        T -= 1
    }
    
    print(resultString)
}

solution()
