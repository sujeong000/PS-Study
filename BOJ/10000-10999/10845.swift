import Foundation

let N = Int(readLine()!)!

var queue = [String]()

for _ in 0..<N {
    let command = readLine()!.components(separatedBy: " ")
    
    switch command[0] {
    case "push":
        queue.append(command[1])
    case "pop":
        if queue.isEmpty {
            print(-1)
        } else {
            print(queue[0])
            queue.removeFirst()
        }
    case "size":
        print(queue.count)
    case "empty":
        print(queue.isEmpty ? 1 : 0)
    case "front":
        print(queue.first ?? -1)
    case "back":
        print(queue.last ?? -1)
    default:
        break
    }
}
