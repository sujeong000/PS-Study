import Foundation

typealias Node = (row: Int, col: Int)
typealias Adjacent = (dr: Int, dc: Int)
typealias Element = (node: Node, depth: Int)

struct Queue {
    var queue = [Element]()
    var front = 0

    var isEmpty: Bool {
        return queue.isEmpty
    }
    
    mutating func insert(_ node: Element) {
        queue.append(node)
    }
    
    mutating func popFront() -> Element {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func shortestPath(maze: [[Int]], start: Node, end: Node) -> Int {
    var queue = Queue()
    var visit = Array(repeating: Array(repeating: false, count: maze.count), count: maze.count)
    
    queue.insert((start, 1))
    visit[start.row][start.col] = true
    
    while !queue.isEmpty {                                              // BFS
        let current = queue.popFront()
        
        if current.node == end { return current.depth }                 // (N, M)에 도달
        
        let adjacents: [Adjacent] = [(-1, 0), (1, 0), (0, -1), (0, 1)]  // 인접 상하좌우
        for adj in adjacents {
            let adjRow = current.node.row + adj.dr
            let adjCol = current.node.col + adj.dc
            let adjNode = (adjRow, adjCol)
            
            if !visit[adjRow][adjCol] && maze[adjRow][adjCol] == 1 {   // 방문한 적 없고 1인 칸이면
                visit[adjRow][adjCol] = true                           // 방문
                queue.insert((adjNode, current.depth + 1))
            }
        }
    }
    
    return 987654321
}

var maze = Array(repeating: Array(repeating: 0, count: 102), count: 102)

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]

for i in 1...N {
    let input = readLine()!
    
    input.enumerated().forEach {
        maze[i][$0 + 1] = Int(String($1))!
    }
}

print(shortestPath(maze: maze, start: (1, 1), end: (N, M)))
