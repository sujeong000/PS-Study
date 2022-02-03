import Foundation

var isPrime = Array(repeating: true, count: 4_000_001)
var primeNumbers = [Int]()

func getPrimeNumber() {
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

func numberOfCases(_ n: Int) -> Int {
    var count = isPrime[n] ? 1 : 0
    var i = 0, j = 1, sum = primeNumbers[i] + primeNumbers[j]
    
    while i < j && j < primeNumbers.count {
        if sum >= n {
            if sum == n { count += 1 }
            
            i += 1
            sum -= primeNumbers[i-1]
            
            if i == j {
                j += 1
                guard j < primeNumbers.count else { break }
                sum += primeNumbers[j]
            }
        } else {
            j += 1
            guard j < primeNumbers.count else { break }
            sum += primeNumbers[j]
        }
    }
    
    return count
}

func solution() {
    let N = Int(readLine()!)!
    
    getPrimeNumber()
    print(numberOfCases(N))
}

solution()
