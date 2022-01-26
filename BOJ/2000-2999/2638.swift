import Foundation

let cheese = 1, noCheese = 0, air = -1
var N = 0, M = 0
var arr = Array(repeating: [Int](), count: 100)
var visit = [[Bool]]()

func DFS(row: Int, col: Int) {
    visit[row][col] = true
    arr[row][col] = air
    
    let adjacents = [(row+1, col), (row-1, col), (row, col+1), (row, col-1)].filter {
        (0..<N) ~= $0.0 && (0..<M) ~= $0.1
    }
    
    for adj in adjacents {
        let adjRow = adj.0
        let adjCol = adj.1
        
        guard !visit[adjRow][adjCol] && arr[adjRow][adjCol] != cheese else { continue }
        DFS(row: adjRow, col: adjCol)
    }
}

func contactWithAir() {
    visit = Array(repeating: Array(repeating: false, count: 100), count: 100)
    DFS(row: 0, col: 0)
}

func meltCheese() {
    for row in 0..<N {
        for col in 0..<M {
            guard arr[row][col] == cheese else { continue }
            
            let adjacents =  [(row+1, col), (row-1, col), (row, col+1), (row, col-1)].filter {
                (0..<N) ~= $0.0 && (0..<M) ~= $0.1
            }
            let adjacentsAir = adjacents.filter { arr[$0.0][$0.1] == air }
            
            if adjacentsAir.count >= 2 { arr[row][col] = noCheese }
        }
    }
}

func checkNoMoreCheese() -> Bool {
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] == cheese { return false }
        }
    }
    
    return true
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        arr[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    var count = 0
    
    while !checkNoMoreCheese() {
        contactWithAir()
        meltCheese()
        
        count += 1
    }
    
    print(count)
}

solution()
