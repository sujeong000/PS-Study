import Foundation

var result = ""
var deque = [Int]()

var N = Int(readLine()!)!
while N > 0 {
    let query = readLine()!.split(separator: " ")
    
    switch query[0] {
    case "push_front":
        deque.insert(Int(String(query[1]))!, at: 0)
    case "push_back":
        deque.append(Int(String(query[1]))!)
    case "pop_front":
        result.write("\(deque.isEmpty ? -1 : deque.removeFirst())\n")
    case "pop_back":
        result.write("\(deque.isEmpty ? -1 : deque.removeLast())\n")
    case "size":
        result.write("\(deque.count)\n")
    case "empty":
        result.write("\(deque.isEmpty ? 1 : 0)\n")
    case "front":
        result.write("\(deque.isEmpty ? -1 : deque.first!)\n")
    case "back":
        result.write("\(deque.isEmpty ? -1 : deque.last!)\n")
    default:
        break
    }
    
    N -= 1
}

print(result)
