import Foundation

func check(n: Int) -> Bool{
    let strNum = String(n)
    
    if strNum.count == 1{
        return true
    } else{
        let arr = strNum.map{ Int(String($0))! }
        let gap = arr[0] - arr[1]
        for i in 1..<(arr.count-1){
            if (arr[i] - arr[i+1]) != gap{
                return false
            }
        }
        
        return true
    }
}

let N = Int(readLine()!)!

var cnt = 0
for i in 1...N{
    if check(n: i){
        cnt += 1
    }
}

print(cnt)
