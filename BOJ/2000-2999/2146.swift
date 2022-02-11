import Foundation

var N = 0
var map = Array(repeating: [Int](), count: 100)

typealias Pair = (row: Int, col: Int)

struct Queue {
    var queue = [Pair]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ p: Pair) {
        queue.append(p)
    }
    
    mutating func popFront() -> Pair {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS(row: Int, col: Int, num: Int) {
    var queue = Queue()
    queue.insert(Pair(row, col))
    map[row][col] = num
    
    while !queue.isEmpty {
        let current = queue.popFront()
        let r = current.row
        let c = current.col
        
        let adjacents = [Pair(r+1,c), Pair(r-1,c), Pair(r,c-1), Pair(r,c+1)]
        for adj in adjacents {
            guard (0..<N) ~= adj.row,
                  (0..<N) ~= adj.col,
                  map[adj.row][adj.col] == 1 else { continue }
            
            queue.insert(adj)
            map[adj.row][adj.col] = num
        }
    }
}

func unionIsland() {
    var num = 2
    
    for i in 0..<N {
        for j in 0..<N {
            guard map[i][j] == 1 else { continue }
            BFS(row: i, col: j, num: num)
            num += 1
        }
    }
}

func findMinLength() -> Int {
    unionIsland()

    var minLength = 987654321
    
    for i in 0..<N*N-1 {
        let r1 = i / N, c1 = i % N
        
        guard map[r1][c1] != 0 else { continue }
        
        for j in i+1..<N*N {
            let r2 = j / N, c2 = j % N
            
            guard map[r2][c2] != 0,
                  map[r2][c2] != map[r1][c1] else { continue }
            
            let length = abs(r1 - r2) + abs(c1 - c2) - 1
            minLength = min(minLength, length)
        }
    }
    
    return minLength
}

func solution() {
    N = Int(readLine()!)!
    
    for i in 0..<N {
        map[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    let result = findMinLength()
    print(result)
}

solution()
