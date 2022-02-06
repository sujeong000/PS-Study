import Foundation

let MOD: Int64 = 1_000_000_007
let adjacents: [[Int64]] =
[
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 0, 1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 1, 0]
]

func multiplyMatrix(_ m1: [[Int64]], _ m2: [[Int64]]) -> [[Int64]] {
    var result = Array(repeating: Array(repeating: Int64(0), count: m1.count), count: m2[0].count)
    
    for i in 0..<m1.count {
        for j in 0..<m2[0].count {
            for k in 0..<m1[0].count {
                result[i][j] += (m1[i][k] * m2[k][j]) % MOD
                result[i][j] %= MOD
            }
        }
    }
    
    return result
}

func power(n: Int, matrix: [[Int64]]) -> [[Int64]] {
    if n == 1 { return matrix }
    
    let half = power(n: n/2, matrix: matrix)
    
    if n % 2 == 0 {
        return multiplyMatrix(half, half)
    } else {
        return multiplyMatrix(multiplyMatrix(half, half), matrix)
    }
}

func solution() {
    let D = Int(readLine()!)!
    
    // 인접 행렬을 n제곱하면 i에서 j로 가는 길이 n짜리 경로의 수를 구할 수 있음
    print(power(n: D, matrix: adjacents)[0][0])
}

solution()
