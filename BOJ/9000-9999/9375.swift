import Foundation

func solution() -> String {
    var result = ""
    var T = Int(readLine()!)!
    
    while T > 0 {
        var dict = [String:Int]()
        
        let N = Int(readLine()!)!
        for _ in 0..<N {
            let input = readLine()!.split(separator: " ").map{ String($0) }
            let name = input[0]
            let type = input[1]
            
            if let count = dict[type] {
                dict[type] = count + 1
            } else {
                dict[type] = 1
            }
        }
        
        var numberOfCases: Int64 = 1
        for count in dict.values {
            numberOfCases *= Int64(count + 1)
        }
        
        result.write("\(numberOfCases - 1)\n")
        
        T -= 1
    }
    
    return result
}

print(solution())
