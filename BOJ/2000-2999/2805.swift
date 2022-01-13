import Foundation

func lowerBound(n: Int) -> Int {
    var lo = 0, hi = N - 1
    
    while lo < hi {
        let mid = (lo + hi) / 2
        if sortedTrees[mid] < n { lo = mid + 1 }
        else { hi = mid }
    }
    
    return lo
}

func possible(height: Int) -> Bool {
    let lb = lowerBound(n: height)
    
    let sum = psum[N-1] - (lb == 0 ? 0 : psum[lb - 1])      // 높이가 height 이상인 나무들의 높이 합
    let count = N - lb                                      // 높이가 height 이상인 나무들의 수
    let left = sum - Int64(height) * Int64(count)           // height 높이에서 자르고 남은 나무들의 길이 합
    
    return left >= M
}

func solution() -> Int {
    var lo = 0, hi = 2000000001

    // possible(lo) && !possible(hi)
    for _ in 0..<100 {
        let mid = (lo + hi) / 2
        
        if possible(height: mid) { lo = mid }
        else { hi = mid }
    }

    return lo
}

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
var trees = readLine()!.split(separator: " ").map{ Int64(String($0))! }
let N = input[0]
let M = input[1]

let sortedTrees = trees.sorted()
var psum = Array(repeating: Int64(0), count: trees.count)
psum[0] = sortedTrees[0]
for i in 1..<N { psum[i] = psum[i - 1] + sortedTrees[i] }

print(solution())
