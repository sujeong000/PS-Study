import Foundation

let N = Int(readLine() ?? "") ?? -1

var cycle: Int = 0
var now = N

repeat{
    let a = now / 10
    let b = now % 10
    let sum = a + b
    let c = sum % 10
    now = b * 10 + c
    cycle += 1
}while now != N

print(cycle)
