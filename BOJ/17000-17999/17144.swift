import Foundation

var R = 0, C = 0, T = 0
var arr = Array(repeating: [Int](), count: 100)
var visit = [[Bool]]()
var airCleanerPos = -1

func diffuse() {
    var after = arr
    
    for i in 0..<R {
        for j in 0..<C {
            guard arr[i][j] > 0 else { continue }
            
            let diffuseAmount = arr[i][j] / 5
            let adjacents = [(i+1,j), (i-1,j), (i,j+1), (i,j-1)].filter {
                (0..<R) ~= $0.0 && (0..<C) ~= $0.1 && arr[$0.0][$0.1] >= 0
            }
            
            for adj in adjacents { after[adj.0][adj.1] += diffuseAmount }
            after[i][j] -= diffuseAmount * adjacents.count
        }
    }
    
    arr = after
}

func cleanAir() {
    var after = arr
    
    // upper
    after[airCleanerPos-1] = [-1, 0] + arr[airCleanerPos-1].dropLast().dropFirst()
    for row in 1...airCleanerPos-1 { after[row-1][C-1] = arr[row][C-1] }
    after[0] = arr[0].dropFirst() + [arr[1][C-1]]
    for row in 0...airCleanerPos-3 { after[row+1][0] = arr[row][0] }
    
    // lower
    after[airCleanerPos] = [-1, 0] + arr[airCleanerPos].dropLast().dropFirst()
    for row in airCleanerPos...R-2 { after[row+1][C-1] = arr[row][C-1] }
    after[R-1] = arr[R-1].dropFirst() + [arr[R-2][C-1]]
    for row in airCleanerPos+2...R-1 { after[row-1][0] = arr[row][0] }
    
    arr = after
}

func calcDust() -> Int {
    var sum = 0
    
    for i in 0..<R {
        for j in 0..<C {
            if arr[i][j] > 0 { sum += arr[i][j] }
        }
    }
    
    return sum
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    R = input[0]
    C = input[1]
    T = input[2]
    
    for i in 0..<R {
        arr[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        if arr[i][0] == -1 { airCleanerPos = i }
    }
    
    for _ in 0..<T {
        diffuse()
        cleanAir()
    }
    
    print(calcDust())
}

solution()
