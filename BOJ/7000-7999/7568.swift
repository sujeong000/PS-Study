import Foundation

struct Person: Comparable {
    let height: Int
    let weight: Int
    var rank = 0

    static func < (lhs: Person, rhs: Person) -> Bool {
        lhs.weight < rhs.weight && lhs.height < rhs.height
    }
}

var people = [Person]()
let N = Int(readLine()!)!

for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    people.append(Person(height: input[1], weight: input[0]))
}

for i in 0..<N {
    people[i].rank = people.reduce(1){ $1 > people[i] ? $0 + 1 : $0 }
}

print(people.reduce(""){ $0 + "\($1.rank) "})
