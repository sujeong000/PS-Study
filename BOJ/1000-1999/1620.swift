import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]

var numToString = Array(repeating: "", count: 100001)
var stringToNum = [String:Int]()

for i in 1...N {
    let pokemon = readLine()!
    numToString[i] = pokemon
    stringToNum[pokemon] = i
}

var result = ""

for _ in 1...M {
    let query = readLine()!
    let num = Int(query) ?? 0
    if num == 0 {
        result.write("\(stringToNum[query]!)\n")
    } else {
        result.write("\(numToString[num])\n")
    }
}

print(result)
