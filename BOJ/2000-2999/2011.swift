import Foundation

let MOD: Int64 = 1_000_000
var arr = [Int]()
var cache = Array(repeating: Int64(-1), count: 5001)

func dp(_ index: Int) -> Int64 {
    if index == arr.count { return 1 }
    
    var ret = cache[index]
    if ret != -1 { return ret }
    
    if arr[index] != 0 {
        ret = dp(index+1)
        
        if (index < arr.count-1) && (arr[index]*10 + arr[index+1] <= 26) {
            ret += dp(index + 2)
            ret %= MOD
        }
    } else {
        ret = 0
    }

    cache[index] = ret
    
    return ret
}

func solution() {
    arr = readLine()!.map{ Int(String($0))! }
    
    print(dp(0))
}

solution()
