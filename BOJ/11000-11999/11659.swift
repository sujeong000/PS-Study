import Foundation

func solution() -> String {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    let arr = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    var psum = Array(repeating: arr[0], count: N)
    
    for i in 1..<N {
        psum[i] = psum[i-1] + arr[i]
    }
    
    var result = ""
    
    for _ in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let lo = input[0] - 1
        let hi = input[1] - 1
        
        let sumFromLoToHi = psum[hi] - (lo == 0 ? 0 : psum[lo - 1])
        result.write("\(sumFromLoToHi)\n")
    }
    
    return result
}

print(solution())
