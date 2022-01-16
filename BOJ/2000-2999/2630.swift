import Foundation

var paper = Array(repeating: Array(repeating: 0, count: 128), count: 128)

typealias Color = (white: Int, blue: Int)

func countColor(row: Int, col: Int, size: Int) -> Color {
    // Base Case
    if size == 1 {
        if paper[row][col] == 1 { return (0, 1) }
        else { return (1, 0) }
    }
    
    var white = 0
    var blue = 0
    
    let rowPoint = [row, row + size / 2]
    let colPoint = [col, col + size / 2]
    
    for i in 0..<2 {                    // 4분면으로 나눠서 각각 카운트 후 합침
        for j in 0..<2 {
            let quadrant = countColor(row: rowPoint[i],
                                      col: colPoint[j],
                                      size: size / 2)
            white += quadrant.white
            blue += quadrant.blue
        }
    }
    
    if white == 0 { return (0, 1) }     // 4분면의 색이 모두 같으면 자르지 않음
    if blue == 0 { return (1, 0) }
    
    return (white, blue)
}

let N = Int(readLine()!)!
for i in 0..<N {
    let row = readLine()!.split(separator: " ").map{ Int(String($0))! }
    row.enumerated().forEach{ paper[i][$0] = $1 }
}

let result = countColor(row: 0, col: 0, size: N)

print(result.white)
print(result.blue)
