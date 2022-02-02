import Foundation

let R = 0, G = 1, B = 2, INF = 987654321
var N = 0
var cost = Array(repeating: Array(repeating: -1, count: 3), count: 1001)
var cache = Array(repeating: Array(repeating: Array(repeating: INF, count: 3), count: 3), count: 1001)

func dp(index: Int, first: Int, before: Int) -> Int {
    if index == N { return 0 }
    
    var ret = cache[index][first][before]
    if ret != INF { return ret }
    
    if index == N-1 {
        for color in [R, G, B].filter({ $0 != before && $0 != first}) {
            ret = min(ret, cost[index][color] + dp(index: index+1, first: first, before: color))
        }
    } else if index == 0 {
        ret = cost[index][first] + dp(index: index+1, first: first, before: first)
    } else {
        for color in [R, G, B].filter({ $0 != before }) {
            ret = min(ret, cost[index][color] + dp(index: index+1, first: first, before: color))
        }
    }
        
    
    cache[index][first][before] = ret
    
    return ret
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        cost[i][R] = input[R]
        cost[i][G] = input[G]
        cost[i][B] = input[B]
    }
    
    print(min(dp(index: 0, first: R, before: R),
              dp(index: 0, first: G, before: G),
              dp(index: 0, first: B, before: B)))
}

solution()
