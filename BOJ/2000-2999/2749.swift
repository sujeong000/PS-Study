import Foundation

struct Matrix {
    let arr: [[Int64]]
    
    init(arr: [[Int64]] = [[1, 1], [1, 0]]) {
        self.arr = arr
    }
    
    subscript(index: Int) -> [Int64] {
        return arr[index]
    }
    
    static func *(lhs: Matrix, rhs: Matrix) -> Matrix {
        var result = Array(repeating: Array(repeating: Int64(0), count: 2), count: 2)
        
        for i in 0..<2 {
            for j in 0..<2 {
                for k in 0..<2 {
                    result[i][j] += (lhs[i][k] * rhs[k][j]) % 1_000_000
                    result[i][j] %= 1_000_000
                }
            }
        }
        
        return Matrix(arr: result)
    }
}

var dict = [Int64:Matrix]()

func fibo(_ n: Int64) -> Matrix {
    if n == 1 { return Matrix() }
    
    if let ret = dict[n] { return ret }
    
    if n % 2 == 0 {
        dict[n] = fibo(n / 2) * fibo(n / 2)
        return dict[n]!
    } else {
        dict[n] = fibo(n / 2) * fibo(n / 2) * Matrix()
        return dict[n]!
    }
}

func solution() -> String {
    let n = Int64(readLine()!)!
    return "\(fibo(n)[0][1])"
}

print(solution())
