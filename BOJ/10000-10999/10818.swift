import Foundation

let N = Int(readLine() ?? "") ?? 0
let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

var min = 1000001
var max = -1000001
for i in 0..<N{
    if min > arr[i]{
        min = arr[i]
    }
    if max < arr[i]{
        max = arr[i]
    }
}

print("\(min) \(max)")
