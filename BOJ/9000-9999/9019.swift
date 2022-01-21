import Foundation

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

func toCommand(_ n: Int64) -> String {
    var ret = ""
    var x = n
    
    let dict = ["", "D", "S", "L", "R"]
    
    while x > 0 {
        ret += dict[Int(x % 10)]
        x /= 10
    }
    
    return String(ret.reversed())
}

func BFS(start: Int, target: Int) -> String {
    var queue = Queue()
    var visit = Array(repeating: false, count: 10000)
    var path = Array(repeating: Int64(0), count: 10000)
    
    queue.insert(start)
    visit[start] = true
    
    while !queue.isEmpty {
        let n = queue.popFront()
        
        if n == target { return toCommand(path[n]) }
        
        let D = 2 * n % 10000
        let S = n == 0 ? 9999 : n - 1
        let L = n % 1000 * 10 + n / 1000
        let R = n / 10 + n % 10 * 1000
        
        let adjacents = [(D, 1), (S, 2), (L, 3), (R, 4)]
        for adj in adjacents {
            let next = adj.0
            let cmd = adj.1
            
            if !visit[next] {
                visit[next] = true
                path[next] = path[n] * 10 + Int64(cmd)
                queue.insert(next)
            }
        }
    }
    
    return "-1"
}

func solution() -> String {
    var result = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        result.write(BFS(start: A, target: B) + "\n")
        
        T -= 1
    }
    
    return result
}

print(solution())
