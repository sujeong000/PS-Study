import Foundation

let n = Int(readLine() ?? "") ?? 0

var i: Int = 0
var sum: Int = 0
for i in 1...n{
    sum += i
}

print(sum)
