import Foundation

var N = 0
var board = Array(repeating: [Int](), count: 10)
var cache = Array(repeating: Array(repeating: Array(repeating: Array(repeating: -1, count: (1 << 10)), count: (1 << 10)), count: 10), count: 10)

func findDiagonal(row: Int, col: Int) -> (left: Int, right: Int) {
    let left = (row + col) / 2
    let right = (row + (N - 1 - col)) / 2
    
    return (left, right)
}

func check(row: Int, col: Int, leftDiagonal: Int, rightDiagonal: Int) -> Bool {
    let diagonals = findDiagonal(row: row, col: col)
    let checkLeft = leftDiagonal & (1 << diagonals.left) == 0
    let checkRight = rightDiagonal & (1 << diagonals.right) == 0
    let checkBoard = board[row][col] == 1
    
    return checkLeft && checkRight && checkBoard
}

func next(row: Int, col: Int) -> (row: Int, col: Int) { // 다음 검은/흰 칸 반환
    var nextRow = row
    var nextCol = col + 2
    
    if nextCol >= N {
        nextCol += 1
        nextCol %= 2
        nextRow += 1
    }
    
    return (nextRow, nextCol)
}

func dp(row: Int, col: Int, leftDiagonal: Int, rightDiagonal: Int) -> Int {
    if row >= N { return 0 }
    
    var ret = cache[row][col][leftDiagonal][rightDiagonal]
    if ret != -1 { return ret }
    
    let next = next(row: row, col: col)
    
    // 1. (row, col)에 놓지 않는 경우
    let skip = dp(row: next.row,
                  col: next.col,
                  leftDiagonal: leftDiagonal,
                  rightDiagonal: rightDiagonal)
    ret = max(ret, skip)
    
    // 2. (row, col)에 놓는 경우
    if check(row: row, col: col, leftDiagonal: leftDiagonal, rightDiagonal: rightDiagonal) {
        let diagonals = findDiagonal(row: row, col: col)
        let put = 1 + dp(row: next.row,
                         col: next.col,
                         leftDiagonal: leftDiagonal | (1 << diagonals.left),
                         rightDiagonal: rightDiagonal | (1 << diagonals.right))
        ret = max(ret, put)
    }
    
    cache[row][col][leftDiagonal][rightDiagonal] = ret
    
    return ret
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 0..<N {
        board[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    let black = dp(row: 0, col: 0, leftDiagonal: 0, rightDiagonal: 0)   // 체스판의 검은 칸
    let white = dp(row: 0, col: 1, leftDiagonal: 0, rightDiagonal: 0)   // 체스판의 흰 칸
    let result = black + white
    
    print(result)
}

solution()
