import Foundation

var maxIdx = -1
var max = 0

for i in 1...9{
    let n = Int(readLine()!)!
    
    if max < n{
        maxIdx = i
        max = n
    }
}

print(max)
print(maxIdx)
