import Foundation

var N = 0, L = 0
var board = Array(repeating: [Int](), count: 100)
var parent = [Int]()
var rank = [Int]()

func find(_ x: Int) -> Int {
    if parent[x] == x { return x }
    
    parent[x] = find(parent[x])
    return parent[x]
}

func union(_ a: Int, _ b: Int) {
    var pa = find(a), pb = find(b)
    
    if pa == pb { return }
    
    if rank[pa] < rank[pb] { swap(&pa, &pb) }
    
    parent[pb] = pa
    rank[pa] += rank[pb]
}

func check(road: [Int]) -> Bool {
    parent = (0..<N).map{ $0 }
    rank = Array(repeating: 1, count: N)
    
    for i in 0..<N-1 {
        if road[i] == road[i+1] {
            union(i, i+1)
        }
    }
    
    for i in 0..<N-1 {
        guard find(i) != find(i+1) else { continue }
        
        guard abs(road[i] - road[i+1]) == 1 else { return false }
        
        if road[i] > road[i+1] {
            if rank[find(i+1)] >= L {
                rank[find(i+1)] -= L
            } else {
                return false
            }
        } else {
            if rank[find(i)] >= L {
                rank[find(i)] -= L
            } else {
                return false
            }
        }
    }
    
    return true
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    L = input[1]
    
    for i in 0..<N {
        board[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
    }
    
    var count = 0
    for i in 0..<N {
        let row = board[i]
        let col = (0..<N).map{ board[$0][i] }
        
        let checkRow = check(road: row)
        let checkCol = check(road: col)
        
        if checkRow { count += 1 }
        if checkCol { count += 1 }
    }
    print(count)
}

solution()
