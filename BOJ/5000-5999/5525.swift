import Foundation

func solution() -> String {
    let N = Int(readLine()!)!
    let M = Int(readLine()!)!
    var S = readLine()!
    S += String(S.last!)
    
    var isPN = false
    var before = "O"
    var count = 0
    var pns = [Int]()   // 가장 길게 잡을 수 있는 PN들을 저장
    
    for char in S {
        if String(char) == before {                                 // 교대로 안나오면 PN이 끊긴 것
            if isPN{ pns.append(char == "O" ? count - 1 : count) }  // 지금까지 카운트한 PN 저장
            isPN = false
            count = 0                                               // count 초기화
        } else if char == "O" && isPN {
            count += 1                                              // O의 개수 카운트 > PN에서 N이 됨
        }
        
        before = String(char)
        if char == "I" { isPN = true }
    }
    
    var result = 0
    
    for pn in pns {
        guard pn >= N else { continue }
        
        result += pn - N + 1
    }
    
    return "\(result)"
}


print(solution())
