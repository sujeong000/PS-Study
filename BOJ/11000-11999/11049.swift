import Foundation

typealias Pair = (row: Int, col: Int)

var N = 0
var matrix = [Pair]()
var cache = Array(repeating: Array(repeating: -1, count: 501), count: 501)

// dp(lo, hi) = lo부터 hi번째 행렬을 전부 곱하는 데 필요한 연산 횟수의 최솟값
func dp(lo: Int, hi: Int) -> Int {
    if lo == hi { return 0 }
    
    var ret = cache[lo][hi]
    if ret != -1 { return ret }
    
    for i in lo..<hi {  // 반으로 잘라 (왼쪽 결과 * 오른쪽 결과)
        let cost = dp(lo: lo, hi: i) + dp(lo: i+1, hi: hi) + matrix[lo].row * matrix[i].col * matrix[hi].col
        ret = ret == -1 ? cost : min(ret, cost)
    }
    
    cache[lo][hi] = ret
    
    return ret
}

func solution() {
    N = Int(readLine()!)!
    
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        matrix.append((row: input[0], col: input[1]))
    }
    
    print(dp(lo: 0, hi: N-1))
}

solution()
