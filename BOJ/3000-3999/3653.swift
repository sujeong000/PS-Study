import Foundation

class FenwickTree {
    var tree = Array(repeating: 0, count: 200001)
    
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

var index = Array(repeating: 0, count: 100001)

let testcase = Int(readLine()!)!
for _ in 0..<testcase {
    let fwt = FenwickTree()
    var result = ""
    
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let n = input[0]
    let m = input[1]
    
    // 초기화
    (1...n).forEach{
        index[$0] = $0 + 100000
        fwt.add(at: $0 + 100000, val: 1)
    }
    
    input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    for i in 0..<m {
        let targetDVD = input[i]
        
        // targetDVD보다 위에 놓인 DVD의 수 = targetDVD의 index보다 작은 index의 개수
        let upperCount = fwt.sum(to: index[targetDVD] - 1)
        result.write("\(upperCount) ")
        
        // targetDVD를 뽑아서 맨 위에 둔다 = targetDVD의 index를 최소로 변경
        fwt.add(at: index[targetDVD], val: -1)
        index[targetDVD] = 100000 - i
        fwt.add(at: index[targetDVD], val: 1)
    }
    
    print(result)
}
