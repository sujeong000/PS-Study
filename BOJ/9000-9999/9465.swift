import Foundation

var N = 0
var cache = Array(repeating: Array(repeating: Array(repeating: -1, count: 2), count: 2), count: 100001)
var stickers = Array(repeating: [Int](), count: 2)

// n번째 열의 위아래 스티커 존재 여부가 up, down일 때, n번째 열부터 끝까지 고려했을 때 얻을 수 있는 최대 점수
func dp(n: Int, up: Int, down: Int) -> Int {
    // 기저 사례
    if n == N { return 0 }
    
    // 캐싱
    var ret = cache[n][up][down]
    if ret != -1 { return ret }
    
    ret = dp(n: n + 1, up: 1, down: 1)                                  // 둘 다 그냥 두기

    if up == 1 {
        ret = max(ret, stickers[0][n] + dp(n: n+1, up: 0, down: 1))     // 위에거 떼기
    }
    if down == 1 {
        ret = max(ret, stickers[1][n] + dp(n: n+1, up: 1, down: 0))     // 아래거 떼기
    }
    
    cache[n][up][down] = ret
    
    return ret
}

func initTestcase() {
    cache = Array(repeating: Array(repeating: Array(repeating: -1, count: 2), count: 2), count: 100001)
}

func solution() -> String {
    var result = ""
    
    var T = Int(readLine()!)!
    while T > 0 {
        initTestcase()
        
        N = Int(readLine()!)!
        for i in 0..<2 {
            stickers[i] = readLine()!.split(separator: " ").map{ Int(String($0))! }
        }
        
        result.write("\(dp(n: 0, up: 1, down: 1))\n")
        
        T -= 1
    }
    
    return result
}

print(solution())
