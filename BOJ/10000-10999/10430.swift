import Foundation

let line = readLine() ?? ""
let lineArr = line.split(separator: " ")
let a = Int(lineArr[0]) ?? 0
let b = Int(lineArr[1]) ?? 0
let c = Int(lineArr[2]) ?? 0

print((a+b)%c)
print(((a%c)+(b%c)) % c)
print((a*b)%c)
print(((a%c)*(b%c))%c)
