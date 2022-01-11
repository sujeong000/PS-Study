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
var dict = Array(repeating: -1, count: 500001)
var rank = Array(repeating: -1, count: 500001)

let N = Int(readLine()!)!
for i in 0..<N { arr[i] = (i, Int(readLine()!)!) }

// 좌표 압축 : 상대적인 실력만 필요하므로 1~N 범위로 압축
arr.sort(by: { $0.1 < $1.1 })
for i in 0..<N { arr[i] = (arr[i].0, i+1) }
arr.sort(by: { $0.0 < $1.0 })

for i in 0..<N { dict[arr[i].1] = i + 1 }

let fwt = FenwickTree()
for i in 1...N {
    let index = dict[i]
    rank[index] = fwt.sum(to: index - 1) + 1    // 최선의 등수 = i보다 앞에 있으면서 i보다 큰 것의 개수 + 1
    fwt.add(at: index, val: -1)
}

var result = ""
for i in 1...N {
    result.write("\(rank[i])\n")
}
print(result)
