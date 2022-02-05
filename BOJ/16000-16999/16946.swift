import Foundation

var N = 0, M = 0
var map = Array(repeating: [Int](), count: 1001)
var result = Array(repeating: Array(repeating: 0, count: 1001), count: 1001)
var parent = Array(repeating: Array(repeating: Pair(0,0), count: 1001), count: 1001)
var rank = Array(repeating: Array(repeating: 1, count: 1001), count: 1001)
var visit = Array(repeating: Array(repeating: false, count: 1001), count: 1001)

struct Pair: Hashable {
    let row: Int
    let col: Int
    
    init(_ row: Int, _ col: Int) {
        self.row = row
        self.col = col
    }
    
    var adjacents: [Pair] {
        return [Pair(row+1,col), Pair(row-1,col), Pair(row,col+1), Pair(row,col-1)]
                .filter { (0..<N) ~= $0.row && (0..<M) ~= $0.col }
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
    
    for adj in p.adjacents {
        guard !visit[adj.row][adj.col] && map[adj.row][adj.col] == 0 else { continue }
        
        union(p, adj)
        DFS(adj)
    }
}

func initParent() {
    for i in 0..<N {
        for j in 0..<M {
            parent[i][j] = Pair(i, j)
        }
    }
}

func unionPairs() {
    initParent()
    
    for i in 0..<N {
        for j in 0..<M {
            guard !visit[i][j] && map[i][j] == 0 else { continue }
            DFS(Pair(i, j))
        }
    }
}

func breakTheWall() {
    for i in 0..<N {
        for j in 0..<M {
            guard map[i][j] != 0 else { continue }
            
            var count = 1
            
            let adjacentSet = Set(Pair(i, j).adjacents.map{ find($0) })
            for adjSet in adjacentSet {
                guard map[adjSet.row][adjSet.col] == 0 else { continue }
                
                count += rank[adjSet.row][adjSet.col]
            }
            
            result[i][j] = count % 10
        }
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N { map[i] = readLine()!.map{ Int(String($0))! } }
    
    unionPairs()
    breakTheWall()
    
    var resultString = ""
    
    for i in 0..<N {
        for j in 0..<M {
            resultString.write("\(result[i][j])")
        }
        resultString.write("\n")
    }
    
    print(resultString)
}

solution()
