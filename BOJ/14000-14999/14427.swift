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
    
    private func query(left: Int, right: Int, node: Int, nodeLeft: Int, nodeRight: Int) -> Int {
        if right < nodeLeft || nodeRight < left { return -1 }
        if left <= nodeLeft && nodeRight <= right { return rangeMinIndex[node] }
        
        let mid = (nodeLeft + nodeRight) / 2
        let leftMinIndex = query(left: left, right: right, node: node*2, nodeLeft: nodeLeft, nodeRight: mid)
        let rightMinIndex = query(left: left, right: right, node: node*2+1, nodeLeft: mid+1, nodeRight: nodeRight)
        
        if leftMinIndex == -1 { return rightMinIndex }
        else if rightMinIndex == -1 { return leftMinIndex }
        else { return arr[leftMinIndex-1] <= arr[rightMinIndex-1] ? leftMinIndex : rightMinIndex }
    }
    
    func query(left: Int, right: Int) -> Int {
        return query(left: left, right: right, node: 1, nodeLeft: 1, nodeRight: n)
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
        result.write("\(segTree.query(left: 1, right: N))\n")
    }
}

print(result)
