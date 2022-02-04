import Foundation

var A: Int64 = 0, B: Int64 = 0
var numberOfOne = Array(repeating: Int64(1), count: 54) // 2^(i) 미만인 모든 수에 대해 1의 개수의 합

func lg(_ n: Int64) -> Int {
    var x = n
    var count = 0
    
    while x > 1 {
        x /= 2
        count += 1
    }
    
    return count
}

func countNumberOfOne() {
    for i in 1..<54 {
        numberOfOne[i] = 2 * numberOfOne[i-1] + (Int64(1) << i)
    }
}

func psum(x: Int64) -> Int64 {  // x이하인 모든 수에 대해 1의 개수의 합
    if x <= 1 { return x }
    
    let lg = lg(x)                                      // 부동 소수점때문에 log2()쓰면 부정확, 반례: 281474976710656 562949953421311
    let lessThanPowlg = numberOfOne[lg-1]               // lg 미만 자리수를 가진 수들의 1의 개수 합
    let numberOfRemainder = x - (Int64(1) << lg) + 1    // lg 자리수를 가진 수들의 맨 앞 1의 개수의 합
    let remainder = psum(x: numberOfRemainder - 1)      // lg 자리수를 가진 수들의 맨 앞 1을 제외한 1의 개수의 합
    
    return lessThanPowlg + numberOfRemainder + remainder
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int64(String($0))! }
    A = input[0]
    B = input[1]
    
    countNumberOfOne()
    
    let result = psum(x: B) - psum(x: A-1)
    print(result)
}

solution()

