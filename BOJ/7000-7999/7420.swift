import Foundation

var N = 0, L = 0
var points = [Point]()

struct Stack {
    var stack = Array(repeating: Point(x: 0, y: 0), count: 1_001)
    var top = -1
    
    var size: Int {
        return top + 1
    }
    
    var isEmpty: Bool {
        return top == -1
    }
    
    var first: Point {
        return stack[top]
    }
    
    var second: Point {
        return stack[top-1]
    }
    
    mutating func push(_ p: Point) {
        top += 1
        stack[top] = p
    }
    
    mutating func pop() {
        top -= 1
    }
}

struct Point: Comparable {
    let x: Int64
    let y: Int64
    
    static func -(_ lhs: Point, _ rhs: Point) -> Point {
        return Point(x: lhs.x - rhs.x, y: lhs.y - rhs.y)
    }
    
    static func <(_ lhs: Point, _ rhs: Point) -> Bool {
        if lhs.x * rhs.y != lhs.y * rhs.x { return lhs.x * rhs.y > lhs.y * rhs.x }
        if lhs.y != rhs.y { return lhs.y < rhs.y }
        return lhs.x < rhs.x
    }
    
    static func dist(_ lhs: Point, _ rhs: Point) -> Double {
        let x = (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y)
        return sqrt(Double(x))
    }
}

func CCW(_ p1: Point, _ p2: Point, _ p3: Point) -> Int {
    let v1 = p2 - p1
    let v2 = p3 - p2
    let op = v1.x * v2.y - v1.y * v2.x
    
    if op > 0 { return 1 }
    else if op < 0 { return -1 }
    else { return 0 }
}

func findStartPoint() -> Point {
    var startPoint = Point(x: 10_001, y: 10_001)
    
    for point in points {
        guard point.y <= startPoint.y else { continue }
        
        if point.y < startPoint.y { startPoint = point }
        else if point.x < startPoint.x { startPoint = point }
    }
    
    return startPoint
}

func sortPoints() {
    let startPoint = findStartPoint()
    for i in 0..<N { points[i] = points[i] - startPoint }
    
    points.sort()
}

func grahamScan() -> Double {
    sortPoints()
    
    var stack = Stack()
    
    stack.push(points[0])
    stack.push(points[1])
    
    for i in 2..<N {
        while stack.size >= 2 {
            let first = stack.first
            let second = stack.second
            
            if CCW(second, first, points[i]) > 0 { break }
            
            stack.pop()
        }
        
        stack.push(points[i])
    }
    
    var dist = Point.dist(stack.first, stack.stack[0])
    for i in 0..<stack.top {
        dist += Point.dist(stack.stack[i], stack.stack[i+1])
    }
    
    dist += Double.pi * 2 * Double(L)
    
    return dist
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    L = input[1]
    points = Array(repeating: Point(x:0, y:0), count: N)
    
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
        let x = input[0]
        let y = input[1]
        points[i] = Point(x: x, y: y)
    }
    
    let result = grahamScan()
    print(Int64(round(result)))
}

solution()
