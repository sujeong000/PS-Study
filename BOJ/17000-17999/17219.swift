import Foundation

func solution() -> String {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    let N = input[0]
    let M = input[1]
    
    var dict = [String:String]()
    for _ in 0..<N {
        let siteAndPw = readLine()!.split(separator: " ").map{ String($0) }
        let site = siteAndPw[0]
        let pw = siteAndPw[1]
        
        dict[site] = pw
    }
    
    var result = ""
    
    for _ in 0..<M {
        let site = readLine()!
        result.write(dict[site]!+"\n")
    }
    
    return result
}


print(solution())
