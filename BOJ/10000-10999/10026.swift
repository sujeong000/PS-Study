import Foundation

var N = 0
var grid = Array(repeating: Array(repeating: "", count: 102), count: 102)
var visit = Array(repeating: Array(repeating: false, count: 102), count: 102)

typealias Adjacent = (dr: Int, dc: Int)

func dfs(row: Int, col: Int) {
    visit[row][col] = true
    
    let color = grid[row][col]
    
    let adjacents: [Adjacent] = [(1,0), (-1,0), (0,1), (0,-1)]
    for adj in adjacents {
        let adjRow = row + adj.dr
        let adjCol = col + adj.dc
        
        let adjColor = grid[adjRow][adjCol]
        let adjVisit = visit[adjRow][adjCol]
        
        if !adjVisit && adjColor == color {
            dfs(row: adjRow, col: adjCol)
        }
    }
}

func countCC() -> Int {
    var count = 0
    
    for row in 1...N {
        for col in 1...N {
            if !visit[row][col] {
                dfs(row: row, col: col)
                count += 1
            }
        }
    }
    
    return count
}

func makeColorBlindness() {
    for i in 0..<102 {
        for j in 0..<102 {
            if grid[i][j] == "G" { grid[i][j] = "R" }
        }
    }
}

func resetVisit() {
    visit = Array(repeating: Array(repeating: false, count: 102), count: 102)
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 1...N {
        let input = readLine()!
        input.enumerated().forEach { grid[i][$0 + 1] = String($1) }
    }
    
    let notColorBlindness = countCC()
    
    makeColorBlindness()
    resetVisit()
    
    let colorBlindness = countCC()
    
    print("\(notColorBlindness) \(colorBlindness)")
}

solution()
