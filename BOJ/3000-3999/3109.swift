import Foundation

var R = 0, C = 0
var board = Array(repeating: [Character](), count: 10001)

struct Pair {
    let r: Int
    let c: Int
    
    var up: Pair {
        return Pair(r: r-1, c: c+1)
    }
    
    var right: Pair {
        return Pair(r: r, c: c+1)
    }
    
    var down: Pair {
        return Pair(r: r+1, c: c+1)
    }
}

func connect(_ p: Pair) -> Bool {
    board[p.r][p.c] = "x"   // 방문표시, 그리디하게 연결할 것이므로 한번 방문한 곳은 1.이미 연결됐거나 2. 불가능하다고 판정된 곳
    
    if p.c == C-1 { return true }
    
    for next in [p.up, p.right, p.down] {
        guard (0..<R) ~= next.r,
              (0..<C) ~= next.c,
              board[next.r][next.c] == "." else { continue }
        
        if connect(next) { return true }
    }
    
    return false
}

func countConnect() -> Int {
    var count = 0
    
    for r in 0..<R {
        if connect(Pair(r: r, c: 0)) {
            count += 1
        }
    }
    
    return count
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    R = input[0]
    C = input[1]
    
    for i in 0..<R {
        board[i] = readLine()!.map{ $0 }
    }
    
    let result = countConnect()
    print(result)
}

solution()
