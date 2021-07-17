import Foundation

var check = [Bool](repeating: false, count: 42)

for i in 0..<10{
    let n = Int(readLine()!)!
    
    check[n%42] = true
}

var cnt = 0
for i in 0..<42{
    if check[i]{
        cnt += 1
    }
}

print(cnt)
