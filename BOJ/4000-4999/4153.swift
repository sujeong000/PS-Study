import Foundation

var result = ""

while true {
    var triangle = readLine()!.split(separator: " ").map{ Int(String($0))! }
    
    if triangle == [0, 0, 0] { break }
    
    triangle.sort()
    triangle = triangle.map{ $0 * $0 }
    
    result.write( triangle[2] == triangle[0] + triangle[1] ? "right\n" : "wrong\n")
}

print(result)
