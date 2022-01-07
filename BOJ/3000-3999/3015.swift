import Foundation

struct Pair {
    let height: Int
    var count: Int64
    
    mutating func countUp(_ n: Int64) {
        self.count += n
    }
}

var stack = [Pair]()
var result: Int64 = 0

let N = Int(readLine()!)!
for _ in 0..<N {
    var pair = Pair(height: Int(readLine()!)!, count: 1)
    
    while !stack.isEmpty && stack.last!.height <= pair.height {
        result += stack.last!.count     // top과 서로 볼 수 있음 > 카운트 업
        
        if stack.last!.height == pair.height { pair.countUp(stack.last!.count) }    // 키가 같은 사람들을 서로 볼 수 있음 > 카운트 업
        _ = stack.popLast()
    }
    
    if !stack.isEmpty { result += 1 }   // 왼쪽에서 처음으로 등장하는 더 큰 사람과 서로 볼 수 있음 > 카운트 업
    stack.append(pair)
}

print(result)
