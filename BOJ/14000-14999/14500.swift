import Foundation

var N = 0, M = 0
var paper = Array(repeating: Array(repeating: -999999, count: 510), count: 510)

typealias Tetromino = (dr: Int, dc: Int)

let tetromino: [[Tetromino]] =
[
    [(0,1), (0,2), (0,3)],  // ㅡ
    [(1,0), (2,0), (3,0)],  // ㅣ
    [(0,1), (1,0), (1,1)],  // ㅁ
    [(0,1), (0,2), (1,1)],  // ㅜ
    [(1,0), (1,1), (2,0)],  // ㅏ
    [(1,-1), (1,0), (2,0)], // ㅓ
    [(1,-1), (1,0), (1,1)], // ㅗ
    [(0,1), (1,1), (2,1)],  // 세로로 길쭉한 ㄱ
    [(0,1), (1,0), (2,0)],  // Г
    [(0,1), (0,2), (-1,2)], // ㅢ
    [(1,0), (1,1), (1,2)],  // 가로로 길쭉한 ㄴ
    [(1,0), (2,0), (2,1)],  // L
    [(0,1), (-1,1), (-2,1)], // L 대칭
    [(0,1), (0,2), (1,2)],  // ￢
    [(0,1), (0,2), (1,0)],  // 가로로 길쭉한 Г
    [(1,0), (1,1), (2,1)],  // ㅣ-ㅣ
    [(0,1), (-1,1), (1,0)], // 위에거 대칭
    [(0,1), (1,1), (1,2)],   // ㅡㅣㅡ
    [(0,1), (-1,1), (-1,2)]   // 위에거 대칭
]

func solution() -> Int {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 3..<N+3 {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        for j in 0..<M {
            paper[i][j+3] = input[j]
        }
    }
    
    var maxSum = 0
    
    for row in 3..<N+3 {
        for col in 3..<M+3 {
            for ttm in tetromino { // 19가지 경우를 다 놓아본다
                var sum = paper[row][col]
                
                for i in 0..<3 {
                    sum += paper[row + ttm[i].dr][col + ttm[i].dc]
                }
                
                maxSum = max(maxSum, sum)
            }
        }
    }
    
    return maxSum
}

print(solution())
