import Foundation

func gcd(_ A: Int, _ B: Int) -> Int {
    if B == 0 { return A }
    
    return gcd(B, A % B)
}

func solution() -> String {
    var result = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        let M = input[0]
        let N = input[1]
        let X = input[2]
        let Y = input[3]
        
        let gcd = gcd(N, M)
        var findSolution = false
        
        for i in 1...(N/gcd) {              // x를 기준으로 x가 X가 되는 모든 해를 고려, 총 N/gcd개 고려
            let k = (i - 1) * M + X         // k번째 해
            let y = k % N == 0 ? N : k % N  // k번째 해일 때 y값
            
            if y == Y {
                result.write("\(k)\n")
                findSolution = true
                break
            }
        }
        
        if !findSolution { result.write("-1\n") }
        
        T -= 1
    }
    
    return result
}

print(solution())
