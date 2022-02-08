import Foundation

var N = 0
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
    var p: Int64 = 0
    var q: Int64 = 0
    
    static func -(_ lhs: Point, _ rhs: Point) -> Point {
        return Point(x: lhs.x - rhs.x, y: lhs.y - rhs.y)
    }
    
    static func <(_ lhs: Point, _ rhs: Point) -> Bool {
        if lhs.p * rhs.q != lhs.q * rhs.p { return lhs.p * rhs.q > lhs.q * rhs.p }
        if lhs.y != rhs.y { return lhs.y > rhs.y }
        return lhs.x < rhs.x
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
    var startPoint = Point(x: 21, y: -21)
    
    for point in points {
        guard point.y >= startPoint.y else { continue }
        
        if point.y > startPoint.y { startPoint = point }
        else if point.x < startPoint.x { startPoint = point }
    }
    
    return startPoint
}

func sortPoints() {
    let startPoint = findStartPoint()
    for i in 0..<N {
        points[i].p = points[i].x - startPoint.x
        points[i].q = points[i].y - startPoint.y
    }
    
    points.sort()
}

func grahamScan() -> Stack {
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
    
    return stack
}

func solution() {
    var resultString = ""
    var P = Int(readLine()!)!
    
    while P > 0 {
        N = Int(readLine()!)!
        points = Array(repeating: Point(x:0, y:0), count: N)
        
        for i in 0..<N/5 + (N%5 != 0 ? 1 : 0) {
            let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
            
            for j in 0..<input.count/2 {
                let x = input[j*2]
                let y = input[j*2+1]
                points[i*5+j] = Point(x: x, y: y)
            }
        }
        
        let result = grahamScan()
        
        resultString.write("\(result.size)\n")
        resultString.write("\(result.stack[0].x) \(result.stack[0].y)\n")
        for i in (1..<result.size).reversed() {
            resultString.write("\(result.stack[i].x) \(result.stack[i].y)\n")
        }
        
        P -= 1
    }
    
    print(resultString)
}

solution()
