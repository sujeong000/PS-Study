import Foundation

typealias Pair = (A: Int, B: Int)

var N = 0
var arr = [Pair]()
var lis = [0]
var pos = [Int]()

func lowerBound(x: Int) -> Int {
    var lo = 0, hi = lis.count-1
    
    while lo < hi {
        let mid = (lo + hi) / 2
        
        if lis[mid] < x { lo = mid + 1 }
        else { hi = mid }
    }
    
    return lo
}

func LIS() {
    for i in 0..<N {
        let x = arr[i].B
        
        if lis.last! < x {
            pos[i] = lis.count
            lis.append(x)
        } else {
            let lb = lowerBound(x: x)
            pos[i] = lb
            lis[lb] = x
        }
    }
}

func notBelongToLIS() -> [Int] {
    LIS()
    
    var result = [Int]()
    var index = N - 1
    
    for k in (1..<lis.count).reversed() {
        while index >= 0 && pos[index] != k {
            result.append(arr[index].A)
            index -= 1
        }
        
        index -= 1
    }
    
    while index >= 0 {
        result.append(arr[index].A)
        index -= 1
    }
    
    return result.sorted()
}

func solution() {
    N = Int(readLine()!)!
    
    arr = Array(repeating: (0,0), count: N)
    pos = Array(repeating: 0, count: N)
    
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let A = input[0]
        let B = input[1]
        
        arr[i] = (A, B)
    }
    
    arr.sort(by: { $0.0 < $1.0 })   // A를 기준으로 오름차순 정렬
    
    let result = notBelongToLIS()   // 전깃줄이 교차하지 않으려면 B가 증가 수열이어야 함
    
    var resultString = "\(result.count)\n"
    result.forEach{ resultString.write("\($0)\n") }
    print(resultString)
}

solution()
