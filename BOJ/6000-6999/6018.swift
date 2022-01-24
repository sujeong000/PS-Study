import Foundation

var parents = [Int]()
var rank = Array(repeating: 1, count: 1001)

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
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    let Q = input[2]
    
    initParents(N)
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        union(a: A, b: B)
    }
    
    var resultString = ""
    
    for _ in 0..<Q {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        let canMeet = find(A) == find(B)
        if canMeet { resultString.write("Y\n") }
        else { resultString.write("N\n") }
    }
    
    print(resultString)
}

solution()
