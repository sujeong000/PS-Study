import Foundation

typealias Pair = (A: Int, B: Int)

var N = 0
var arr = [Pair]()
var lis = [0]

func lowerBound(x: Int) -> Int {
    var lo = 0, hi = lis.count-1
    
    while lo < hi {
        let mid = (lo + hi) / 2
        
        if lis[mid] < x { lo = mid + 1 }
        else { hi = mid }
    }
    
    return lo
}

func LIS() -> Int {
    for i in 0..<N {
        let x = arr[i].B
        
        if lis.last! < x {
            lis.append(x)
        } else {
            let lb = lowerBound(x: x)
            lis[lb] = x
        }
    }
    
    return lis.count - 1
}

func solution() {
    N = Int(readLine()!)!
    
    arr = Array(repeating: (0,0), count: N)
    
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        arr[i] = (A, B)
    }
    
    arr.sort(by: { $0.0 < $1.0 })   // A를 기준으로 오름차순 정렬
    
    let result = N - LIS()
    print(result)
}

solution()
