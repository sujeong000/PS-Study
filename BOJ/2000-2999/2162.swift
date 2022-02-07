import Foundation

var N = 0
var segments = [Segment]()
var parent = (0..<3000).map{ $0 }
var rank = Array(repeating: 1, count: 3000)

struct Point: Comparable {
    let x: Int
    let y: Int
    
    init(_ x: Int, _ y: Int) {
        self.x = x
        self.y = y
    }
    
    static func <(_ lhs: Point, _ rhs: Point) -> Bool {
        if lhs.x == rhs.x { return lhs.y < rhs.y }
        else { return lhs.x < rhs.x }
    }
    
    static func CCW(_ p1: Point, _ p2: Point, _ p3: Point) -> Int {
        let v1 = Point(p2.x-p1.x, p2.y-p1.y)
        let v2 = Point(p3.x-p2.x, p3.y-p2.y)
        
        let result = v1.x * v2.y - v1.y * v2.x
        
        if result > 0 { return 1 }
        else if result < 0 { return -1 }
        else { return 0 }
    }
}

struct Segment {
    var index: Int
    var p1: Point
    var p2: Point
    
    init(x1: Int, y1: Int, x2: Int, y2: Int) {
        self.index = segments.count
        self.p1 = Point(x1, y1)
        self.p2 = Point(x2, y2)
    }
    
    static func checkMeet(_ seg1: Segment, _ seg2: Segment) -> Bool {
        let ccw1 = Point.CCW(seg1.p1, seg1.p2, seg2.p1)
        let ccw2 = Point.CCW(seg1.p1, seg1.p2, seg2.p2)
        let ccw3 = Point.CCW(seg2.p1, seg2.p2, seg1.p1)
        let ccw4 = Point.CCW(seg2.p1, seg2.p2, seg1.p2)
        
        if ccw1*ccw2 > 0 || ccw3*ccw4 > 0 {
            return false
        } else if ccw1*ccw2 == 0 && ccw3*ccw4 == 0 {
            let p1 = seg1.p1 < seg1.p2 ? seg1.p1 : seg1.p2
            let p2 = p1 == seg1.p1 ? seg1.p2 : seg1.p1
            let p3 = seg2.p1 < seg2.p2 ? seg2.p1 : seg2.p2
            let p4 = p3 == seg2.p1 ? seg2.p2 : seg2.p1
            
            return p1 <= p4 && p3 <= p2
        } else {
            return true
        }
    }
}

func find(_ seg: Int) -> Int {
    if seg == parent[seg] { return seg }
    
    parent[seg] = find(parent[seg])
    
    return parent[seg]
}

func union(_ seg1: Int, _ seg2: Int) {
    var p1 = find(seg1), p2 = find(seg2)
    
    if p1 == p2 { return }
    
    if rank[p1] < rank[p2] { swap(&p1, &p2) }
    
    parent[p2] = p1
    rank[p1] += rank[p2]
}

func solution() {
    N = Int(readLine()!)!
    
    for _ in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        segments.append(Segment(x1: input[0], y1: input[1], x2: input[2], y2: input[3]))
    }
    
    for i in 0..<N-1 {
        for j in i+1..<N {
            guard Segment.checkMeet(segments[i], segments[j]) else { continue }
            
            union(i, j)
        }
    }
    
    print(Set((0..<N).map{ find($0) }).count)
    print(rank.max()!)
}

solution()
