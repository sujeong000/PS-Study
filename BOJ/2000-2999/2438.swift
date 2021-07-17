import Foundation

let N = Int(readLine() ?? "") ?? 0

var i: Int
var j: Int
for i in 1...N{
    for j in 1...i{
        print("*", terminator: "")
    }
    print()
}
