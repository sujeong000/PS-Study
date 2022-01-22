import Foundation

var N = 0, M = 0
var map = Array(repeating: Array(repeating: 1, count: 1001), count: 1001)

typealias Node = (row: Int, col: Int, didBreak: Int)
struct Queue {
    var queue = [Node]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ n: Node) {
        queue.append(n)
    }
    
    mutating func popFront() -> Node {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS() -> Int {
    var queue = Queue()
    var dist = Array(repeating: Array(repeating: Array(repeating: 987654321, count: 2), count: 1001), count: 1001)  // dist[row][col][didBreak]
    
    dist[0][0][0] = 1
    queue.insert((0, 0, 0))
    
    while !queue.isEmpty {
        let current = queue.popFront()
        let row = current.row
        let col = current.col
        let didBreak = current.didBreak
        
        let adjacents = [(row+1, col), (row-1, col), (row, col+1), (row, col-1)].filter {
            return (0..<N) ~= $0 && (0..<M) ~= $1
        }
        
        for adj in adjacents {
            let adjRow = adj.0
            let adjCol = adj.1
            
            if map[adjRow][adjCol] == 0 {
                if dist[row][col][didBreak] + 1 < dist[adjRow][adjCol][didBreak] {
                    dist[adjRow][adjCol][didBreak] = dist[row][col][didBreak] + 1
                    queue.insert((adjRow, adjCol, didBreak))
                }
            } else {
                guard didBreak == 0 else { continue }
                
                if dist[row][col][didBreak] + 1 < dist[adjRow][adjCol][1] {
                    dist[adjRow][adjCol][1] = dist[row][col][didBreak] + 1
                    queue.insert((adjRow, adjCol, 1))
                }
            }
        }
    }
    
    return min(dist[N-1][M-1][0], dist[N-1][M-1][1])
}

func solution() -> String {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        let row = readLine()!
        row.enumerated().forEach {
            map[i][$0] = Int(String($1))!
        }
    }
    
    let result = BFS()
    
    return "\(result == 987654321 ? -1 : result)"
}

print(solution())
