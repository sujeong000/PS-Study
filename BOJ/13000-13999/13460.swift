import Foundation

typealias Pair = (row: Int, col: Int)

let INF = 987654321
var N = 0, M = 0
var board = Array(repeating: Array(repeating: Character(" "), count: 100), count: 100)
var red = Pair(0, 0), blue = Pair(0, 0), hole = Pair(0, 0)
var result = INF

enum Direction: CaseIterable {
    case up, down, left, right
}

enum Marble {
    case red, blue
}

func move(direction: Direction, target: Marble) -> Bool {
    var marble: Pair
    
    switch target {
    case .red:
        board[red.row][red.col] = "."
        marble = red
    case .blue:
        board[blue.row][blue.col] = "."
        marble = blue
    }
    
    switch direction {
    case .up:
        while marble.row > 0 {
            guard board[marble.row-1][marble.col] != "#",
                  board[marble.row-1][marble.col] != "R",
                  board[marble.row-1][marble.col] != "B" else { break }
                  
            marble = (marble.row-1, marble.col)
            if board[marble.row][marble.col] == "O" { break }
        }
    case .down:
        while marble.row < N-1 {
            guard board[marble.row+1][marble.col] != "#",
                  board[marble.row+1][marble.col] != "R",
                  board[marble.row+1][marble.col] != "B" else { break }
      
            marble = (marble.row+1, marble.col)
            if board[marble.row][marble.col] == "O" { break }
        }
    case .left:
        while marble.col > 0 {
            guard board[marble.row][marble.col-1] != "#",
                  board[marble.row][marble.col-1] != "R",
                  board[marble.row][marble.col-1] != "B" else { break }
            
            marble = (marble.row, marble.col-1)
            if board[marble.row][marble.col] == "O" { break }
        }
    case .right:
        while marble.col < M-1 {
            guard board[marble.row][marble.col+1] != "#",
                  board[marble.row][marble.col+1] != "R",
                  board[marble.row][marble.col+1] != "B" else { break }
         
            marble = (marble.row, marble.col+1)
            if board[marble.row][marble.col] == "O" { break }
        }
    }
    
    if board[marble.row][marble.col] == "O" { return true }
    
    switch target {
    case .red:
        board[marble.row][marble.col] = "R"
        red = marble
    case .blue:
        board[marble.row][marble.col] = "B"
        blue = marble
    }
    
    return false
}

func simulate(depth: Int, direction: Direction) {
    if depth > 10 || depth >= result { return }
    
    let didBlueFall: Bool
    let didRedFall: Bool
    
    switch direction {
    case .up:
        if blue.row < red.row {
            didBlueFall = move(direction: .up, target: .blue)
            didRedFall = move(direction: .up, target: .red)
        } else {
            didRedFall = move(direction: .up, target: .red)
            didBlueFall = move(direction: .up, target: .blue)
        }
    case .down:
        if blue.row > red.row {
            didBlueFall = move(direction: .down, target: .blue)
            didRedFall = move(direction: .down, target: .red)
        } else {
            didRedFall = move(direction: .down, target: .red)
            didBlueFall = move(direction: .down, target: .blue)
        }
    case .left:
        if blue.col < red.col {
            didBlueFall = move(direction: .left, target: .blue)
            didRedFall = move(direction: .left, target: .red)
        } else {
            didRedFall = move(direction: .left, target: .red)
            didBlueFall = move(direction: .left, target: .blue)
        }
    case .right:
        if blue.col > red.col {
            didBlueFall = move(direction: .right, target: .blue)
            didRedFall = move(direction: .right, target: .red)
        } else {
            didRedFall = move(direction: .right, target: .red)
            didBlueFall = move(direction: .right, target: .blue)
        }
    }
    
    if didBlueFall { return }
    if didRedFall { result = min(result, depth) }
    
    for nextDirection in Direction.allCases {
        guard direction != nextDirection else { continue }
        
        let originalBoard = board
        let originalRed = red
        let originalBlue = blue
        
        simulate(depth: depth+1, direction: nextDirection)
        
        board = originalBoard
        red = originalRed
        blue = originalBlue
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        board[i] = readLine()!.map{ $0 }
        for j in 0..<M {
            if board[i][j] == "R" { red = (i, j) }
            else if board[i][j] == "B" { blue = (i, j) }
        }
    }
    
    for direction in Direction.allCases {
        let originalBoard = board
        let originalRed = red
        let originalBlue = blue
        
        simulate(depth: 1, direction: direction)
        
        board = originalBoard
        red = originalRed
        blue = originalBlue
    }
    
    print(result == INF ? -1 : result)
}

solution()
