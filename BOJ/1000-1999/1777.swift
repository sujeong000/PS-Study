import Foundation

class FenwickTree {
    var n: Int
    var tree = Array(repeating: 0, count: 100002)
    
    init(n: Int) {
        self.n = n
        (1...100000).forEach{ add(at: $0, val: 1) }
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
    
    // [1...]부터의 구간합이 최초로 targetSum 이상이 되는 위치의 인덱스 반환
    func lb(targetSum: Int) -> Int {
        var lo = 1, hi = n + 1
        
        while lo < hi {
            let mid = (lo + hi) / 2
            if sum(to: mid) < targetSum { lo = mid + 1 }
            else { hi = mid }
        }
        
        return lo
    }
}

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

var fwt = FenwickTree(n: N)
var seq = Array(repeating: 0, count: N + 1)

for i in 0..<N {
    let num = N - i                                     // 큰 수부터 차례로 위치시키기
    let index = fwt.lb(targetSum: arr[num - 1] + 1)     // num보다 뒤에 있으면서 작은 것의 개수가 arr[num - 1]개인 자리
    seq[N - index] = num                                // 뒤에서 index번째에 위치하면 됨
    
    fwt.add(at: index, val: -1)                         // 뒤에서 index번째 자리 선점 여부 체크
}

var result = ""
for i in 0..<N {
    result.write("\(seq[i]) ")
}
print(result)
