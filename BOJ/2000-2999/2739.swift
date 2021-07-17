import Foundation

let N = Int(readLine() ?? "") ?? 0

var i: Int = 0
for i in 1...9 {
    print("\(N) * \(i) = \(i*N)")
}
