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

var arr = Array(repeating: (1000000001, 1000000001), count: 500001)
var rank = Array(repeating: -1, count: 500001)

let N = Int(readLine()!)!
for i in 0..<N { arr[i] = (i + 1, Int(readLine()!)!) }

let sortedArr = arr.sorted(by: { $0.1 < $1.1 })

let fwt = FenwickTree()
for i in 0..<N {
    let index = sortedArr[i].0
    rank[index] = fwt.sum(to: index - 1) + 1    // 최선의 등수 = i보다 앞에 있으면서 i보다 큰 것의 개수 + 1
    fwt.add(at: index, val: -1)
}

var result = ""
for i in 1...N {
    result.write("\(rank[i])\n")
}
print(result)
