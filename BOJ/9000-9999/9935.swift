import Foundation

typealias Pair = (i: Int, dictIndex: Int)
struct Stack {
    var stack: [Pair] = Array(repeating: (0, 0), count: 1_000_000)
    var topIndex = -1
    
    var top: Pair {
        return stack[topIndex]
    }
    
    var isEmpty: Bool {
        return topIndex == -1
    }
    
    mutating func push(_ p: Pair) {
        topIndex += 1
        stack[topIndex] = p
    }
    
    mutating func pop() -> Pair {
        let ret = stack[topIndex]
        topIndex -= 1
        return ret
    }
    
    mutating func empty() {
        while !isEmpty { _ = pop() }
    }
}

var dict = [Character:Int]()

func solution() {
    var resultString = ""
    let S = readLine()!
    let explosion = readLine()!
    
    for (index, char) in explosion.enumerated() { dict[char] = index }

    var stack = Stack()                                         // 폭발 문자열이 될 가능성이 있는 문자들을 담는다.
    var didExplode = Array(repeating: false, count: S.count)    // didExplode[i] = i번째 문자의 폭발 여부
    var targetIndex = 0                                         // 폭발 문자열을 완성하기 위해서는 다음에 어떤 문자가 와야 하는지
    
    for (i, char) in S.enumerated() {
        if let index = dict[char],                                                  // 폭발 문자열에 포함된 문자이고
           index == targetIndex || index == 0 {                                     // 찾고자 하는 문자이거나, 폭발 문자열의 시작이면
            stack.push((i, index))                                                  // 폭발 문자열이 될 가능성이 있으므로 스택에 푸시한다.
            targetIndex = index + 1                                                 // 폭발 문자열을 완성하기 위해서 방금 푸시한 문자 다음에 와야 할 문자
            
            if targetIndex >= explosion.count {                                     // 스택 안에서 폭발 문자열이 완성됐으면
                for _ in 0..<explosion.count { didExplode[stack.pop().i] = true }   // 폭발시키고
                targetIndex = stack.isEmpty ? 0 : stack.top.dictIndex + 1           // top을 가지고 다시 폭발 문자열 완성 시도
            }
        } else {                                                                    // 중간에 쓸데없는 문자가 꼈으므로
            stack.empty()                                                           // 스택안에 있는 후보들은 모두 탈락
            targetIndex = 0                                                         // 다시 처음부터 시작
        }
    }
    
    for (i, char) in S.enumerated() {
        if !didExplode[i] { resultString.write("\(char)") }
    }
    
    print(resultString.count == 0 ? "FRULA" : resultString)
}

solution()
