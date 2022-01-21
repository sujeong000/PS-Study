import Foundation

var ladder = Array(repeating: 0, count: 101)
var snake = Array(repeating: 0, count: 101)

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
    var depth = Array(repeating: 987654321, count: 101)
    
    depth[start] = 0
    queue.insert(start)
    
    while !queue.isEmpty {
        let n = queue.popFront()
        
        (1...6).forEach{
            guard n + $0 <= 100 else { return }
            
            var next = n + $0
            
            if snake[next] != 0 { next = snake[next] }
            if ladder[next] != 0 { next = ladder[next] }
            
            if depth[n] + 1 < depth[next] {
                depth[next] = depth[n] + 1
                queue.insert(next)
            }
        }
    }
    
    return depth[target]
}

func solution() -> String {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    for _ in 0..<N {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let x = input[0]
        let y = input[1]
        
        ladder[x] = y
    }
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let u = input[0]
        let v = input[1]
        
        snake[u] = v
    }
    
    return "\(BFS(start: 1, target: 100))"
}

print(solution())
