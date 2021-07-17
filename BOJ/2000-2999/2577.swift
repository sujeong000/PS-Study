import Foundation

let A = Int(readLine()!)!
let B = Int(readLine()!)!
let C = Int(readLine()!)!

var mulResult = A * B * C

var countArr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
while mulResult > 0{
    let x = mulResult % 10
    countArr[x] += 1
    mulResult /= 10
}

for i in 0..<10{
    print(countArr[i])
}
