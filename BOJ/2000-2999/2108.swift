import Foundation

struct Nums: CustomStringConvertible {
    let nums: [Int]
    let sortedNums: [Int]
    
    init(nums: [Int]) {
        self.nums = nums
        self.sortedNums = nums.sorted()
    }
    
    var mean: Int {
        var sum = 0
        
        nums.forEach{ sum += $0 }
        
        let mean = round(Double(sum) / Double(nums.count))

        return Int(mean)
    }
    
    var median: Int {
        sortedNums[(nums.count - 1) / 2]
    }
    
    var mode: Int {
        var count = Array(repeating: 0, count: 8001)
        nums.forEach{ count[$0 + 4000] += 1 }
        
        var maxCount = 0
        count.forEach{ maxCount = max(maxCount, $0) }
        
        var mode = -4001
        for i in 0...8000 {
            if count[i] == maxCount {
                if mode == -4001 { mode = i - 4000 }
                else { return i - 4000 }
            }
        }
        
        return mode
    }
    
    var gap: Int {
        return sortedNums.last! - sortedNums.first!
    }
    
    var description: String {
        return "\(mean)\n\(median)\n\(mode)\n\(gap)"
    }
}

let N = Int(readLine()!)!
var arr = Array(repeating: 0, count: N)
for i in 0..<N { arr[i] = Int(readLine()!)! }

print(Nums(nums: arr))
