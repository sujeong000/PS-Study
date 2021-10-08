import Foundation

let x = Double(readLine()!)!

let n = Int(ceil(sqrt(8 * x + 1) / 2 - 0.5))
let sum = n * (n-1) / 2

let col = Int(x) - sum
let row = n - col + 1

n % 2 != 0 ? print("\(row)/\(col)") : print("\(col)/\(row)")
