import Foundation

var adjacents = Array(repeating: [(Int, Int)](), count: 1001)

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

func BFS(start: Int, target: Int) -> Int {
    var queue = Queue()
    var visit = Array(repeating: false, count: 1001)
    var dist = Array(repeating: 0, count: 1001)
    
    dist[start] = 0
    visit[start] = true
    queue.insert(start)
    
    while !queue.isEmpty {
        let n = queue.popFront()
        
        if n == target { return dist[n] }
        
        for adj in adjacents[n] {
            let next = adj.0
            let d = adj.1
            
            guard !visit[next] else { continue }
            
            visit[next] = true
            dist[next] = dist[n] + d
            queue.insert(next)
        }
    }
    
    return 987654321
}

func solution() -> String {
    var result = ""
    
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    for _ in 1..<N {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let s = input[0]
        let e = input[1]
        let d = input[2]
        
        adjacents[s].append((e, d))
        adjacents[e].append((s, d))
    }
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let s = input[0]
        let e = input[1]
        
        result.write("\(BFS(start: s, target: e))\n")
    }
    
    return result
}

print(solution())
