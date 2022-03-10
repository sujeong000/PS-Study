import Foundation

let MAX_V = 20_000, MAX_N = 100, INF = 987654321
let dr = [1, -1, 0, 0]
let dc = [0, 0, 1, -1]

var N = 0, M = 0, SRC = 0, SINK = 0
var arr = Array(repeating: [Character](), count: MAX_N)
var edges = Array(repeating: [Int:Edge](), count: MAX_V)
var parent = [Int]()

struct Edge {
    var capacity: Int
    var flow: Int
    
    var remainCapacity: Int {
        return capacity - flow
    }
}

func DFS(_ here: Int) {
    if parent[SINK] != -1 { return }
    
    for there in edges[here].keys {
        if edges[here][there]!.remainCapacity > 0 && parent[there] == -1 {
            parent[there] = here
            DFS(there)
        }
    }
}

func FordFulkerson() -> Int {
    var totalFlow = 0
    
    while true {
        parent = Array(repeating: -1, count: MAX_V)
        parent[SRC] = SRC
        
        DFS(SRC)
        
        if parent[SINK] == -1 { break }
        
        var p = SINK
        while p != SRC {
            edges[parent[p]][p]!.flow += 1
            edges[p][parent[p]]!.flow -= 1
            p = parent[p]
        }
        
        totalFlow += 1
    }
    
    return totalFlow
}

func addEdge(s: Int, e: Int, cap: Int) {
    edges[s][e] = Edge(capacity: cap, flow: 0)
    edges[e][s] = Edge(capacity: 0, flow: 0)
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for r in 0..<N {
        arr[r] = readLine()!.map{ $0 }
    }
    
    for r in 0..<N {
        for c in 0..<M {
            guard arr[r][c] != "#" else { continue }
            
            let curr = r * M + c
            
            if arr[r][c] == "K" {
                SRC = curr + 10_000
            } else if arr[r][c] == "H" {
                SINK = curr
            }
            
            addEdge(s: curr, e: curr+10_000, cap: 1)    // 정점 분할: In -> Out
            for i in 0..<4 {
                let adjr = r + dr[i]
                let adjc = c + dc[i]
                
                guard (0..<N) ~= adjr,
                      (0..<M) ~= adjc,
                      arr[adjr][adjc] != "#" else { continue }
                
                let adj = adjr * M + adjc
                addEdge(s: curr+10_000, e: adj, cap: INF)
            }
        }
    }
    
    let result: Int
    
    if let _ = edges[SRC][SINK] {
        result = -1                 // K와 H가 직접 연결 되어있으면 절대 막을 수 없다
    } else {
        result = FordFulkerson()    // 최소 컷은 최대 유량과 같다
    }
    
    print(result)
}

solution()
