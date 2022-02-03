import Foundation

var T = 0, n = 0, m = 0
var A = [Int]()
var B = [Int]()
var dictA = [Int:Int]()
var dictB = [Int:Int]()

func considerAllCases() {
    for start in 0..<n {
        var sum = 0
        
        for end in start..<n {
            sum += A[end]
            
            if dictA[sum] == nil {
                dictA[sum] = 1
            } else {
                dictA[sum]! += 1
            }
        }
    }
    
    for start in 0..<m {
        var sum = 0
        
        for end in start..<m {
            sum += B[end]
            
            if dictB[sum] == nil {
                dictB[sum] = 1
            } else {
                dictB[sum]! += 1
            }
        }
    }
}

func makeT() -> Int64 {
    var count: Int64 = 0
    
    for (key, val) in dictA {
        guard let cases = dictB[T - key] else { continue }
        
        count += Int64(val) * Int64(cases)
    }
    
    return count
}

func solution() {
    T = Int(readLine()!)!
    
    n = Int(readLine()!)!
    A = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    m = Int(readLine()!)!
    B = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    considerAllCases()
    print(makeT())
}

solution()
