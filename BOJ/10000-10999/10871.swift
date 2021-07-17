import Foundation

let input1 = readLine() ?? ""
let input2 = readLine() ?? ""

let inputArr1 = input1.split(separator: " ")
let inputArr2 = input2.split(separator: " ")

let N = Int(inputArr1[0]) ?? 0
let X = Int(inputArr1[1]) ?? 0

var arr: [Int] = [Int]()
var i: Int
for i in 0..<N{
    let n = Int(inputArr2[i]) ?? 0
    arr.append(n)
}

for i in 0..<N{
    if arr[i] < X{
        print(arr[i], terminator: " ")
    }
}
