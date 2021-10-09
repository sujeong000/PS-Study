import Foundation

func solution() {
    let N = Int(readLine()!)!
    
    var points = [[Int64]]()
    
    for i in 0..<N {
        var input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
        points.append([input[0], input[1]])
    }
    
    var result: Int64 = 0
    
    let x = points[0][0]
    let y = points[0][1]
    for i in 1..<N-1 {
        var x1 = points[i][0]
        var y1 = points[i][1]
        var x2 = points[i+1][0]
        var y2 = points[i+1][1]
        
        result += x * y1 + x1 * y2 + x2 * y - x1 * y - x2 * y1 - x * y2
    }
    
    print(String(format: "%.1f", abs(Double(result) / 2.0)))
}

solution()
