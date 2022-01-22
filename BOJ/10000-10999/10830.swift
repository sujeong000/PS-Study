import Foundation

struct Matrix: CustomStringConvertible {
    let matrix: [[Int]]
    
    var size: Int {
        return matrix.count
    }
    
    subscript(index: Int) -> [Int] {
        return matrix[index]
    }
    
    static func *(lhs: Matrix, rhs: Matrix) -> Matrix {
        var result = Array(repeating: Array(repeating: 0, count: lhs.size), count: lhs.size)
        
        for i in 0..<lhs.size {
            for j in 0..<lhs.size {
                for k in 0..<lhs.size {
                    result[i][j] += (lhs[i][k] * rhs[k][j]) % 1000
                    result[i][j] %= 1000
                }
            }
        }
        
        return Matrix(matrix: result)
    }
    
    var description: String {
        var ret = ""
        
        for i in 0..<size {
            for j in 0..<size {
                ret.write("\(matrix[i][j] % 1000) ")
            }
            ret.write("\n")
        }
        
        return ret
    }
}

var cache = [Int64:Matrix]()

func multipleMatrix(matrix: Matrix, n: Int64) -> Matrix {
    if n == 1 { return matrix }
    
    if let ret = cache[n] { return ret }
    
    let halfResult = multipleMatrix(matrix: matrix, n: n / 2)
    
    if n % 2 == 0 {
        cache[n] = halfResult * halfResult
        return cache[n]!
    } else {
        cache[n] = halfResult * halfResult * matrix
        return cache[n]!
    }
}

func solution() -> String {
    let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    let N = input[0]
    let B = input[1]
    
    var matrix = [[Int]]()
    
    for _ in 0..<N {
        matrix.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
    }
    
    return multipleMatrix(matrix: Matrix(matrix: matrix), n: B).description
}

print(solution())
