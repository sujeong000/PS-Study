import Foundation

var visit = Array(repeating: Array(repeating: false, count: 27), count: 27)
var map = Array(repeating: Array(repeating: 0, count: 27), count: 27)
var N = 0
var depth = 0

typealias Adjacent = (dr: Int, dc: Int)

func DFS(row: Int, col: Int) {
    depth += 1                  // 단지에 속하는 집의 수 기록
    visit[row][col] = true
    
    let adjacents: [Adjacent] = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for adj in adjacents {
        let adjRow = row + adj.dr
        let adjCol = col + adj.dc
        
        if !visit[adjRow][adjCol] && map[adjRow][adjCol] == 1 {
            DFS(row: adjRow, col: adjCol)
        }
    }
}

func countCC() -> [Int] {
    var ret = [Int]()
    
    for row in 1...N {
        for col in 1...N {
            if !visit[row][col] && map[row][col] == 1 {
                DFS(row: row, col: col)         // DFS 호출 횟수 = 단지 개수
                
                ret.append(depth)
                depth = 0
            }
        }
    }
    
    return ret.sorted()
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 1...N {
        let row = readLine()!
        
        row.enumerated().forEach {
            map[i][$0 + 1] = Int(String($1))!
        }
    }
    
    let countingResult = countCC()
    
    var result = ""
    result.write("\(countingResult.count)\n")
    countingResult.forEach{ result.write("\($0)\n") }
    print(result)
}

solution()
