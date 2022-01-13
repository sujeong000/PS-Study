import Foundation

struct Stack {
    var stack = [Character]()

    var isEmpty: Bool {
        return stack.isEmpty
    }
    
    mutating func pop() -> Character {
        return stack.popLast()!
    }
    
    mutating func push(_ char: Character) {
        stack.append(char)
    }
}

var result = ""

while true {
    let input = readLine()!
    if input == "." { break }
    
    var stack = Stack()
    var valanced = true
    
    for char in input {
        switch char {
        case "[", "(":
            stack.push(char)
        case "]":
            if stack.isEmpty || stack.pop() != "[" {
                valanced = false
                break
            }
        case ")":
            if stack.isEmpty || stack.pop() != "(" {
                valanced = false
                break
            }
        default:
            continue
        }
    }
    
    if !stack.isEmpty { valanced = false }
    
    result.write("\(valanced ? "yes" : "no")\n")
}

print(result)
