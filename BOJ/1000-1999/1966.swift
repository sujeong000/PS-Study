import Foundation

struct Document {
    let index: Int
    let priority: Int
    var isDone: Bool = false
}

func solution(N: Int, M: Int, priorities: [Int]) -> Int {
    var queue = priorities.enumerated().map{ Document(index: $0, priority: $1) }
    var sortedPriorities = priorities.sorted()
    
    var front = 0
    var count = 0
    
    while true {
        while queue[front].isDone {                 // 이미 인쇄한 문서들 스킵
            front = front == N - 1 ? 0 : front + 1
        }
        
        let currentDoc = queue[front]
        let maxPriority = sortedPriorities.last!
        
        if currentDoc.priority < maxPriority {      // 현재 문서보다 중요한 문서가 있는 경우
            front = front == N - 1 ? 0 : front + 1  // 인쇄하지 않고 맨 뒤에 재배치
        } else {                                    // 현재 문서가 가장 중요한 문서인 경우
            count += 1
            queue[front].isDone = true
            _ = sortedPriorities.popLast()          // 인쇄
            
            if currentDoc.index == M { return count }
        }
    }
}

var result = ""

var testcase = Int(readLine()!)!
while testcase > 0 {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let priorities = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    let solution = solution(N: N, M: M, priorities: priorities)
    result.write("\(solution)\n")
    
    testcase -= 1
}

print(result)
