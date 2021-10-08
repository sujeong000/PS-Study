import Foundation

let white = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let black = readLine()!.components(separatedBy: " ").map{ Int($0)! }

let A = white[0]
let B = white[1]
let C = black[0]
let D = black[1]

if (A % 2 == B % 2) == (C % 2 == D % 2) {
    print("black")
} else {
    print("white")
}
