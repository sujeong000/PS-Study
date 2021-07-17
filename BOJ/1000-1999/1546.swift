import Foundation

let N = Int(readLine()!)!
var scores = readLine()!.split(separator: " ").map{ Double(String($0))! }

var M: Double = 0
for i in 0..<N{
    if M < scores[i]{ M = scores[i] }
}

var sum: Double = 0
for i in 0..<N{
    scores[i] /= M
    scores[i] *= 100
    sum += scores[i]
}

print(sum / Double(N))
