import Foundation

var N = 0, M = 0, islandCount = 0
var map = Array(repeating: [Int](), count: 10)
var edges = [(Int, Int, Int)]()
var parent = (0...7).map{ $0 }
var rank = Array(repeating: 1, count: 8)

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
                  (0..<M) ~= adj.col,
                  map[adj.row][adj.col] == 1 else { continue }
            
            queue.insert(adj)
            map[adj.row][adj.col] = num
        }
    }
}

func unionIsland() {
    var num = 2
    
    for i in 0..<N {
        for j in 0..<M {
            guard map[i][j] == 1 else { continue }
            
            BFS(row: i, col: j, num: num)
            islandCount += 1
            num += 1
        }
    }
}

func connectEdges() {
    for i in 0..<N {
        for j in 0..<M {
            guard map[i][j] != 0 else { continue }
            
            let adjacents = [(1,0), (-1,0), (0,1), (0,-1)]
            for adj in adjacents {
                var r = i + adj.0
                var c = j + adj.1
                
                while (0..<N) ~= r && (0..<M) ~= c && map[r][c] == 0 {
                    r += adj.0
                    c += adj.1
                }
                
                guard (0..<N) ~= r,
                      (0..<M) ~= c,
                      map[r][c] != map[i][j] else { continue }
                      
                
                let weight = abs(i-r) + abs(j-c) - 1
                if weight >= 2 {
                    edges.append((map[r][c], map[i][j], weight))
                }
            }
        }
    }
}

func find(_ x: Int) -> Int {
    if parent[x] == x { return x }
    
    parent[x] = find(parent[x])
    
    return parent[x]
}

func union(_ a: Int, _ b: Int) {
    var pa = find(a), pb = find(b)
    
    guard pa != pb else { return }
    
    if rank[pa] < rank[pb] { swap(&pa, &pb) }
    
    parent[pb] = pa
    rank[pa] += rank[pb]
}

func kruskalMST() -> Int {
    edges.sort(by: { $0.2 < $1.2 } )
    
    var cost = 0
    var count = 1
    
    for edge in edges {
        let start = edge.0
        let end = edge.1
        let weight = edge.2
        
        if find(start) != find(end) {
            cost += weight
            union(start, end)
            count += 1
        }
    }
    
    if count < islandCount { cost = 0 }
    
    return cost
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        map[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    unionIsland()
    connectEdges()
    
    let result = kruskalMST()
    print(result == 0 ? -1 : result)
}

solution()
