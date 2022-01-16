import Foundation

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let M = input[1]

var neverHeard = Set<String>()
var neverSeen = Set<String>()

for _ in 0..<N {
    let name = readLine()!
    neverHeard.insert(name)
}

for _ in 0..<M {
    let name = readLine()!
    neverSeen.insert(name)
}

let neverHeardAndSeen = neverHeard.intersection(neverSeen)

var result = ""
result.write("\(neverHeardAndSeen.count)\n")
neverHeardAndSeen.sorted().forEach{ result.write("\($0)\n") }
print(result)
