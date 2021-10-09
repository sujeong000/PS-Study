import Foundation

var parent = [Int]()
var sz = [Int]()
var edges = [Edge]()
var gods = [[0, 0]]

func find(_ x: Int) -> Int {
    if parent[x] == x {
        return x
    } else {
        parent[x] = find(parent[x])
        return parent[x]
    }
}

func merge(_ x: Int, _ y: Int) {
    var x = find(x)
    var y = find(y)
    if sz[x] < sz[y] { swap(&x, &y) }
    parent[y] = x
    sz[x] += sz[y]
}

struct Edge: Comparable {
    static func < (lhs: Edge, rhs: Edge) -> Bool {
        return lhs.weight < rhs.weight
    }
    
    var start: Int
    var end: Int
    var weight: Int64
}

func solution() {
    var input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
    let V = input[0]
    let M = input[1]
    
    for i in 0...V {
        parent.append(i)
        sz.append(1)
    }
    
    for _ in 1...V {
        input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
        gods.append([input[0], input[1]])
    }

    for i in 2...V {
        for j in 1..<i {
            let weight = Int64(gods[i][0] - gods[j][0]) * Int64(gods[i][0] - gods[j][0])
                        + Int64(gods[i][1] - gods[j][1]) * Int64(gods[i][1] - gods[j][1])
            edges.append(Edge(start: i, end: j, weight: weight))
        }
    }
    
    edges.sort()

    var cost: Double = 0
    var count = 0
    var i = 0
    
    for _ in 0..<M {
        input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
        if find(input[0]) != find(input[1]) {
            count += 1
            merge(input[0], input[1])
        }
    }

    while count < V - 1 {
        let edge = edges[i]
        
        if find(edge.start) != find(edge.end) {
            merge(edge.start, edge.end)
            cost += sqrt(Double(edge.weight))
            count += 1
        }
        
        i += 1
    }

    print(String(format: "%.2f", cost))
}

solution()
