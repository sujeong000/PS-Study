import Foundation

let N = Int64(readLine()!)!

var count: Int64 = 1
var lo: Int64 = 1
var hi: Int64 = 1

while true {
    if lo <= N && N <= hi {
        print(count)
        break
    }
    
    lo = hi + 1
    hi = lo + count * 6 - 1
    count += 1
}
