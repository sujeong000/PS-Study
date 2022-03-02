import Foundation

struct Point {
    let x: Int
    let y: Int
    
    static func -(_ lhs: Point, _ rhs: Point) -> Point {
        return Point(x: rhs.x - lhs.x, y: rhs.y - lhs.y)
    }
}

func CCW(_ p1: Point, _ p2: Point, _ p3: Point) -> Int {
    let v1 = p2 - p1
    let v2 = p3 - p2
    
    let ccw = v1.x * v2.y - v2.x * v1.y
    
    if ccw > 0 { return 1 }
    else if ccw < 0 { return -1 }
    else { return 0 }
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let p1 = Point(x: input[0], y: input[1])
    
    input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let p2 = Point(x: input[0], y: input[1])
    
    input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let p3 = Point(x: input[0], y: input[1])
    
    let result = CCW(p1, p2, p3)
    print(result)
}

solution()
