import Foundation

func solution() {
    let N = Int(readLine()!)!
    let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    var LIS = Array(repeating: 1, count: N)
    var reverseLIS = Array(repeating: 1, count: N)
    
    for i in 0..<N {
        for j in 0..<i {
            if arr[j] < arr[i] {
                LIS[i] = max(LIS[i], LIS[j] + 1)
            }
            if arr[N-1-j] < arr[N-1-i] {
                reverseLIS[N-1-i] = max(reverseLIS[N-1-i], reverseLIS[N-1-j] + 1)
            }
        }
    }
    
    var result = 0
    
    for i in 0..<N {
        result = max(result, LIS[i] + reverseLIS[i] - 1)
    }
    
    print(result)
}

solution()
