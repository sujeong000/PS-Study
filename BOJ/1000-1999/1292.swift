import Foundation

var psum = [0]

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let A = input[0]
    let B = input[1]
    
    var n = 1
    while psum.count <= 1000 {
        for _ in 0..<n {
            psum.append(psum.last! + n)
        }
        n += 1
    }
    
    print(psum[B] - psum[A-1])
}

solution()
