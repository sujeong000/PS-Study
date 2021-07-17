import Foundation

var testcase = Int(readLine()!)!

while testcase > 0{
    
    let arr = readLine()!.split(separator: " ").map{ Double(String($0))! }
    let N = Int(arr[0])
    
    var sum: Double = 0
    for i in 1...N{
        sum += arr[i]
    }
    
    let average = sum / arr[0]
    var cnt = 0
    for i in 1...N{
        if average < arr[i]{
            cnt += 1
        }
    }
    
    print(String(format: "%.3f", Double(cnt) / arr[0] * 100) + "%")
    
    testcase -= 1
}
