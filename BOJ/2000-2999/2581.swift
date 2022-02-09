import Foundation

var isPrime = Array(repeating: true, count: 10_001)

func findPrimeNumbers() {
    isPrime[1] = false
    
    for i in 2...10_000 {
        guard isPrime[i] else { continue }
        
        var n = i * 2
        while n <= 10_000 {
            isPrime[n] = false
            n += i
        }
    }
}

func solution() {
    let M = Int(readLine()!)!
    let N = Int(readLine()!)!
    
    findPrimeNumbers()
    
    var minPrimeNumber = 10_001
    var primeSum = 0
    
    for i in M...N {
        guard isPrime[i] else { continue }
        if primeSum == 0 { minPrimeNumber = i }
        primeSum += i
    }
    
    if primeSum == 0 {
        print(-1)
    } else {
        print(primeSum)
        print(minPrimeNumber)
    }
}

solution()
