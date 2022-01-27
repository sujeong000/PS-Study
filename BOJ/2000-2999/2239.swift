import Foundation

var findSolution = false
var state = [[Int]]()

func sudoku(index: Int) {
    if findSolution { return }
    
    for i in index..<81 {
        let row = i / 9
        let col = i % 9
        
        if state[row][col] == 0 {
            for n in 1...9 {
                if checkPossible(row: row, col: col, num: n, state: state) {
                    state[row][col] = n
                    sudoku(index: i+1)
                }
            }
            
            state[row][col] = 0
            return
        }
    }
    
    findSolution = true
    printSudoku()
}

func checkPossible(row: Int, col: Int, num: Int, state: [[Int]]) -> Bool {
    let blockRow = row / 3 * 3
    let blockCol = col / 3 * 3
    
    for i in 0..<9 {
        if state[row][i] == num { return false }            // 같은 행 검사
        if state[i][col] == num { return false }            // 같은 열 검사
        let dr = i / 3
        let dc = i % 3
        if state[blockRow+dr][blockCol+dc] == num { return false }    // 같은 블록 검사
    }
    
    return true
}

func printSudoku() {
    for i in 0..<9 {
        for j in 0..<9 {
            print(state[i][j], terminator: "")
        }
        print()
    }
}

func solution() {
    for _ in 0..<9 {
        state.append(readLine()!.map{ Int(String($0))! })
    }
    
    sudoku(index: 0)
}

solution()
