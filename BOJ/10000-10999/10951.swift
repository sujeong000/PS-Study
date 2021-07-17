import Foundation

while let input = readLine(){
    let inputArr = input.split(separator: " ")
    
    let A = Int(inputArr[0]) ?? 0
    let B = Int(inputArr[1]) ?? 0
    
    print(A+B)
}
