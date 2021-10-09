import Foundation

var parent = [Int]()
var sz = [Int]()
var edges1 = [Edge]()
var edges2 = [Edge]()

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

struct Node {
    var visit = false
    var adjacent = [Int: Edge]()
}

var nodes = [Node]()
var farNode = 0
var maxDist = 0

func solution() {
    let input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
    let N = input[0]
    let K = input[1]
    
    for i in 0..<N {
        parent.append(i)
        sz.append(1)
        nodes.append(Node())
    }
    
    for _ in 0..<K {
        let inputs = readLine()!.split(separator: " ").map{ Int(String($0))! }
        edges1.append(Edge(start: inputs[0], end: inputs[1], weight: inputs[2]))
    }
    
    edges1.sort()
    
    var cost: Int64 = 0
    var count = 0
    var i = 0

    while count < N - 1 {
        let edge = edges1[i]
        
        if find(edge.start) != find(edge.end) {
            merge(edge.start, edge.end)
            cost += Int64(edge.weight)
            count += 1
            nodes[edge.start].adjacent[edge.end] = edge
            nodes[edge.end].adjacent[edge.start] = edge
        }
        
        i += 1
    }
    
    print(cost)
    
    // 트리의 지름
    dfs(index: 0, dist: 0)
    maxDist = 0
    for i in 0..<N {
        nodes[i].visit = false
    }
    dfs(index: farNode, dist: 0)
    print(maxDist)
}

func dfs(index: Int, dist: Int) {
    nodes[index].visit = true
    
    if dist > maxDist {
        farNode = index
        maxDist = dist
    }
    
    for (next, edge) in nodes[index].adjacent {
        if !nodes[next].visit {
            dfs(index: next, dist: dist + edge.weight)
        }
    }
}

solution()
