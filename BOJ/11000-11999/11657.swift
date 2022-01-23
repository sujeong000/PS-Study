import Foundation

let INF = 987654321

struct Edge {
    let start: Int
    let end: Int
    let weight: Int
}

func bellmanFord(n: Int, edges: [Edge]) -> (hasCycle: Bool, dist: [Int]) {
    var dist = Array(repeating: INF, count: n + 1)
    
    var hasCycle = false
    dist[1] = 0
    
    for i in 0..<n {
        for edge in edges {
            if dist[edge.start] != INF && dist[edge.start] + edge.weight < dist[edge.end] {
                dist[edge.end] = dist[edge.start] + edge.weight
                if i == n - 1 { hasCycle = true }
            }
        }
    }
    
    return (hasCycle, dist)
}

func solution() -> String {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    var edges = [Edge]()
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let start = input[0]
        let end = input[1]
        let weight = input[2]
        
        edges.append(Edge(start: start, end: end, weight: weight))
    }
    
    let result = bellmanFord(n: N, edges: edges)
    
    guard !result.hasCycle else { return "-1" }
    
    var resultString = ""
    
    for i in 2...N {
        resultString.write("\(result.dist[i] == INF ? -1 : result.dist[i])\n")
    }
    
    return resultString
}

print(solution())
