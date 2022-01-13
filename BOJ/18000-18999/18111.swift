import Foundation

struct Result: Comparable {
    let cost: Int
    let height: Int
    
    static func < (lhs: Result, rhs: Result) -> Bool {
        if lhs.cost == rhs.cost { return lhs.height > rhs.height }
        else { return lhs.cost < rhs.cost }
    }
}

func craft(height: Int) -> Int {
    var cost = 0
    var addedBlocks = 0
    var removedBlocks = 0
    
    for block in blocks {
        if block > height {     // height가 될 때까지 제거
            cost += 2 * (block - height)
            removedBlocks += (block - height)
        } else {                // height가 될 때까지 추가
            cost += (height - block)
            addedBlocks += (height - block)
        }
    }
    
    let isPossible = B + removedBlocks - addedBlocks >= 0   // 주어진 블록 개수를 초과하지 않고 가능한지
    
    return isPossible ? cost : 987654321
}

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]
let B = input[2]
var blocks = [Int]()
var results = [Result]()

for _ in 0..<N {
    blocks += readLine()!.split(separator: " ").map{ Int(String($0))! }
}

for h in 0...256 {
    let result = Result(cost: craft(height: h), height: h)
    results.append(result)
}

results.sort()

print(results[0].cost, results[0].height)
