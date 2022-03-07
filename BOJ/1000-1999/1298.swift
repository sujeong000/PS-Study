import Foundation

var N = 0, M = 0
var adjacents = Array(repeating: [Int](), count: 101)
var owner = Array(repeating: 0, count: 101)
var visit = Array(repeating: false, count: 101)

func DFS(_ person: Int) -> Bool {
    for adj in adjacents[person] {
        guard !visit[adj] else { continue }
        
        visit[adj] = true
        
        if owner[adj] == 0 || DFS(owner[adj]) {
            owner[adj] = person
            return true
        }
    }
    
    return false
}

func bipartiteMatch() -> Int {
    var matchCount = 0
    
    for i in 1...N {
        visit = Array(repeating: false, count: 101)
        if DFS(i) { matchCount += 1 }
    }
    
    return matchCount
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        adjacents[A].append(B)
    }
    
    print(bipartiteMatch())
}

solution()
