import Foundation

var R = 0, C = 0, M = 0
var sharks = [Shark]()

enum Direction: Int {
    case up = 1, down, right, left
}

class Shark: CustomStringConvertible {
    var r: Int
    var c: Int
    let s: Int
    var d: Direction
    let z: Int
    var dead: Bool = false
    
    var pos: Int {
        return C * r + c
    }
    
    init(r: Int, c: Int, s: Int, d: Int, z: Int) {
        self.r = r
        self.c = c
        self.s = s
        self.d = Direction(rawValue: d)!
        self.z = z
    }
    
    func move() {
        var dist: Int
        
        switch d {
        case .up, .down:
            dist = s % (2 * (R - 1))
        case .right, .left:
            dist = s % (2 * (C - 1))
        }
        
        while dist > 0 {
            switch d {
            case .up:
                let goStraight = min(r, dist)
                r -= goStraight
                dist -= goStraight
                
                if r == 0 {
                    d = .down
                    r = 2
                }
            case .down:
                let goStraight = min(R+1-r, dist)
                r += goStraight
                dist -= goStraight
                
                if r == R + 1 {
                    d = .up
                    r = R - 1
                }
            case .right:
                let goStraight = min(C+1-c, dist)
                c += goStraight
                dist -= goStraight
                
                if c == C + 1 {
                    d = .left
                    c = C - 1
                }
            case .left:
                let goStaright = min(c, dist)
                c -= goStaright
                dist -= goStaright
                
                if c == 0 {
                    d = .right
                    c = 2
                }
            }
        }
    }
    
    var description: String {
        return ("(\(r), \(c)), \(dead ? "Dead": "Live")")
    }
}

func catchShark(col: Int) -> Int {
    var target: Shark?
    
    for shark in sharks {
        guard !shark.dead && shark.c == col else { continue }
        
        if target == nil {
            target = shark
        } else {
            if target!.r > shark.r { target = shark }
        }
    }
    
    target?.dead = true
    
    return target?.z ?? 0
}

func moveAllSharks() {
    var dict = [Int:Shark]()
    
    for shark in sharks {
        guard !shark.dead else { continue }
        
        shark.move()
        
        if let existingShark = dict[shark.pos] {    // 해당 자리에 다른 상어가 있으면
            if existingShark.z < shark.z {
                dict[shark.pos] = shark
                existingShark.dead = true           // 작은 상어는 잡아 먹힘
            } else {
                shark.dead = true
            }
        } else {
            dict[shark.pos] = shark
        }
    }
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    R = input[0]
    C = input[1]
    M = input[2]
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let r = input[0]
        let c = input[1]
        let s = input[2]
        let d = input[3]
        let z = input[4]
        
        let shark = Shark(r: r, c: c, s: s, d: d, z: z)
        sharks.append(shark)
    }
    
    var sum = 0
    
    for col in 1...C {
        sum += catchShark(col: col)
        moveAllSharks()
    }
    
    print(sum)
}

solution()
