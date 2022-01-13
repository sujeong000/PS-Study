import Foundation

func possible(length: Int64) -> Bool {
    var count: Int64 = 0
    
    for cable in cables {
        count += cable / length
    }
    
    return count >= N
}

func optimize() -> Int64 {
    var lo = Int64(1), hi = Int64(cables.last! + 1)
    
    for _ in 0...100 {
        let mid = (lo + hi) / 2
        if possible(length: mid) { lo = mid }
        else { hi = mid }
    }
    
    return lo
}

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let K = input[0]
let N = input[1]

var cables = [Int64]()
for _ in 0..<K { cables.append(Int64(readLine()!)!) }
cables.sort()

print(optimize())
