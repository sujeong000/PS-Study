import Foundation

var N = 0
var cache = Array(repeating: Array(repeating: Array(repeating: Array(repeating: -1, count: 2), count: 2), count: 2), count: 31)

func dp(index: Int, first: Int, second: Int, third: Int) -> Int {
    if index == N { return first + second + third == 0 ? 1 : 0 }
    
    var ret = cache[index][first][second][third]
    if ret != -1 { return ret }
    
    switch first + second + third {
    case 3:
        ret = dp(index: index+1, first: 0, second: 0, third: 0)
    case 2:
        ret = dp(index: index+1, first: 1-first, second: 1-second, third: 1-third)
    case 1:
        if second == 1 {
            ret = dp(index: index+1, first: 1, second: 0, third: 1)
        } else {
            let case1 = dp(index: index+1, first: 1-first, second: 1-second, third: 1-third)
            let case2 = dp(index: index+1, first: 0, second: 0, third: 0)
            ret = case1 + case2
        }
    case 0:
        let case1 = dp(index: index+1, first: 1, second: 1, third: 1)
        let case2 = dp(index: index+1, first: 1, second: 0, third: 0)
        let case3 = dp(index: index+1, first: 0, second: 0, third: 1)
        ret = case1 + case2 + case3
    default: break
    }
    
    cache[index][first][second][third] = ret
    
    return ret
}

func solution() {
    N = Int(readLine()!)!
    
    print(dp(index: 0, first: 0, second: 0, third: 0))
}

solution()
