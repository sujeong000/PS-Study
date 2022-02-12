import Foundation

var N = 0, C = 0
var houses = [Int]()

func decision(d: Int) -> Bool {
    var index = 0
    var target = 0
    var count = 0
    
    while index < N {
        if houses[index] >= target {
            count += 1
            target = houses[index] + d
        }
        index += 1
    }
    
    return count >= C
}

func optimize() -> Int {
    houses.sort()
    
    var lo = 0, hi = 1_000_000_001
    
    for _ in 0..<100 {
        let mid = (lo + hi) / 2
        if decision(d: mid) { lo = mid }
        else { hi = mid }
    }
    
    return lo
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    C = input[1]
    
    houses = Array(repeating: 0, count: N)
    for i in 0..<N { houses[i] = Int(readLine()!)! }
    
    let result = optimize()
    print(result)
}

solution()
