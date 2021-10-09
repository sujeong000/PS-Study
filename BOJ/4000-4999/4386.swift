import Foundation

var parent = [Int]()
var sz = [Int]()
var edges = [Edge]()
var stars = [[Double]]()

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
    var weight: Double
}

func solution() {
    var input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
    let V = input[0]
    
    for i in 0..<V {
        parent.append(i)
        sz.append(1)
    }
    
    for _ in 0..<V {
        var inputs = readLine()!.components(separatedBy: " ").map{ Double(String($0))! }
        stars.append([inputs[0], inputs[1]])
    }

    for i in 1..<V {
        for j in 0..<i {
            let dx = stars[i][0] - stars[j][0]
            let dy = stars[i][1] - stars[j][1]
            let weight = dx * dx + dy * dy
            edges.append(Edge(start: i, end: j, weight: sqrt(weight)))
        }
    }
    
    edges.sort()

    var cost: Double = 0
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

    print(String(format: "%.2f", cost))
}

solution()
