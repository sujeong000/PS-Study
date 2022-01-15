import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let K = input[1]

var queue = [(Int, Int)]()
var front = 0
var minDist = Array(repeating: 987654321, count: 100001)    // N에서 i번 정점까지 최단거리

queue.append((N, 0))    // N에서 시작
minDist[N] = 0

var caseCount = 0

while true {    // BFS
    if front == queue.count { break }   // 큐가 비었으면 종료
    
    let x = queue[front].0
    let dist = queue[front].1
    
    if dist > minDist[K] { break }      // minDist[K]보다 멀리는 갈 필요 없음
    
    front += 1  // pop
    
    if x == K {
        minDist[K] = dist
        caseCount += 1
    }
    
    let adjacents = [x * 2, x - 1, x + 1]   // 좌, 우, 2배 지점
    for adj in adjacents {
        if 0 <= adj && adj <= 100000 && (dist + 1) <= minDist[adj] {  // minDist랑 같을 때도 경우의 수 카운트를 위해 삽입
            minDist[adj] = dist + 1
            queue.append((adj, dist + 1))
        }
    }
}

print(minDist[K])
print(caseCount)
