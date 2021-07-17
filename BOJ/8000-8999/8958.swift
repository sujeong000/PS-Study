import Foundation

var testcase = Int(readLine()!)!

while testcase > 0{
    
    let result = readLine()!
    
    var combo = 0
    var score = 0
    for char in result{
        if char == "O"{
            combo += 1
            score += combo
        } else{
            combo = 0
        }
    }
    
    print(score)
    testcase -= 1
}
