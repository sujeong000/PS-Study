import Foundation

var parent = [Int]()
var sz = [Int]()
var edges = [Edge]()

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
    var weight: Int
}

func solution() {
    var input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
    let V = input[0]
    let C = input[1]
    
    for i in 0...V {
        parent.append(i)
        sz.append(1)
    }

    for _ in 0..<C {
        input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
        edges.append(Edge(start: input[0], end: input[1], weight: input[2]))
    }

    edges.sort()

    var cost = 0
    var count = 0
    var i = 0

    while count < V - 1 {
        let edge = edges[i]
        
        if find(edge.start) != find(edge.end) {
            merge(edge.start, edge.end)
            cost += edge.weight
            count += 1
        }
        
        i += 1
    }

    print(cost)
}

solution()
