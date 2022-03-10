import Foundation

var N = 0, M = 0
var clauses = Array(repeating: (0,0), count: 100)

func calc(with mask: Int) -> Bool {
    var ret = true

    for m in 0..<M {
        let i = clauses[m].0
        let j = clauses[m].1
        
        var x = (mask & (1 << (abs(i)-1))) != 0
        var y = (mask & (1 << (abs(j)-1))) != 0
        
        if i < 0 { x = !x }
        if j < 0 { y = !y }
        
        ret = ret && (x || y)
    }

    return ret
}

func bruteForce() -> Int {
    for i in 0..<(1 << N) {
        if calc(with: i) { return 1 }
    }
    
    return 0
}

func solution() {
    var input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<M {
        input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        clauses[i] = (input[0], input[1])
    }
    
    let result = bruteForce()
    print(result)
}

solution()
