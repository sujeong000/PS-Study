import Foundation

var arr = [[String]]()

func fillStar(row: Int, col: Int, size: Int) {
    let base = base(of: size)       // 밑변 길이
    let height = height(of: size)   // 높이
    
    if size == 1 {
        arr[row][col] = "*"
    } else if size % 2 == 0 {                   // size가 짝수이면 역삼각형
        for i in 0..<base {                     // 밑변
            arr[row][col+i] = "*"
        }
        
        for i in 0..<height-1 {                 // 두 빗변
            arr[row+i+1][col+i+1] = "*"
            arr[row+i+1][col+base-i-2] = "*"
        }
        
        fillStar(row: row + 1, col: col + (height+1)/2, size: size-1)       // 내부 size-1짜리 삼각형
    } else {                                    // size가 홀수이면 정(?)삼각형
        for i in 0..<base {                     // 밑변
            arr[row+height-1][col+i] = "*"
        }
        
        for i in 0..<height-1 {                 // 두 빗변
            arr[row+height-i-2][col+i+1] = "*"
            arr[row+height-i-2][col+base-i-2] = "*"
        }
        
        fillStar(row: row + height/2, col: col + (height+1)/2, size: size-1) // 내부 size-1짜리 삼각형
    }
}

func height(of size: Int) -> Int {
    return Int(pow(2.0, Float(size))) - 1
}

func base(of size: Int) -> Int {
    return height(of: size) * 2 - 1
}

func solution() {
    let N = Int(readLine()!)!
    let height = height(of: N)
    let base = base(of: N)
    arr = Array(repeating: [String](), count: height)
    
    for i in 0..<height {
        if N % 2 == 0 {
            arr[i] = Array(repeating: " ", count: base - i)
        } else {
            arr[i] = Array(repeating: " ", count: base/2+1+i)
        }
    }
    
    fillStar(row: 0, col: 0, size: N)
    
    arr.forEach{ print($0.joined()) }
}

solution()
