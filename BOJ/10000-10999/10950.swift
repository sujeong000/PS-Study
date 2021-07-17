import Foundation

var testcase = Int(readLine() ?? "") ?? 0

while testcase > 0{
    let input = readLine() ?? ""
    let inputArr = input.split(separator: " ")
    let A = Int(inputArr[0]) ?? 0
    let B = Int(inputArr[1]) ?? 1
    print(A+B)
    
    testcase -= 1
}
