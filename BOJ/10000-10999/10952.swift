import Foundation

while true{
    let input = readLine() ?? ""
    let inputArr = input.split(separator: " ")
    
    let A = Int(inputArr[0]) ?? 0
    let B = Int(inputArr[1]) ?? 0
    
    if A == 0, B == 0{
        break
    } else{
        print(A+B)
    }
}
