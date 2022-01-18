let T = Int(readLine()!)!
let answers = readLine()!.split(separator: " ").map{ Int(String($0))! }
print(answers.reduce(0){ $0 + ($1 == T ? 1 : 0) })
