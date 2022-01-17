import Foundation


var result = ""

var T = Int(readLine()!)!

while T > 0 {
    let p = readLine()!
    let n = Int(readLine()!)!
    let arr = readLine()!
            .replacingOccurrences(of: "[\\[\\]]", with: "", options: .regularExpression)
            .split(separator: ",")
            .map{ Int(String($0))! }
    
    var front = 0
    var end = n - 1
    var reverse = false
    var error = false
    
    for query in p {
        switch String(query) {
        case "R":
            swap(&front, &end)      // 순서 뒤집기
            reverse.toggle()        // 뒤집음 표시
        case "D":
            if !reverse && front <= end {           // 정방향일 때 비어있지 않으면
                front += 1
            } else if reverse && front >= end {     // 역방향일 때 비어있지 않으면
                front -= 1
            } else {                                // 비어있을 때 D하면 에러
                error = true
                break
            }
        default:
            break
        }
    }
    
    if error {
        result.write("error\n")
    } else {
        result.write("[")
        
        while (!reverse && front <= end) || (reverse && front >= end) {
            result.write("\(arr[front])")
            if front != end { result.write(",") }
            
            front += reverse ? -1 : 1
        }
        
        result.write("]\n")
    }
    
    T -= 1
}

print(result)
