import Foundation

var N = 0
var points = [Point]()
var startPoint = Point(x: 1_000_000_001, y: 1_000_000_001)

func CCW(_ p1: Point, _ p2: Point) -> Int64 {
    return p1.p * p2.q - p1.q * p2.p
}

struct Point: Comparable {
    let x: Int64
    let y: Int64
    var p: Int64 = 0
    var q: Int64 = 0
    
    static func <(_ lhs: Point, _ rhs: Point) -> Bool {
        let ccw = CCW(lhs, rhs)
        if ccw != 0 { return ccw > 0 }
        if lhs.x != rhs.x { return lhs.x < rhs.x }
        else { return lhs.y < rhs.y }
    }
}

func findStartPoint() -> Point {
    for point in points {
        guard point.x <= startPoint.x else { continue }
        
        if point.x < startPoint.x { startPoint = point }
        else if point.y < startPoint.y { startPoint = point }
    }
    
    return startPoint
}

func sortPoints() -> Int {
    let startPoint = findStartPoint()
    
    for i in 0..<points.count {
        points[i].p = points[i].x - startPoint.x
        points[i].q = points[i].y - startPoint.y
    }
    
    points.sort()
    
    let lastPoint = points.last!
    var reversePoint = points.count - 1
    
    while CCW(points[reversePoint], lastPoint) == 0 {
        reversePoint -= 1   // 마지막 선분의 점들을 거리가 먼 순으로 방문해야 함
    }
    
    return reversePoint
}

func solution() {
    N = Int(readLine()!)!
    
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ")
        
        guard input.last! == "Y" else { continue }
        
        let x = Int64(String(input[0]))!
        let y = Int64(String(input[1]))!
        points.append(Point(x: x, y: y))
    }
    
    let reversePoint = sortPoints()
    
    var resultString = "\(points.count)\n"
    
    for i in 0...reversePoint {
        resultString.write("\(points[i].x) \(points[i].y)\n")
    }
    for i in (reversePoint+1..<points.count).reversed() {
        resultString.write("\(points[i].x) \(points[i].y)\n")
    }
    
    print(resultString)
}

solution()
