import Foundation

let r: Int64 = 31
let M: Int64 = 1234567891

var dict = [Character:Int64]()
"abcdefghijklmnopqrstuvwxyz".enumerated().forEach{ dict[$1] = Int64($0 + 1) }

let L = Int(readLine()!)!
let myString = readLine()!

var result: Int64 = 0
var powR: Int64 = 1

for myChar in myString {
    result = (result + (dict[myChar]! * powR) % M) % M
    powR = (powR * r) % M
}

print(result)
