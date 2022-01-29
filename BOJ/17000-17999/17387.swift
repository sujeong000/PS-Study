import Foundation

struct Point: Comparable, Equatable {
    let x: Int64
    let y: Int64
    
    static func < (lhs: Point, rhs: Point) -> Bool {
        if lhs.x == rhs.x { return lhs.y < rhs.y }
        else { return lhs.x < rhs.x }
    }
    
    static func CCW(_ p1: Point, _ p2: Point, _ p3: Point) -> Int64 {
        let v1 = Point(x: p2.x - p1.x, y: p2.y - p1.y)
        let v2 = Point(x: p3.x - p2.x, y: p3.y - p2.y)
        
        let result = v1.x * v2.y - v1.y * v2.x
        
        if result > 0 { return 1 }
        else if result == 0 { return 0 }
        else { return -1 }
    }
}

func solution() {
    let L1 = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    let L2 = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    
    var p1 = Point(x: L1[0], y: L1[1])
    var p2 = Point(x: L1[2], y: L1[3])
    var p3 = Point(x: L2[0], y: L2[1])
    var p4 = Point(x: L2[2], y: L2[3])
    
    let ccw1 = Point.CCW(p1, p2, p3)
    let ccw2 = Point.CCW(p1, p2, p4)
    let ccw3 = Point.CCW(p3, p4, p1)
    let ccw4 = Point.CCW(p3, p4, p2)
    
    let result1 = ccw1 * ccw2
    let result2 = ccw3 * ccw4
    
    if result1 > 0 || result2 > 0 {             // 확실히 교차하지 않음
        print(0)
    } else if result1 == 0 && result2 == 0 {    // 두 선분이 같은 직선 위에 있는 경우
        if p1 > p2 { swap(&p1, &p2) }
        if p3 > p4 { swap(&p3, &p4) }
        
        if p1 <= p4 && p3 <= p2 { print(1) }
        else { print(0) }
    } else {                                    // 확실히 교차함
        print(1)
    }
}

solution()
