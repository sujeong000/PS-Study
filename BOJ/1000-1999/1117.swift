import Foundation

let input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let W = input[0]
let H = input[1]
let f = input[2]
let c = input[3]
let x1 = input[4]
let y1 = input[5]
let x2 = input[6]
let y2 = input[7]

var widthOfRight = W - f
var widthOfLeft = f

func calculateColoredWidth(w: Int) -> Int64 {
    return w <= x1 ? Int64(0) : Int64(min(x2, w) - x1)
}

let totalColoredArea = (calculateColoredWidth(w: widthOfRight) + calculateColoredWidth(w: widthOfLeft)) * Int64(c + 1) * Int64(y2 - y1)
print(Int64(W) * Int64(H) - totalColoredArea)
