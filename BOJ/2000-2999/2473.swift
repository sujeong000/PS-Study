import Foundation

func solution() {
    let N = Int(readLine()!)!
    
    var arr = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    arr.sort()
    
    var minVal: Int64 = 3000000001
    var minResult = [Int64]()
    for i in 0..<N-2 {
        var s = i+1
        var e = N-1
        
        while s < e {
            let sum = abs(arr[s] + arr[e] + arr[i])
            if sum < minVal {
                minVal = sum
                minResult = [arr[i], arr[s], arr[e]]
            }
            
            if arr[s] + arr[e] < -arr[i] {
                s += 1
            } else {
                e -= 1
            }
        }
    }
    
    print(minResult.map{ "\($0)" }.joined(separator: " "))
}

solution()
