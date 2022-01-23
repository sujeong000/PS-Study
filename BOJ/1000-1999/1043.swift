import Foundation

var parties = [[Int]]()
var parent = [Int]()
var size = [Int]()
var N = 0, M = 0

func initUnionFind(n: Int) {
    parent = (0...n).map{ $0 }
    size = Array(repeating: 1, count: n + 1)
}

func find(_ x: Int) -> Int {
    if parent[x] == x { return x }
    
    parent[x] = find(parent[x])
    
    return parent[x]
}

func union(a: Int, b: Int) {
    var pa = find(a), pb = find(b)
    
    guard pa != pb else { return }
    
    if size[pa] < size[pb] { swap(&pa, &pb) }
    parent[pb] = pa
    size[pa] += size[pb]
}

func solution() -> String {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    initUnionFind(n: N)
    
    let whoKnowsTruth = Array(readLine()!.split(separator: " ").map{ Int(String($0))! }.dropFirst())
    
    for _ in 0..<M {
        let participants = Array(readLine()!.split(separator: " ").map{ Int(String($0))! }.dropFirst())
        parties.append(participants)
    }
    
    for party in parties {                      // 같은 파티에 참석하는 사람들끼리는 같은 종류를 들어야함
        for i in 0..<party.count-1 {
            union(a: party[i], b: party[i+1])
        }
    }
    
    var result = 0
    
    if !whoKnowsTruth.isEmpty {
        for i in 0..<whoKnowsTruth.count-1 {    // 진실을 아는 사람을 하나로 묶어줌
            union(a: whoKnowsTruth[i], b: whoKnowsTruth[i+1])
        }
        
        for party in parties {                  // 각 파티의 참석자들이 진실을 알아야하는 집단인지 체크
            if find(party.first!) != find(whoKnowsTruth.first!) {
                result += 1
            }
        }
    } else {
        result = M
    }
    
    return "\(result)"
}

print(solution())
