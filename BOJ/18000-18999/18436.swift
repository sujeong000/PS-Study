import Foundation

class FenwickTree {
    var tree = Array(repeating: 0, count: 100001)
    
    init(arr: [Int]) {
        for (index, num) in arr.enumerated() {
            if num % 2 == 0 {
                add(at: index + 1, val: 1)
            }
        }
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

let N = Int(readLine()!)!
var arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

var fwt = FenwickTree(arr: arr)     // 짝수만 카운트
var result = ""

let M = Int(readLine()!)!
for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    if input[0] == 1 {
        let index = input[1]
        let newVal = input[2]
        
        if arr[index - 1] % 2 != 0 && newVal % 2 == 0 {         // 홀수 > 짝수로 업데이트 : 짝수 개수 + 1
            fwt.add(at: index, val: 1)
        } else if arr[index - 1] % 2 == 0 && newVal % 2 != 0 {  // 짝수 > 홀수로 업데이트 : 짝수 개수 - 1
            fwt.add(at: index, val: -1)
        }
        
        arr[index - 1] = newVal
    } else {
        let lo = input[1]
        let hi = input[2]
        
        let evenCount = fwt.sum(to: hi) - fwt.sum(to: lo - 1)   // 짝수 개수 = 구간합 [lo...hi]
        let oddCount = hi - lo + 1 - evenCount                  // 홀수 개수 = 구간 길이 - 짝수 개수
        
        result.write("\(input[0] == 2 ? evenCount : oddCount)\n")
    }
}

print(result)
