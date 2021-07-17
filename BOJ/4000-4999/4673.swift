import Foundation

func d(n: Int) -> Int {
    let sum = String(n).reduce(0) {$0 + Int(String($1))!}
    
    return n + sum
}

var set: Set<Int> = []
for i in 1...10000{
    set.insert(i)
}

for i in 1..<10000{
    set.remove(d(n: i))
}

for num in set.sorted(){
    print(num)
}
