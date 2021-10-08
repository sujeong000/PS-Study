import Foundation

let input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
var toilet = readLine()!.map{ Int("\($0)")! }

let K = input[0]
let L = input[1]
let N = input[2]

for _ in 0..<L {
    toilet.append(0)
}

var using = false
var usingCombo = 0
var emptyCombo = 0
var didFlush = false

for sec in 1...toilet.count {
    let i = toilet[sec - 1]
    if i == 0 {
        usingCombo = 0
        emptyCombo += 1
        if emptyCombo == L && using {
            using = false
            didFlush = true
            print(sec)
        }
    } else {
        emptyCombo = 0
        usingCombo += 1
        if usingCombo == K {
            using = true
        }
    }
}

if !didFlush {
    print("NIKAD")
}
