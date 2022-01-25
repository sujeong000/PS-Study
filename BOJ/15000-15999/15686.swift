import Foundation

typealias Chicken = (row: Int, col: Int)
typealias ChickenDist = (index: Int, dist: Int)

var N = 0, M = 0
var houses = [House]()
var chickens = [Chicken]()
var result = 987654321

class House {
    let row: Int
    let col: Int
    var chickenDist: [ChickenDist]              // 모든 치킨집까지의 거리
    
    init(row: Int, col: Int) {
        self.row = row
        self.col = col
        self.chickenDist = []
    }
    
    func minChickenDist(mask: Int) -> Int {     // 선택한 치킨집을 mask로 나타낼 때 가장 가까운 치킨집 사이의 거리
        for cd in chickenDist {                 // 오름차순 정렬되어 있으므로 앞에서부터 차례로 탐색
            if mask & (1 << cd.index) != 0 { return cd.dist }
        }
        
        return 2501
    }
}

func calcCityChickenDist(mask: Int) -> Int {    // 도시의 치킨 거리
    var sum = 0
    
    houses.forEach{ sum += $0.minChickenDist(mask: mask) }
    
    return sum
}

// 현재까지 index번째 치킨집까지 고려했고, count개의 치킨집을 골랐으며, 어떤 치킨집들을 골랐는지를 비트마스크 mask로 나타냄
func pickMChickens(index: Int, count: Int, mask: Int) {
    if index == chickens.count {                                // 모든 치킨집을 다 고려했을 때
        guard count <= M else { return }                        // M개 이하의 치킨집을 고른 경우
        result = min(result, calcCityChickenDist(mask: mask))   // 그때의 도시의 치킨 거리 계산 후 최소값 갱신
        return
    }
    
    pickMChickens(index: index+1, count: count, mask: mask)     // index번째 치킨집을 고르지 않음
    
    if count < M {                                              // index번째 치킨집을 고름
        pickMChickens(index: index+1, count: count+1, mask: mask | (1 << index))
    }
}

func solution() {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    N = input[0]
    M = input[1]
    
    for i in 0..<N {
        let city = readLine()!.split(separator: " ").map{ Int(String($0))! }
        for j in 0..<N {
            if city[j] == 1 {
                houses.append(House(row: i, col: j))
            } else if city[j] == 2 {
                chickens.append((i, j))
            }
        }
    }
    
    for house in houses {
        for (index, chicken) in chickens.enumerated() { // 어떤 집에서 모든 치킨집까지의 거리를 구해둠
            let dist = abs(chicken.row - house.row) + abs(chicken.col - house.col)
            house.chickenDist.append((index, dist))
        }
        
        house.chickenDist.sort(by: { $0.1 < $1.1 })     // 어떤 집에서 각 치킨집까지의 거리를 오름차순 정렬해둠
    }
    
    pickMChickens(index: 0, count: 0, mask: 0)
    
    print(result)
}

solution()
