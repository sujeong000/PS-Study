import Foundation

var r1 = 0, c1 = 0, r2 = 0, c2 = 0
var board = Array(repeating: Array(repeating: 0, count: 5), count: 50)

func fillBoard() {
    if (0..<50) ~= -r1 && (0..<5) ~= -c1 {
        board[-r1][-c1] = 1
    }
    
    var count = 2
    let maxSize = max(abs(r1), abs(c1), abs(r2), abs(c2))
    
    if maxSize == 0 { return }
    
    for size in 1...maxSize {
        for i in 0..<2*size {
            let directions = [
                (size-1-i - r1, size - c1),
                (-size - r1, size-1-i - c1),
                (-size+1+i - r1, -size - c1),
                (size - r1, -size+1+i - c1)
            ]
            
            for d in 0..<4 {
                let direction = directions[d]
                guard (0..<50) ~= direction.0 && (0..<5) ~= direction.1 else { continue }
                board[direction.0][direction.1] = count + 2 * d * size
            }
            
            count += 1
        }
        
        count += 6 * size
    }
}

func findMaxLength() -> Int {
    var maxValue = 0
    
    for i in r1...r2 {
        for j in c1...c2 {
            maxValue = max(board[i - r1][j - c1], maxValue)
        }
    }
    
    return String(maxValue).count
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    r1 = input[0]
    c1 = input[1]
    r2 = input[2]
    c2 = input[3]
    
    fillBoard()
    
    let maxLength = findMaxLength()
    
    var resultString = ""
    for i in r1...r2 {
        for j in c1...c2 {
            let formattedString = String(format: "%\(maxLength)d ", board[i - r1][j - c1])
            resultString.write(formattedString)
        }
        resultString.write("\n")
    }
    print(resultString)
}

solution()
