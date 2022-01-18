import Foundation

typealias Position = (row: Int, col: Int)
typealias Node = (pos: Position, depth: Int)

var arr = Array(repeating: Array(repeating: -1, count: 20), count: 20)
var babyShark = Shark(pos: (0,0))
var N = 0

struct Shark {
    var pos: Position
    var eatingCount: Int
    var size: Int
    
    init(pos: Position) {
        self.pos = pos
        self.eatingCount = 0
        self.size = 2
    }
    
    mutating func eat(at pos: Position) {
        arr[pos.row][pos.col] = 0
        eatingCount += 1
        
        if eatingCount == size {
            size += 1
            eatingCount = 0
        }
        
        move(to: pos)
    }
    
    mutating func move(to pos: Position) {
        self.pos = pos
    }
}

struct Queue {
    private var queue = [Node]()
    private var front = 0
    
    var isEmpty: Bool {
        return front >= queue.count
    }
    
    mutating func insert(_ node: Node) {
        queue.append(node)
    }
    
    mutating func popFront() -> Node {
        let ret = queue[front]
        front += 1
        return ret
    }
}

func findFood() -> Node {
    var queue = Queue()
    var visit = Array(repeating: Array(repeating: false, count: N), count: N)
    var candidates = [Node]()       // 먹이 후보, 추후에 후보 중 우선순위가 가장 높은 것을 리턴
    
    queue.insert((babyShark.pos, 0))
    visit[babyShark.pos.row][babyShark.pos.col] = true
    
    while !queue.isEmpty {                  // BFS
        let current = queue.popFront()
        let row = current.pos.row
        let col = current.pos.col
        let depth = current.depth
        
        var adjacents = [Position]()
        
        if row != 0 { adjacents.append((row - 1, col)) }        // 상
        if col != 0 { adjacents.append((row, col - 1)) }        // 좌
        if row != N - 1 { adjacents.append((row + 1, col)) }    // 하
        if col != N - 1 { adjacents.append((row, col + 1)) }    // 우
        
        for adj in adjacents {
            switch arr[adj.row][adj.col] {
            case 0, babyShark.size:                     // 비었거나 크기가 같으면 지나가기만 할 수 있음
                if !visit[adj.row][adj.col] {
                    queue.insert((adj, depth + 1))
                }
            case (1..<babyShark.size):                  // 더 작으면 먹을 수 있음
                candidates.append((adj, depth + 1))
            default:                                    // 더 크면 지나가지 못함
                continue
            }
            
            visit[adj.row][adj.col] = true
        }
    }
    
    candidates.sort(by: {           // 문제에서 주어진 우선순위에 따라 먹이 결정
        if $0.depth == $1.depth {
            if $0.pos.row == $1.pos.row { return $0.pos.col < $1.pos.col }
            else { return $0.pos.row < $1.pos.row }
        } else {
            return $0.depth < $1.depth
        }
    })
    
    return candidates.first ?? ((-1, -1), -1)
}

func solution() -> Int {
    N = Int(readLine()!)!
    
    for i in 0..<N {
        let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
        
        for j in 0..<N {
            arr[i][j] = input[j]
            
            if arr[i][j] == 9 {
                babyShark.move(to: (i, j))
                arr[i][j] = 0
            }
        }
    }
    
    var count = 0
    
    while true {
        let food = findFood()               // 먹이 찾기
        
        if food.pos == (-1, -1) {           // 더 이상 먹이가 없음
            return count
        } else {                            // 먹이 있음
            babyShark.eat(at: food.pos)
            count += food.depth
        }
    }
    
    return count
}

print(solution())
