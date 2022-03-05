import Foundation

var N = 0, M = 0, K = 0
var arr = Array(repeating: [Int](), count: 301)
var psum = Array(repeating: Array(repeating: 0, count: 301), count: 301)

func calcPsum() {
    for i in 1...N {
        for j in 1...M {
            psum[i][j] = psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1] + arr[i][j]
        }
    }
}

func sum(_ i: Int, _ j: Int, _ x: Int, _ y: Int) -> Int {
    return psum[x][y] - psum[x][j-1] - psum[i-1][y] + psum[i-1][j-1]
}

func solution() {
    var resultString = ""
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    arr[0] = Array(repeating: 0, count: M)
    
    for i in 1...N {
        arr[i] = [0] + readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    calcPsum()
    
    K = Int(readLine()!)!
    
    for _ in 0..<K {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let i = input[0]
        let j = input[1]
        let x = input[2]
        let y = input[3]
        
        let result = sum(i, j, x, y)
        resultString.write("\(result)\n")
    }
    
    print(resultString)
}

solution()
