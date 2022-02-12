import Foundation

var N = 0, M = 0
var arr = Array(repeating: [Int](), count: 8)
var minBlindSpot = 987654321

enum Direction: CaseIterable {
    case up, down, left, right
    
    static func directions(_ n: Int) -> [[Direction]] {
        switch n {
        case 1:
            return [[.up], [.down], [.left], [.right]]
        case 2:
            return [[.left, .right], [.up, .down]]
        case 3:
            return [[.up, .right], [.right, .down], [.down, .left], [.left, .up]]
        case 4:
            return [[.up, .left, .right], [.right, .up, .down], [.down, .right, .left], [.left, .down, .up]]
        case 5:
            return [[.up, .down, .left, .right]]
        default:
            return [[]]
        }
    }
}

func countBlindSpot() -> Int {
    var count = 0
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] == 0 { count += 1 }
        }
    }
    
    return count
}

func monitor(row: Int, col: Int, direction: Direction, cancel: Bool) {
    var dr = 0, dc = 0
    
    switch direction {
    case .up:
        dr = -1
    case .down:
        dr = 1
    case .left:
        dc = -1
    case .right:
        dc = 1
    }
    
    var r = row + dr
    var c = col + dc
    
    while (0..<N) ~= r && (0..<M) ~= c {
        guard arr[r][c] != 6 else { break }
        
        if cancel {
            if arr[r][c] < 0 { arr[r][c] += 1 }
        } else {
            if arr[r][c] < 1 { arr[r][c] -= 1 }
        }
        
        r += dr
        c += dc
    }
}

func bruteForce(row: Int, col: Int) {
    if row >= N {
        minBlindSpot = min(minBlindSpot, countBlindSpot())
        return
    }
    
    let nextRow = (row * M + col + 1) / M
    let nextCol = (row * M + col + 1) % M
    
    switch arr[row][col] {
    case 1, 2, 3, 4, 5:
        for direction in Direction.directions(arr[row][col]) {
            for d in direction { monitor(row: row, col: col, direction: d, cancel: false) }
            bruteForce(row: nextRow, col: nextCol)
            for d in direction { monitor(row: row, col: col, direction: d, cancel: true) }
        }
    default:
        bruteForce(row: nextRow, col: nextCol)
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        arr[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    bruteForce(row: 0, col: 0)
    
    print(minBlindSpot)
}

solution()
