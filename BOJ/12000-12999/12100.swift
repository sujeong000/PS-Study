import Foundation

var N = 0, result = 0
var board = [[Int]]()

enum Direction: CaseIterable {
    case up, down, left, right
}

func swipe(direction: Direction, state: [[Int]]) -> [[Int]] {
    var swipedState = state
    
    for i in 0..<N {                    // 한 행/열씩 민다.
        let originalColOrRow: [Int]
        switch direction {
        case .left: originalColOrRow = state[i]
        case .right: originalColOrRow = state[i].reversed()
        case .up: originalColOrRow = (0..<N).map{ state[$0][i] }
        case .down: originalColOrRow = (0..<N).reversed().map{ state[$0][i] }
        }
        
        // 1. 한 방향으로 몰기
        var newColOrRow = originalColOrRow.filter{ $0 != 0 }
        
        guard !newColOrRow.isEmpty else { continue }
        
        // 2. 합치기
        for j in 0..<newColOrRow.count-1 {
            guard newColOrRow[j] == newColOrRow[j+1] else { continue }
            newColOrRow[j] *= 2
            newColOrRow[j+1] = 0
        }
        
        // 3. 빈자리 처리
        newColOrRow = newColOrRow.filter{ $0 != 0 }
        while newColOrRow.count < N { newColOrRow.append(0) }
        
        // 4. 결과 복사
        switch direction {
        case .left: swipedState[i] = newColOrRow
        case .right: swipedState[i] = newColOrRow.reversed()
        case .up: (0..<N).forEach{ swipedState[$0][i] = newColOrRow[$0] }
        case .down: (0..<N).forEach{ swipedState[N-1-$0][i] = newColOrRow[$0] }
        }
    }
    
    return swipedState
}

func findMax(_ state: [[Int]]) {
    for i in 0..<N {
        for j in 0..<N {
            result = max(result, state[i][j])
        }
    }
}

func simulate(depth: Int, state: [[Int]]) {
    if depth > 5 { findMax(state); return }

    for direction in Direction.allCases {
        let swipedState = swipe(direction: direction, state: state)
        simulate(depth: depth + 1, state: swipedState)
    }
}

func solution() {
    N = Int(readLine()!)!
    
    for _ in 0..<N {
        board.append(readLine()!.split(separator: " ").map{ Int(String($0))! })
    }
    
    simulate(depth: 1, state: board)
    
    print(result)
}

solution()
