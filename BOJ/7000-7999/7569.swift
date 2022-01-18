import Foundation

var M = 0, N = 0, H = 0
var box = Array(repeating: Array(repeating: Array(repeating: -1, count: 102), count: 102), count: 102)

typealias Tomato = (x: Int, y: Int, z: Int, day: Int)   // day = 익은 날짜
typealias Adjacent = (dx: Int, dy: Int, dz: Int)

struct Queue {
    var queue = [Tomato]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ tomato: Tomato) {
        queue.append(tomato)
    }
    
    mutating func popFront() -> Tomato {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS() -> Int {
    var queue = Queue()
    var maxDay = 0
    
    for i in 1...H {
        for j in 1...N {
            for k in 1...M {
                if box[i][j][k] == 1 {      // 처음부터 익어있던 토마토
                    queue.insert((i, j, k, 0))
                }
            }
        }
    }
    
    while !queue.isEmpty {
        let current = queue.popFront()
        
        let adjacents: [Adjacent] = [(1,0,0), (-1,0,0), (0,1,0), (0,-1,0), (0,0,1), (0,0,-1)]
        for adj in adjacents {
            let adjX = current.x + adj.dx
            let adjY = current.y + adj.dy
            let adjZ = current.z + adj.dz
            let adjDay = current.day + 1
            
            if box[adjX][adjY][adjZ] == 0 {     // 인접한 칸에 안익은 토마토가 있는 경우
                box[adjX][adjY][adjZ] = 1       // 영향을 받아 익음
                maxDay = max(maxDay, adjDay)
                queue.insert((adjX, adjY, adjZ, adjDay))
            }
        }
    }
    
    for i in 1...H {
        for j in 1...N {
            for k in 1...M {
                if box[i][j][k] == 0 {          // 익지 못한 토마토가 있는 경우
                    maxDay = -1
                    break
                }
            }
        }
    }
    
    return maxDay
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    M = input[0]
    N = input[1]
    H = input[2]
    
    for i in 1...H {
        for j in 1...N {
            input = readLine()!.split(separator: " ").map{ Int(String($0))! }
            input.enumerated().forEach{ box[i][j][$0+1] = $1 }
        }
    }
    
    print(BFS())
}

solution()
