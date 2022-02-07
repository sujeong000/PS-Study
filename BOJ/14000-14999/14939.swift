import Foundation

let INF = 987654321
var originalArr = Array(repeating: [Bool](), count: 10)
var arr = [[Bool]]()

func toggle(_ row: Int, _ col: Int) {
    arr[row][col].toggle()
    
    let adjacents = [(row-1, col), (row+1, col), (row, col-1), (row, col+1)].filter {
        (0..<10) ~= $0.0 && (0..<10) ~= $0.1
    }
    
    for adj in adjacents {
        arr[adj.0][adj.1].toggle()
    }
}

func simulate(firstRow: Int) -> Int {
    arr = originalArr
    
    var count = 0
    
    for i in 0..<10 {   // 주어진 첫 줄 연산 처리
        guard firstRow & (1 << i) != 0 else { continue }
        toggle(0, i)
        count += 1
    }
    
    for row in 1..<10 {
        for col in 0..<10 { // 윗 줄이 켜져있으면 무조건 꺼야함
            guard arr[row-1][col] else { continue }
            toggle(row, col)
            count += 1
        }
    }
    
    for col in 0..<10 {
        if arr[9][col] { return INF }
    }
    
    return count
}

func bruteForce() -> Int {
    var minCount = INF
    
    for i in 0..<(1 << 10) {    // 첫 줄만 결정하면 나머지는 저절로 결정됨.
        minCount = min(minCount, simulate(firstRow: i))
    }
    
    return minCount
}

func solution() {
    for i in 0..<10 {
        originalArr[i] = readLine()!.map{ $0 == "O" }
    }
    
    let result = bruteForce()
    print(result == INF ? -1 : result)
}

solution()
