import Foundation

var parents = [Int]()
var rank = Array(repeating: 1, count: 300_001)

func initParents(_ n: Int) {
    parents = (0...n).map{ $0 }
}

func find(_ n: Int) -> Int {
    if parents[n] == n { return n }
    
    parents[n] = find(parents[n])
    
    return parents[n]
}

func union(a: Int, b: Int) {
    var pa = find(a), pb = find(b)
    
    if pa == pb { return }
    
    if rank[pa] < rank[pb] { swap(&pa, &pb) }
    parents[pb] = pa
    rank[pa] += rank[pb]
}

func solution() {
    let N = Int(readLine()!)!
    
    initParents(N)
    
    for _ in 0..<N-2 {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        union(a: A, b: B)
    }
    
    for i in 2...N {
        if find(1) != find(i) {
            print(1, i)
            break
        }
    }
}

solution()
