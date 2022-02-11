import Foundation

var N = 0
var forest = Array(repeating: [Int](), count: 500)
var cache = Array(repeating: Array(repeating: -1, count: 500), count: 500)

func dp(row: Int, col: Int) -> Int {
    var ret = cache[row][col]
    if ret != -1 { return ret }
    
    ret = 1
    let adjacents = [(row-1,col), (row+1,col), (row,col-1), (row,col+1)].filter {
        (0..<N) ~= $0.0 && (0..<N) ~= $0.1
    }
    for adj in adjacents {
        guard forest[adj.0][adj.1] > forest[row][col] else { continue }
        ret = max(ret, 1 + dp(row: adj.0, col: adj.1))
    }
    
    cache[row][col] = ret
    
    return ret
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 0..<N {
        forest[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    var maxMove = 0
    for i in 0..<N {
        for j in 0..<N {
            maxMove = max(maxMove, dp(row: i, col: j))
        }
    }
    print(maxMove)
}

solution()
