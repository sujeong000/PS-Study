import Foundation

let testcase = Int(readLine() ?? "") ?? 0

var t: Int
for t in 1...testcase{
    let input = readLine() ?? ""
    let inputArr = input.split(separator: " ")
    let A = Int(inputArr[0]) ?? 0
    let B = Int(inputArr[1]) ?? 1
    
    print("Case #\(t): \(A) + \(B) = \(A+B)")
}
