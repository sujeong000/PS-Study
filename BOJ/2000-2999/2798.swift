import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let cards = readLine()!.split(separator: " ").map{ Int(String($0))! }

let N = input[0]
let M = input[1]

var maxValue = 0

for i in 0..<N-2 {
    for j in i+1..<N-1 {
        for k in j+1..<N {
            let sum = cards[i] + cards[j] + cards[k]
            if sum <= M { maxValue = max(sum, maxValue) }
        }
    }
}

print(maxValue)
