import Foundation

var h = 0, w = 0
var building = Array(repeating: Array(repeating: Character(" "), count: 101), count: 101)
var keys = [Character:Bool]()
var visit = [[Bool]]()
var count = 0
var queue = Queue()
var gotNewKey = true

typealias Pair = (row: Int, col: Int)
struct Queue {
    var queue = [Pair]()
    var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ p: Pair) {
        queue.append(p)
    }
    
    mutating func popFront() -> Pair {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func BFS() {
    gotNewKey = false
    var nextQueue = Queue()
    
    while !queue.isEmpty {
        let current = queue.popFront()
        let row = current.row
        let col = current.col
        
        let adjacents: [Pair] = [(row+1,col), (row-1,col), (row,col+1), (row,col-1)].filter {
            (0..<h) ~= $0.row && (0..<w) ~= $0.col
        }
        
        for adj in adjacents {
            let adjChar = building[adj.row][adj.col]
            
            guard !visit[adj.row][adj.col] && adjChar != "*" else { continue }
            
            if adjChar == "." {
                visit[adj.row][adj.col] = true
                queue.insert(adj)
            } else if "a" <= adjChar && adjChar <= "z" {
                let door = Character(adjChar.uppercased())
                if keys[door] == nil {
                    keys[door] = true
                    gotNewKey = true
                }
            } else if "A" <= adjChar && adjChar <= "Z" {
                guard let _ = keys[adjChar] else {
                    nextQueue.insert(current)
                    continue
                }
            } else {
                count += 1
            }
            
            visit[adj.row][adj.col] = true
            queue.insert(adj)
        }
    }
    
    queue = nextQueue
}

func goInside() {
    for i in 0..<w {
        queue.insert((row: -1, col: i))
        queue.insert((row: h, col: i))
    }
    
    for i in 0..<h {
        queue.insert((row: i, col: -1))
        queue.insert((row: i, col: w))
    }
}

func initTestcase() {
    visit = Array(repeating: Array(repeating: false, count: w), count: h)
    keys = [Character:Bool]()
    count = 0
    queue = Queue()
    gotNewKey = true
}

func solution() {
    var resultString = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        h = input[0]
        w = input[1]
        
        initTestcase()
        
        for i in 0..<h { building[i] = readLine()!.map{ $0 } }
        readLine()!.forEach{ keys[Character($0.uppercased())] = true }
        
        goInside()
        while gotNewKey { BFS() }
        
        resultString.write("\(count)\n")
        
        T -= 1
    }

    print(resultString)
}

solution()
