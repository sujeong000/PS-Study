import Foundation

let INF = 987654321
let C = 0, U = 1, L = 2, D = 3, R = 4
var N = 0
var arr = [Int]()
var cache = Array(repeating: Array(repeating: Array(repeating: INF, count: 5), count: 5), count: 100_001)

func calcCost(before: Int, after: Int) -> Int {
    if before == 0 {
        return 2
    } else if before == after {
        return 1
    } else if before + 2 == after || before - 2 == after {
        return 4
    } else {
        return 3
    }
}

// dp(index, left, right): 현재 두 발의 위치가 left, right일 때 arr[index...]를 모두 밟는 비용
func dp(index: Int, left: Int, right: Int) -> Int {
    if index == N { return 0 }
    
    var ret = cache[index][left][right]
    if ret != INF { return ret }
    
    let next = arr[index]
    if right != next {  // 왼쪽 발을 움직임
        ret = min(ret, calcCost(before: left, after: next) + dp(index: index+1, left: next, right: right))
    }
    if left != next {   // 오른쪽 발을 움직임
        ret = min(ret, calcCost(before: right, after: next) + dp(index: index+1, left: left, right: next))
    }
    
    cache[index][left][right] = ret
    
    return ret
}

func solution() {
    arr = readLine()!.split(separator: " ").map{ Int(String($0))! }.dropLast()
    N = arr.count
    
    let result: Int
    
    if N == 0 {
        result = 0
    } else {
        result = 2 + min(dp(index: 1, left: arr[0], right: 0), dp(index: 1, left: 0, right: arr[0]))
    }
    
    print(result)
}

solution()
