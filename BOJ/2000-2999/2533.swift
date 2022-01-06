import Foundation

// MARK: - 노드 순서 재정의 - adjacent가 자식인지 부모인지 구분하기 위함
var adjacents = Array(repeating: [Int](), count: 1000001)
var reorderedAdjacents = Array(repeating: [Int](), count: 1000001)
var reorderedIndex = Array(repeating: 0, count: 1000001)
var visit = Array(repeating: false, count: 1000001)
var count = 1

func dfs(index: Int) {
    visit[index] = true
    reorderedIndex[index] = count
    count += 1
    
    for adjacent in adjacents[index] {
        if !visit[adjacent] {
            dfs(index: adjacent)
        }
    }
}

func reorder() {
    dfs(index: 1)       // dfs로 자식 노드 번호가 항상 부모보다 크도록 만듦
    for (index, adj) in adjacents.enumerated() {
        reorderedAdjacents[reorderedIndex[index]] = adj.map{ reorderedIndex[$0] }
    }
}


// MARK: - dp(index, isParentEarly): 부모의 얼리어답터 여부가 isParentEarly일 때, index번 노드를 루트로 하는 부분트리를 완성하는 데 필요한 얼리어답터의 수
let INF = 987654321
var cache = Array(repeating: Array(repeating: INF, count: 1000001), count: 2)

func dp(index: Int, isParentEarly: Bool) -> Int {
    // 기저 사례
    if index != 1 && reorderedAdjacents[index].count == 1 { return isParentEarly ? 0 : 1 }  // 리프 노드인 경우
    
    // 캐싱
    var ret = cache[isParentEarly ? 1 : 0][index]
    if ret != INF { return ret }
    
    var early = 1
    var noEarly = 0
    for child in reorderedAdjacents[index] {
        guard child > index else { continue }
        
        early += dp(index: child, isParentEarly: true)
        noEarly += dp(index: child, isParentEarly: false)
    }
    
    if isParentEarly {              // 부모가 얼리어답터인 경우 - 얼리어답터이지 않아도 됨
        ret = min(early, noEarly)
    } else {                        // 부모가 얼리어답터가 아닌 경우 - 무조건 얼리어답터여야만 함
        ret = early
    }
    
    cache[isParentEarly ? 1 : 0][index] = ret
    
    return ret
}


let N = Int(readLine()!)!
for _ in (0..<N-1) {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let A = input[0]
    let B = input[1]
    
    adjacents[A].append(B)
    adjacents[B].append(A)
}

reorder()

print(dp(index: 1, isParentEarly: true))
