import Foundation

let INF: Int64 = 999_999_999_999

struct Edge {
    let start: Int
    let end: Int
    var weight: Int64
}

func canGo(start: Int, end: Int, n: Int, edges: [Edge]) -> Bool {
    var stack = [Int]()
    var visit = Array(repeating: false, count: n)
    
    stack.append(start)
    visit[start] = true
    
    while !stack.isEmpty {
        let current = stack.popLast()!
        for edge in edges {
            if edge.start == current && !visit[edge.end] {
                visit[edge.end] = true
                stack.append(edge.end)
            }
        }
    }
    
    return visit[end]
}

func bellmanFord(n: Int, edges: [Edge], start: Int, initialMoney: Int64, end: Int) -> (hasCycle: Bool, dist: [Int64]) {
    var dist = Array(repeating: INF, count: n)
    
    var hasCycle = false
    dist[start] = -initialMoney
    
    for i in 0..<n {
        for edge in edges {
            if dist[edge.start] != INF && dist[edge.start] + edge.weight < dist[edge.end] {
                dist[edge.end] = dist[edge.start] + edge.weight
                
                // 사이클 내에서 도착도시로 "갈 수 있어야" 도착했을 때 돈이 무한이다.
                if i == n - 1 && canGo(start: edge.end, end: end, n: n, edges: edges) { hasCycle = true }
            }
        }
    }
    
    return (hasCycle, dist)
}

func solution() -> String {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let S = input[1]
    let E = input[2]
    let M = input[3]
    
    var edges = [Edge]()
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let start = input[0]
        let end = input[1]
        let weight = Int64(input[2])
        
        edges.append(Edge(start: start, end: end, weight: weight))
    }
    
    let money = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    for i in 0..<M {
        edges[i].weight -= money[edges[i].end]
    }
    
    let result = bellmanFord(n: N, edges: edges, start: S, initialMoney: money[S], end: E)
    
    if result.dist[E] == INF { return "gg" }
    else if result.hasCycle { return "Gee" }
    else { return "\(-result.dist[E])" }
}

print(solution())
