import Foundation

class FenwickTree {
    var tree = Array(repeating: 0, count: 500001)
    
    init() {
        for i in 1...500000 { self.add(at: i, val: 1) }
    }
    
    func sum(to: Int) -> Int {
        var ret = 0
        var pos = to
        
        while (pos > 0) {
            ret += tree[pos]
            pos &= (pos - 1)
        }
        
        return ret
    }
    
    func add(at: Int, val: Int) {
        var pos = at
        
        while(pos < tree.count) {
            tree[pos] += val
            pos += (pos & -pos)
        }
    }
}

var i = 0
var dict = Array(repeating: -1, count: 1000001)
let N = Int(readLine()!)!
let lineA = readLine()!.split(separator: " ").map{ Int(String($0))! }
for (index, machine) in lineA.enumerated() { dict[machine] = index + 1 }
let lineB = readLine()!.split(separator: " ").map{ Int(String($0))! }

let fwt = FenwickTree()

var result = 0
for machine in lineB {
    let index = dict[machine]
    result += fwt.sum(to: index - 1)
    fwt.add(at: index, val: -1)
}

print(result)
