import Foundation

var n = 0
var pick = Array(repeating: 0, count: 100_001)
var order = [Int]()
var visit = [Bool]()

func findCycle(index: Int) -> Int {
    var count = 1
    var i = index
    var check = [Int]()

    while true {
        check.append(i)
        
        guard !visit[i] else {
            check.forEach{
                visit[$0] = true
                order[$0] = 0
            }
            return count - 1
        }
        
        if order[pick[i]] != 0 {
            let ret = order[pick[i]] - 1
            
            check.forEach{
                visit[$0] = true
                order[$0] = 0
            }
            
            return ret
        }
        
        order[i] = count
        count += 1
        i = pick[i]
    }
}

func makeTeam() -> Int {
    var result = 0
    
    for i in 1...n {
        guard !visit[i] else { continue }
        
        result += findCycle(index: i)
    }
    
    return result
}

func initTestcase() {
    order = Array(repeating: 0, count: 100_001)
    visit = Array(repeating: false, count: 100_001)
}

func solution() {
    var resultString = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        initTestcase()
        
        n = Int(readLine()!)!
        pick = [0] + readLine()!.split(separator: " ").map{ Int(String($0))! }
        
        resultString.write("\(makeTeam())\n")
        
        T -= 1
    }
    
    print(resultString)
    
}

solution()
