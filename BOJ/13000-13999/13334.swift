import Foundation

let n = Int(readLine()!)!
let lines = (0..<n).map{ _ in readLine()!.split(separator: " ").map{ Int(String($0))! } }
let d = Int(readLine()!)!



let points = lines
            .enumerated()
            .map{ [($1[0], $0), ($1[1], $0)] }  // 총 2n개의 포인트를 [(좌표, 사람 번호)] 형태로 저장한 뒤
            .flatMap{ $0 }                      // 2차원 -> 1차원
            .sorted(by: { $0.0 < $1.0 })        // 스위핑하기 위해 좌표를 기준으로 오름차순 정렬

var startIndex = 0                                  // 철로의 시작점
var includedCount = [Int](repeating: 0, count: n)   // 철로에 포함된 i번째 사람의 집 or 사무실 개수
var maxCount = 0
var count = 0

for i in (0..<2*n) {                                    // 철로의 끝점을 하나씩 우측으로 옮기면서 포함되는 사람의 수를 구함
    let endPoint = points[i].0
    
    while endPoint - points[startIndex].0 > d {         // 철로의 길이가 d이하가 될 때까지 시작점을 하나씩 우측으로 옮김
        let person = points[startIndex].1               // 시작점이 위치한 곳의 집/사무실의 주인 번호
        if includedCount[person] == 2 { count -= 1 }    // 철로에 포함됐던 사람인 경우 이제 제외되므로 카운트 다운
        includedCount[person] -= 1                      // 시작점이 우측으로 이동할 것이므로 person번째 사람의 집/사무실은 이제 철로 범위를 벗어남
        startIndex += 1                                 // 시작점 우측으로 한 칸 이동
    }
    
    let person = points[i].1                        // 끝점이 위치한 곳의 집/사무실 주인 번호
    includedCount[person] += 1                      // 끝점이 우측으로 이동했으므로 person번째 사람의 집/사무실은 이제 철로 범위에 들어옴
    if includedCount[person] == 2 { count += 1 }    // person번째 사람의 집과 사무실이 모두 포함됐으면 카운트 업
    
    maxCount = max(maxCount, count)                 // 최대값 갱신
}

print(maxCount)
