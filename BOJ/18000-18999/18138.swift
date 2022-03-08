import Foundation

var N = 0, M = 0
var Tshirts = Array(repeating: 0, count: 201)
var collars = Array(repeating: 0, count: 201)
var owner = Array(repeating: -1, count: 201)    // owner[i] = i번째 카라와 매칭된 티셔츠 번호
var visit = Array(repeating: false, count: 201)
var adjacents = Array(repeating: [Int](), count: 201)

func DFS(_ index: Int) -> Bool {
    for adj in adjacents[index] {
        guard !visit[adj] else { continue }
        
        visit[adj] = true
        
        if owner[adj] == -1 || DFS(owner[adj]) {
            owner[adj] = index
            return true
        }
    }
    
    return false
}

func bipartiteMatch() -> Int {
    var count = 0
    
    for i in 0..<N {
        visit = Array(repeating: false, count: 201)
        if DFS(i) { count += 1 }
    }
    
    return count
}

func check(tShirt: Int, collar: Int) -> Bool {
    if (collar * 2 >= tShirt) && (collar * 4 <= tShirt * 3) { return true }
    else if (collar >= tShirt) && (collar * 4 <= tShirt * 5) { return true }
    else { return false }
}

func connectEdge() {
    for i in 0..<N {
        for j in 0..<M {
            if check(tShirt: Tshirts[i], collar: collars[j]) {
                adjacents[i].append(j)
            }
        }
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N { Tshirts[i] = Int(readLine()!)! }
    for i in 0..<M { collars[i] = Int(readLine()!)! }
    
    connectEdge()
    
    let result = bipartiteMatch()
    print(result)
}

solution()
