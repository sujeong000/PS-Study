import Foundation

var N = 0, M = 0
var map = Array(repeating: [Character](), count: 1001)
var parent = Array(repeating: Array(repeating: Pair(0,0), count: 1001), count: 1001)
var rank = Array(repeating: Array(repeating: 0, count: 1001), count: 1001)
var visit = Array(repeating: Array(repeating: false, count: 1001), count: 1001)

struct Pair: Hashable {
    let row: Int
    let col: Int
    
    init(_ row: Int, _ col: Int) {
        self.row = row
        self.col = col
    }
}

func find(_ p: Pair) -> Pair {
    if parent[p.row][p.col] == p { return p }
    
    parent[p.row][p.col] = find(parent[p.row][p.col])
    
    return parent[p.row][p.col]
}

func union(_ p1: Pair, _ p2: Pair) {
    var parentP1 = find(p1), parentP2 = find(p2)
    
    if parentP1 == parentP2 { return }
    
    if rank[parentP1.row][parentP1.col] < rank[parentP2.row][parentP2.col] {
      swap(&parentP1, &parentP2)
    }
    
    parent[parentP2.row][parentP2.col] = parentP1
    rank[parentP1.row][parentP1.col] += rank[parentP2.row][parentP2.col]
}

func DFS(_ p: Pair) {
    visit[p.row][p.col] = true
    
    let dr: Int, dc: Int
    
    switch map[p.row][p.col] {
    case "U":
        dr = -1; dc = 0
    case "D":
        dr = 1; dc = 0
    case "R":
        dr = 0; dc = 1
    case "L":
        dr = 0; dc = -1
    default:
        dr = 0; dc = 0
    }
    
    let adjacent = Pair(p.row + dr, p.col + dc)
    
    guard (0..<N) ~= adjacent.row && (0..<M) ~= adjacent.col else { return }
    
    union(p, adjacent)
    if !visit[adjacent.row][adjacent.col] { DFS(adjacent) }
}

func initParent() {
    for i in 0..<N {
        for j in 0..<M {
            parent[i][j] = Pair(i, j)
        }
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    initParent()
    
    for i in 0..<N { map[i] = readLine()!.map{ $0 } }
    
    for i in 0..<N {
        for j in 0..<M {
            if !visit[i][j] { DFS(Pair(i, j)) }
        }
    }
    
    var set = Set<Pair>()
    
    for i in 0..<N {
        for j in 0..<M {
            set.insert(find(Pair(i, j)))
        }
    }
    
    print(set.count)
}

solution()
