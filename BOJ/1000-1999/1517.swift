import Foundation

var arr = Array(repeating: 0, count: 500001)
var temp = Array(repeating: 0, count: 500001)
var result: Int64 = 0

func mergeSort(lo: Int, hi: Int) {
    if lo == hi { return }
    
    let mid = (lo + hi) / 2
    mergeSort(lo: lo, hi: mid)
    mergeSort(lo: mid + 1, hi: hi)
    
    var left = lo
    var right = mid + 1
    var index = lo
    var combo: Int64 = 0
    
    while left <= mid && right <= hi {
        if arr[left] <= arr[right] {
            temp[index] = arr[left]
            left += 1
            
            result += combo
        } else {
            temp[index] = arr[right]
            right += 1
            
            combo += 1
        }
        
        index += 1
    }
    
    while left <= mid {
        temp[index] = arr[left]
        left += 1
        index += 1
        result += combo
    }
    
    while right <= hi {
        temp[index] = arr[right]
        right += 1
        index += 1
    }
    
    for i in lo...hi { arr[i] = temp[i] }
}

let N = Int(readLine()!)!
arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
mergeSort(lo: 0, hi: N-1)
print(result)
