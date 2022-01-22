import Foundation

let INF = 987654321
var N = 0, M = 0, W = 0
var edges = [Edge]()

struct Edge {
    let start: Int
    let end: Int
    let time: Int
}

func bellmanFord() -> Bool {
    var dist = Array(repeating: INF, count: N+1)
    dist[1] = 0
    
    for i in 0..<N {
        for edge in edges {
            if dist[edge.start] + edge.time < dist[edge.end] {
                dist[edge.end] = dist[edge.start] + edge.time
                if i == N - 1 { return true }   // 음의 가중치 사이클 존재
            }
        }
    }
    
    return false
}

func initTestcase() {
    edges = [Edge]()
}

func solution() -> String {
    var result = ""
    
    var T = Int(readLine()!)!
    while T > 0 {
        initTestcase()
        
        var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        N = input[0]
        M = input[1]
        W = input[2]
        
        for _ in 0..<M {
            input = readLine()!.split(separator: " ").map{ Int(String($0))! }
            let S = input[0]
            let E = input[1]
            let T = input[2]
            
            edges.append(Edge(start: S, end: E, time: T))
            edges.append(Edge(start: E, end: S, time: T))
        }
        
        for _ in 0..<W {
            input = readLine()!.split(separator: " ").map{ Int(String($0))! }
            let S = input[0]
            let E = input[1]
            let T = input[2]
            
            edges.append(Edge(start: S, end: E, time: -T))
        }
        
        result.write("\(bellmanFord() ? "YES\n" : "NO\n")")
        
        T -= 1
    }
    
    return result
}

print(solution())
