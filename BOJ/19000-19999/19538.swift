import Foundation

var N = 0, M = 0
var adjacents = Array(repeating: [Int](), count: 200_001)
var visit = Array(repeating: false, count: 200_001)
var adjCount = Array(repeating: 0, count: 200_001)
var date = Array(repeating: -1, count: 200_001)
var startPoints = [Int]()

struct Queue {
    var queue = [Int]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ n: Int) {
        queue.append(n)
    }
    
    mutating func popFront() -> Int {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS() {
    var queue = Queue()
    
    for s in startPoints {
        visit[s] = true
        queue.insert(s)
        date[s] = 0
    }

    while !queue.isEmpty {
        let current = queue.popFront()
        
        for adj in adjacents[current] {
            guard !visit[adj] else { continue }
            
            adjCount[adj] += 1
            
            if adjCount[adj] * 2 >= adjacents[adj].count {
                visit[adj] = true
                date[adj] = date[current] + 1
                queue.insert(adj)
            }
        }
    }
}

func solution() {
    N = Int(readLine()!)!
    for i in 1...N {
        adjacents[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }.dropLast()
    }
    
    M = Int(readLine()!)!
    startPoints = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    BFS()
    
    var resultString = ""
    for i in 1...N {
        resultString.write("\(date[i]) ")
    }
    print(resultString)
}

solution()
