import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let K = input[1]

var queue = [(Int, Int)]()
var front = 0
var visit = Array(repeating: false, count: 100001)

queue.append((N, 0))    // N에서 시작
visit[N] = true

while true {    // BFS
    let x = queue[front].0
    let dist = queue[front].1
    
    front += 1  // pop
    
    if x == K {
        print(dist)
        break
    }
    
    let adjacents = [x * 2, x - 1, x + 1]   // 좌, 우, 2배 지점
    for adj in adjacents {
        if 0 <= adj && adj <= 100000 && !visit[adj] {
            visit[adj] = true
            queue.append((adj, dist + 1))
        }
    }
}
