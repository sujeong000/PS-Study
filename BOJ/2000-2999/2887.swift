import Foundation

var parent = [Int]()
var sz = [Int]()
var edges = [Edge]()
var pointsX = [PointX]()
var pointsY = [PointY]()
var pointsZ = [PointZ]()

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

protocol Point {
    var index: Int { get }
    var x: Int { get }
    var y: Int { get }
    var z: Int { get }
}

struct PointX: Comparable, Point {
    static func < (lhs: PointX, rhs: PointX) -> Bool {
        return lhs.x < rhs.x
    }
    
    var index: Int
    var x: Int
    var y: Int
    var z: Int
}

struct PointY: Comparable, Point {
    static func < (lhs: PointY, rhs: PointY) -> Bool {
        return lhs.y < rhs.y
    }
    
    var index: Int
    var x: Int
    var y: Int
    var z: Int
}

struct PointZ: Comparable, Point {
    static func < (lhs: PointZ, rhs: PointZ) -> Bool {
        return lhs.z < rhs.z
    }
    
    var index: Int
    var x: Int
    var y: Int
    var z: Int
}

func calcWeight(p1: Point, p2: Point) -> Int {
    let dx = abs(p1.x - p2.x)
    let dy = abs(p1.y - p2.y)
    let dz = abs(p1.z - p2.z)
    return min(dx, dy, dz)
}

func solution() {
    let input = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
    let V = input[0]
    
    for i in 0..<V {
        parent.append(i)
        sz.append(1)
    }
    
    for i in 0..<V {
        let inputs = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
        pointsX.append(PointX(index: i, x: inputs[0], y: inputs[1], z: inputs[2]))
        pointsY.append(PointY(index: i, x: inputs[0], y: inputs[1], z: inputs[2]))
        pointsZ.append(PointZ(index: i, x: inputs[0], y: inputs[1], z: inputs[2]))
    }
    
    pointsX.sort()
    pointsY.sort()
    pointsZ.sort()

    for i in 0..<V-1 {
        edges.append(Edge(start: pointsX[i].index, end: pointsX[i+1].index, weight: calcWeight(p1: pointsX[i], p2: pointsX[i+1])))
    }
    for i in 0..<V-1 {
        edges.append(Edge(start: pointsY[i].index, end: pointsY[i+1].index, weight: calcWeight(p1: pointsY[i], p2: pointsY[i+1])))
    }
    for i in 0..<V-1 {
        edges.append(Edge(start: pointsZ[i].index, end: pointsZ[i+1].index, weight: calcWeight(p1: pointsZ[i], p2: pointsZ[i+1])))
    }
    
    edges.sort()

    var cost: Int64 = 0
    var count = 0
    var i = 0

    while count < V - 1 {
        let edge = edges[i]
        
        if find(edge.start) != find(edge.end) {
            merge(edge.start, edge.end)
            cost += Int64(edge.weight)
            count += 1
        }
        
        i += 1
    }

    print(cost)
}

solution()
