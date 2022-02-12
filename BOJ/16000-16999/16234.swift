import Foundation

var N = 0, L = 0, R = 0
var land = Array(repeating: [Int](), count: 50)
var visit = [[Bool]]()

typealias Pair = (row: Int, col: Int)

struct Queue {
    var queue = [Pair]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func push(_ p: Pair) {
        queue.append(p)
    }
    
    mutating func popFront() -> Pair {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS(row: Int, col: Int) -> Bool {
    var union = [Pair]()
    var sum = 0
    var queue = Queue()
    
    queue.push(Pair(row, col))
    visit[row][col] = true
    
    while !queue.isEmpty {
        let current = queue.popFront()
        let r = current.row
        let c = current.col
        
        union.append(current)
        sum += land[r][c]
        
        let adjacents = [Pair(r+1,c), Pair(r-1,c), Pair(r,c+1), Pair(r,c-1)]
        
        for adj in adjacents {
            guard (0..<N) ~= adj.row,
                  (0..<N) ~= adj.col,
                  !visit[adj.row][adj.col],
                  (L...R) ~= abs(land[r][c] - land[adj.row][adj.col]) else { continue }
            
            queue.push(adj)
            visit[adj.row][adj.col] = true
        }
    }
    
    for nation in union {
        land[nation.row][nation.col] = sum / union.count
    }
    
    return union.count != 1
}

func simulate() -> Int {
    var day = 0
    
    while true {
        var moveCount = 0
        visit = Array(repeating: Array(repeating: false, count: N), count: N)
        
        for i in 0..<N {
            for j in 0..<N {
                guard !visit[i][j] else { continue }
                let didMove = BFS(row: i, col: j)
                if didMove { moveCount += 1 }
            }
        }
        
        if moveCount == 0 { break }
        else { day += 1 }
    }
    
    return day
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    L = input[1]
    R = input[2]
    
    for i in 0..<N {
        land[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    let result = simulate()
    print(result)
}

solution()
