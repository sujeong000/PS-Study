import Foundation

class SegmentTree {
    let n: Int
    var arr: [Int]
    var rangeMin = Array(repeating: 0, count: 400001)
    
    init(arr: [Int]) {
        self.n = arr.count
        self.arr = arr
        
        _ = makeTree(node: 1, left: 1, right: n)
    }
    
    private func makeTree(node: Int, left: Int, right: Int) -> Int {
        if left == right { rangeMin[node] = arr[left-1]; return rangeMin[node] }
        
        let mid = (left + right) / 2
        let leftMin = makeTree(node: node*2, left: left, right: mid)
        let rightMin = makeTree(node: node*2+1, left: mid+1, right: right)
        rangeMin[node] = min(leftMin, rightMin)
        
        return rangeMin[node]
    }
    
    private func update(index: Int, newVal: Int, node: Int, left: Int, right: Int) -> Int {
        if index < left || right < index { return rangeMin[node] }
        if left == right { rangeMin[node] = newVal; return rangeMin[node] }
        
        let mid = (left + right) / 2
        let leftMin = update(index: index, newVal: newVal, node: node*2, left: left, right: mid)
        let rightMin = update(index: index, newVal: newVal, node: node*2+1, left: mid+1, right: right)
        rangeMin[node] = min(leftMin, rightMin)
        
        return rangeMin[node]
    }
    
    func update(index: Int, newVal: Int) {
        _ = update(index: index, newVal: newVal, node: 1, left: 1, right: n)
    }
    
    private func query(lo: Int, hi: Int, node: Int, left: Int, right: Int) -> Int {
        if hi < left || right < lo { return 1000000001 }
        if lo <= left && right <= hi { return rangeMin[node] }
        
        let mid = (left + right) / 2
        let leftMin = query(lo: lo, hi: hi, node: node*2, left: left, right: mid)
        let rightMin = query(lo: lo, hi: hi, node: node*2+1, left: mid+1, right: right)
        
        return min(leftMin, rightMin)
    }
    
    func query(lo: Int, hi: Int) -> Int {
        return query(lo: lo, hi: hi, node: 1, left: 1, right: n)
    }
}

let N = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }

let segTree = SegmentTree(arr: arr)
var result = ""

let M = Int(readLine()!)!
for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    if input[0] == 1 {
        segTree.update(index: input[1], newVal: input[2])
    } else {
        result.write("\(segTree.query(lo: input[1], hi: input[2]))\n")
    }
}

print(result)
