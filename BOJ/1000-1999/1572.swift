import Foundation

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
    var lo = 1, hi = 65538
    
    while lo < hi {
        let mid = (lo + hi) / 2
        if sum(to: mid) < targetSum { lo = mid + 1 }
        else { hi = mid }
    }
    
    return lo
}

let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let N = input[0]
let K = input[1]
let mid = (K + 1) / 2

var tree = Array(repeating: 0, count: 65539)
var arr = Array(repeating: 1, count: N + 1)
for i in 1...N {
    let num = Int(readLine()!)!;
    arr[i] = num + 1                                    // 0도 들어올 수 있는데, 펜윅트리에서 index는 양수여야 하므로 +1을 해서 기록해줌
}

for i in 0...K-1 {                                      // 일반화를 위해 맨 앞에 0이 추가로 있다고 가정
    add(at: arr[i], val: 1)
}

var result: Int64 = 0
for i in K...N {
    add(at: arr[i - K], val: -1)                    // arr[i - K]는 이번 부분 수열 범위에서 제외됨
    add(at: arr[i], val: 1)                         // arr[i]는 이번 부분 수열 범위에 추가됨
    result += Int64(lb(targetSum: mid) - 1)         // 작은 수 부터 카운트했을 때 합이 (K+1)/2개 이상이 되는 수가 중앙값
}
print(result)
