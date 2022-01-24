import Foundation

var N = 0
var arr = [Int]()

func LPS(_ index: Int) -> Int {     // arr[index]를 중앙으로 하는 가장 긴 증가하는 팰린드롬 부분수열 길이
    var l = index
    var r = index != N - 1 && arr[index] == arr[index+1] ? index + 1 : index
    
    var length = r - l + 1
    var last = arr[l]
    
    while true {
        l -= 1
        r += 1
        
        guard l >= 0,
              r < N,
              arr[l] == arr[r],
              arr[l] < last else { return length }
        
        length += 2
        last = arr[l]
    }
}

func solution() {
    N = Int(readLine()!)!
    arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    var result = 0
    for i in 0..<N { result = max(result, LPS(i)) }     // 모든 포인트에 대해 완전 탐색
    print(result)                                       // 이렇게 해도 증가하는 팰린드롬 성질 때문에 O(N)에 돌아감
}

solution()
