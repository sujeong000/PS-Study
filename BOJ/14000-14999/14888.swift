import Foundation

var N = 0
var A = [Int]()
var operators = [Int]()
var maxResult = -1_000_000_001
var minResult = 1_000_000_001

func bruteForce(index: Int, currentValue: Int) {
    if index == N-1 {
        maxResult = max(maxResult, currentValue)
        minResult = min(minResult, currentValue)
        return
    }
    
    for i in 0..<4 {
        guard operators[i] > 0 else { continue }
        
        operators[i] -= 1
        
        var newValue = currentValue
        switch i {
        case 0:
            newValue += A[index+1]
        case 1:
            newValue -= A[index+1]
        case 2:
            newValue *= A[index+1]
        case 3:
            newValue /= A[index+1]
        default:
            break
        }
        bruteForce(index: index+1, currentValue: newValue)
        
        operators[i] += 1
    }
}

func solution() {
    N = Int(readLine()!)!
    A = readLine()!.split(separator: " ").map{ Int(String($0))! }
    operators = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    bruteForce(index: 0, currentValue: A[0])
    
    print(maxResult)
    print(minResult)
}

solution()
