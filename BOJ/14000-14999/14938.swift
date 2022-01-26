import Foundation

let INF = 987654321
var n = 0, m = 0, r = 0
var dist = Array(repeating: Array(repeating: INF, count: 101), count: 101)
var items = [Int]()

func floydWarshall() {
    for k in 1...n {
        for i in 1...n {
            for j in 1...n {
                if dist[i][k] + dist[k][j] < dist[i][j] {
                    dist[i][j] = dist[i][k] + dist[k][j]
                }
            }
        }
    }
}

func maxItemCount() -> Int {
    var result = 0
    
    for i in 1...n {
        var count = 0
        
        for j in 1...n {
            if dist[i][j] <= m { count += items[j] }
        }
        
        result = max(result, count)
    }
    
    return result
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    n = input[0]
    m = input[1]
    r = input[2]
    
    items = [0] + readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    for i in 1...n { dist[i][i] = 0 }
    for _ in 0..<r {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let start = input[0]
        let end = input[1]
        let weight = input[2]
        
        dist[start][end] = min(dist[start][end], weight)
        dist[end][start] = min(dist[end][start], weight)
    }
    
    floydWarshall()
    
    print(maxItemCount())
}

solution()
