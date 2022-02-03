import Foundation

var isPrime = Array(repeating: true, count: 4_000_001)
var primeNumbers = [Int]()

func getPrimeNumbers() {
    isPrime[1] = false
    
    for i in 2...4_000_000 {
        guard isPrime[i] else { continue }
        
        var x = i * 2
        while x <= 4_000_000 {
            isPrime[x] = false
            x += i
        }
    }
    
    for i in 2...4_000_000 {
        if isPrime[i] { primeNumbers.append(i) }
    }
}

func countNumberOfCases(_ n: Int) -> Int {
    var s = 0, e = 0, sum = 2, count = 0
    
    while true {
        if sum > n {
            sum -= primeNumbers[s]
            s += 1
        } else if sum == n {
            count += 1
            sum -= primeNumbers[s]
            s += 1
        } else {
            guard e < primeNumbers.count-1 else { break }
            e += 1
            sum += primeNumbers[e]
        }
    }
    
    return count
}

func solution() {
    let N = Int(readLine()!)!
    
    getPrimeNumbers()
    print(countNumberOfCases(N))
}

solution()
