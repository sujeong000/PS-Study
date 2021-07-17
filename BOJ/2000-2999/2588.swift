import Foundation

let a = Int(readLine() ?? "") ?? 0
let b = Int(readLine() ?? "") ?? 0

let b_100 = b / 100
let b_10 = b / 10 % 10
let b_1 = b % 10

let res3 = a * b_1
let res4 = a * b_10
let res5 = a * b_100
let res6 = a * b

print(res3)
print(res4)
print(res5)
print(res6)
