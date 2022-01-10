import Foundation

class FenwickTree {
    var tree = Array(repeating: 0, count: 1000001)
    
    func nthCandy(n: Int) -> Int {
        var left = 1, right = 1000000
        
        while (left < right) {
            let mid = (left + right) / 2
            if n <= sum(to: mid) { right = mid }
            else { left = mid + 1 }
        }
        
        return left
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

let fwt = FenwickTree()
var result = ""

let n = Int(readLine()!)!
for _ in 0..<n {
    let query = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    switch query[0] {
    case 1:
        let rank = query[1]
        let nthCandy = fwt.nthCandy(n: rank)
        result.write("\(nthCandy)\n")
        fwt.add(at: nthCandy, val: -1)
    case 2:
        let flavor = query[1]
        let count = query[2]
        fwt.add(at: flavor, val: count)
    default:
        break
    }
}

print(result)
