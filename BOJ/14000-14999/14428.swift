import Foundation

class SegmentTree {
    let n: Int
    var arr: [Int]
    var rangeMinIndex = Array(repeating: 0, count: 400001)
    
    init(arr: [Int]) {
        self.n = arr.count
        self.arr = arr
        
        _ = makeTree(node: 1, left: 1, right: n)
    }
    
    private func makeTree(node: Int, left: Int, right: Int) -> Int {
        if left == right { rangeMinIndex[node] = left; return rangeMinIndex[node] }
        
        let mid = (left + right) / 2
        let leftMinIndex = makeTree(node: node*2, left: left, right: mid)
        let rightMinIndex = makeTree(node: node*2+1, left: mid+1, right: right)
        rangeMinIndex[node] = arr[leftMinIndex-1] <= arr[rightMinIndex-1] ? leftMinIndex : rightMinIndex
        
        return rangeMinIndex[node]
    }
    
    private func update(index: Int, node: Int, left: Int, right: Int) -> Int {
        if index < left || right < index { return rangeMinIndex[node] }
        if left == right { return index }
        
        let mid = (left + right) / 2
        let leftMinIndex = update(index: index, node: node*2, left: left, right: mid)
        let rightMinIndex = update(index: index, node: node*2+1, left: mid+1, right: right)
        rangeMinIndex[node] = arr[leftMinIndex-1] <= arr[rightMinIndex-1] ? leftMinIndex : rightMinIndex
        
        return rangeMinIndex[node]
    }
    
    func update(index: Int, newVal: Int) {
        arr[index - 1] = newVal
        _ = update(index: index, node: 1, left: 1, right: n)
    }
    
    private func query(lo: Int, hi: Int, node: Int, left: Int, right: Int) -> Int {
        if hi < left || right < lo { return -1 }
        if lo <= left && right <= hi { return rangeMinIndex[node] }
        
        let mid = (left + right) / 2
        let leftMinIndex = query(lo: lo, hi: hi, node: node*2, left: left, right: mid)
        let rightMinIndex = query(lo: lo, hi: hi, node: node*2+1, left: mid+1, right: right)
        
        if leftMinIndex == -1 { return rightMinIndex }
        else if rightMinIndex == -1 { return leftMinIndex }
        else { return arr[leftMinIndex-1] <= arr[rightMinIndex-1] ? leftMinIndex : rightMinIndex }
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
