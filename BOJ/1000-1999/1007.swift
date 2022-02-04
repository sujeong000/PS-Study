import Foundation

let INF = 987654321.0
var N = 0
var points = Array(repeating: Vector(x: 0, y: 0), count: 20)
var minLength = INF

struct Vector {
    let x: Int
    let y: Int
    
    var length: Double {
        return sqrt(Double(x*x + y*y))
    }
    
    static func +(lhs: Vector, rhs: Vector) -> Vector {
        Vector(x: lhs.x + rhs.x, y: lhs.y + rhs.y)
    }
    
    static func -(lhs: Vector, rhs: Vector) -> Vector {
        Vector(x: lhs.x - rhs.x, y: lhs.y - rhs.y)
    }
}

func sumAllVectors(bitmask: Int) -> Vector {
    var sum = Vector(x: 0, y: 0)
    
    for i in 0..<N {
        if bitmask & (1 << i) == 0 {
            sum = sum - points[i]       // 마스킹된 N/2개 벡터는 역벡터 처리
        } else {
            sum = sum + points[i]
        }
    }
    
    return sum
}

func bruteForce(index: Int, count: Int, bitmask: Int) { // 절반을 역벡터로 만든다. AB = OB - OA이기 때문
    if index == N {
        if count == N / 2 {
            let sumVector = sumAllVectors(bitmask: bitmask)
            minLength = min(minLength, sumVector.length)
        }
        
        return
    }
    
    if count < N/2 { bruteForce(index: index+1, count: count+1, bitmask: bitmask | (1 << index)) }
    bruteForce(index: index+1, count: count, bitmask: bitmask)
}

func initTestcase() {
    minLength = INF
}

func solution() {
    var resultString = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        initTestcase()
        
        N = Int(readLine()!)!
        
        for i in 0..<N {
            let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
            let pair = Vector(x: input[0], y: input[1])
            points[i] = pair
        }
        
        bruteForce(index: 0, count: 0, bitmask: 0)
        
        resultString.write("\(minLength)\n")
        
        T -= 1
    }
    
    print(resultString)
}

solution()
