import Foundation

var result = ""

var T = Int(readLine()!)!
while T > 0 {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let H = input[0]
    let W = input[1]
    let N = input[2]
    
    let room = N % H == 0 ? N / H : N / H + 1
    let floor = N % H == 0 ? H : N % H
    
    result.write("\(floor)\(room < 10 ? "0": "")\(room)\n")
    
    T -= 1
}

print(result)
