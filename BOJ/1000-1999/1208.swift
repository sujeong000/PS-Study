import Foundation

var N = 0, S = 0
var leftDict = [Int:Int64]()
var rightDict = [Int:Int64]()
var arr = [Int]()

func findAllCasesFromLeft(index: Int, count: Int, mask: Int64) {
    if index == N / 2 {
        var sum = 0
        
        for i in 0..<N/2 {
            if (1 << i) & mask != 0 {
                sum += arr[i]
            }
        }
        
        if count != 0 {
            if leftDict[sum] == nil {
                leftDict[sum] = 1
            } else {
                leftDict[sum]! += 1
            }
        }
        
        return
    }
    
    findAllCasesFromLeft(index: index+1, count: count, mask: mask)
    findAllCasesFromLeft(index: index+1, count: count+1, mask: mask | (1 << index))
}

func findAllCasesFromRight(index: Int, count: Int, mask: Int64) {
    if index == N {
        var sum = 0
        
        for i in N/2..<N {
            if (1 << i) & mask != 0 {
                sum += arr[i]
            }
        }
        
        if count != 0 {
            if rightDict[sum] == nil {
                rightDict[sum] = 1
            } else {
                rightDict[sum]! += 1
            }
        }
        
        return
    }
    
    findAllCasesFromRight(index: index+1, count: count, mask: mask)
    findAllCasesFromRight(index: index+1, count: count+1, mask: mask | (1 << index))
}

func findAllCases() {
    findAllCasesFromRight(index: N/2, count: 0, mask: 0)
    findAllCasesFromLeft(index: 0, count: 0, mask: 0)
}

func makeS() -> Int64 {
    var count = (rightDict[S] ?? 0) + (leftDict[S] ?? 0)
    
    for (key, value) in leftDict {
        if let rightCases = rightDict[S - key] {
            count += value * rightCases
        }
    }
    
    return count
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    S = input[1]
    
    arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    findAllCases()
    
    print(makeS())
}

solution()
