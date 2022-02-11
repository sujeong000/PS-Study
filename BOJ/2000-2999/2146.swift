import Foundation

var N = 0
var map = Array(repeating: [Int](), count: 100)
var visit = Array(repeating: Array(repeating: false, count: 100), count: 100)

typealias Pair = (row: Int, col: Int, dist: Int)

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

func BFS(row: Int, col: Int) -> Int {
    visit = Array(repeating: Array(repeating: false, count: N), count: N)
    
    var zeroQueue = Queue()     // 육지에 인접한 바다들을 넣음
    var oneQueue = Queue()
    oneQueue.insert(Pair(row, col, 0))
    visit[row][col] = true
    
    while !oneQueue.isEmpty {
        let current = oneQueue.popFront()
        let r = current.row
        let c = current.col
        
        let adjacents = [Pair(r+1,c,1), Pair(r-1,c,1), Pair(r,c-1,1), Pair(r,c+1,1)].filter {
            (0..<N) ~= $0.0 && (0..<N) ~= $0.1
        }
        for adj in adjacents {
            guard !visit[adj.row][adj.col] else { continue }
            
            if map[adj.row][adj.col] == 1 {
                visit[adj.row][adj.col] = true
                oneQueue.insert(adj)
            } else {
                visit[adj.row][adj.col] = true
                zeroQueue.insert(adj)
            }
        }
    }
    
    var minLength = 987654321
    
    while !zeroQueue.isEmpty {  // 육지와 가장 인접한 바다부터 BFS시작, 다른 대륙까지의 거리를 측정
        let current = zeroQueue.popFront()
        let r = current.row
        let c = current.col
        let d = current.dist
        
        let adjacents = [Pair(r+1,c,d+1), Pair(r-1,c,d+1), Pair(r,c-1,d+1), Pair(r,c+1,d+1)].filter {
            (0..<N) ~= $0.0 && (0..<N) ~= $0.1
        }
        for adj in adjacents {
            guard !visit[adj.row][adj.col] else { continue }
            
            if map[adj.row][adj.col] == 0 {
                visit[adj.row][adj.col] = true
                if adj.dist < minLength {
                    zeroQueue.insert(adj)
                }
            } else {
                visit[adj.row][adj.col] = true
                minLength = min(minLength, d)
            }
        }
    }
    
    return minLength
}

func findMinLength() -> Int {
    var minLength = 987654321
    
    for i in 0..<N {
        for j in 0..<N {
            guard map[i][j] == 1,
                  i == 0 || map[i-1][j] == 0 || j == 0 || map[i][j-1] == 0 else { continue }
            
            minLength = min(minLength, BFS(row: i, col: j))
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
