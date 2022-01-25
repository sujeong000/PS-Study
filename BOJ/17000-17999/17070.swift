import Foundation

var N = 0
var cache = Array(repeating: Array(repeating: Array(repeating: -1, count: 3), count: 17), count: 17)
var home = Array(repeating: [Int](), count: 17)

typealias Point = (row: Int, col: Int)

struct Pipe {
    enum Direction: Int {
        case vertical = 0, horizontal, diagonal
    }
    
    let pos: Point
    let direction: Direction
    
    var row: Int {
        return pos.row
    }
    
    var col: Int {
        return pos.col
    }
    
    var endPoint: Point {
        switch direction {
        case .vertical:
            return (pos.row+1, pos.col)
        case .horizontal:
            return (pos.row, pos.col+1)
        case .diagonal:
            return (pos.row+1, pos.col+1)
        }
    }
    
    func canPush(direction: Direction) -> Bool {
        switch direction {
        case .horizontal:
            return endPoint.col+1 <= N &&
                   home[endPoint.row][endPoint.col+1] == 0
        case .vertical:
            return endPoint.row+1 <= N &&
                   home[endPoint.row+1][endPoint.col] == 0
        case .diagonal:
            return endPoint.row+1 <= N &&
                   endPoint.col+1 <= N &&
                   home[endPoint.row+1][endPoint.col+1] == 0 &&
                   home[endPoint.row+1][endPoint.col] == 0 &&
                   home[endPoint.row][endPoint.col+1] == 0
        }
    }
    
    var nextState: [Pipe] {
        var directions = [Direction]()
        
        switch direction {
        case .horizontal:
            if canPush(direction: .horizontal) { directions.append(.horizontal) }
            if canPush(direction: .diagonal) { directions.append(.diagonal) }
        case .vertical:
            if canPush(direction: .vertical) { directions.append(.vertical) }
            if canPush(direction: .diagonal) { directions.append(.diagonal) }
        case .diagonal:
            if canPush(direction: .horizontal) { directions.append(.horizontal) }
            if canPush(direction: .vertical) { directions.append(.vertical) }
            if canPush(direction: .diagonal) { directions.append(.diagonal) }
        }
    
        return directions.map{ Pipe(pos: endPoint, direction: $0)}
    }
}

func dp(pipe: Pipe) -> Int {        // dp(pipe) = pipe의 한쪽 끝을 (N,N)으로 옮기는 방법의 수
    if pipe.endPoint.row > N || pipe.endPoint.col > N { return 0 }
    if pipe.endPoint.row == N && pipe.endPoint.col == N { return 1 }

    var ret = cache[pipe.row][pipe.col][pipe.direction.rawValue]
    if ret != -1 { return ret }

    ret = 0
    pipe.nextState.forEach{ ret += dp(pipe: $0) }   // 이동 가능한 모든 방법 고려
    cache[pipe.row][pipe.col][pipe.direction.rawValue] = ret

    return ret
}

func solution() {
    N = Int(readLine()!)!

    for i in 1...N {
        home[i] = [0] + readLine()!.split(separator: " ").map{ Int(String($0))! }
    }

    let initialPipe = Pipe(pos: (1,1), direction: .horizontal)
    let result = dp(pipe: initialPipe)

    print(result)
}

solution()
