import Foundation

var parent = [Int]()
var size = [Int]()

func initUnionFind(n: Int) {
    parent = (0..<n).map{ $0 }
    size = Array(repeating: 1, count: n)
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

func isConnected(u: Int, v: Int) -> Int {
    return find(u) == find(v) ? 1 : 0
}

var resultString = ""

let T = Int(readLine()!)!

for t in 1...T {
    let n = Int(readLine()!)!
    let k = Int(readLine()!)!
    
    initUnionFind(n: n)
    
    for _ in 0..<k {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let a = input[0]
        let b = input[1]
        
        union(a: a, b: b)
    }
    
    let m = Int(readLine()!)!
    
    resultString.write("Scenario \(t):\n")
    
    for _ in 0..<m {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let u = input[0]
        let v = input[1]
        
        if find(u) == find(v) {
            resultString.write("1\n")
        } else {
            resultString.write("0\n")
        }
    }
    
    resultString.write("\n")
}

print(resultString)
