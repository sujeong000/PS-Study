import Foundation

let M: Int64 = 1000000007
var pow2modM = Array(repeating: Int64(1), count: 300001)
for i in 1...300000 { pow2modM[i] = (pow2modM[i-1] * 2) % M }

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int64(String($0))! }
arr.sort()

var result: Int64 = 0
for i in 0..<N {
    let k = arr[i] % M
    // arr[i]가 최대가 되는 경우 2^(N-1-i)가지, 최소가 되는 경우 2^i가지
    result += (((pow2modM[i] - pow2modM[N-1-i] + M) % M) * k) % M
    result %= M
}

print(result)
