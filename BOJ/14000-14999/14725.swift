import Foundation

class Room: CustomStringConvertible {
    var food: String
    var childRooms = [String: Room]()
    var depth: Int
    
    init(food: String, depth: Int) {
        self.food = food
        self.depth = depth
    }
    
    func addFoodInfo(depth: Int, foodList: [String]) {
        guard depth < foodList.count else { return }
        
        let currentFood = foodList[depth]
        if self.childRooms[currentFood] == nil {
            self.childRooms[currentFood] = Room(food: currentFood, depth: depth)
        }
        
        self.childRooms[currentFood]?.addFoodInfo(depth: depth + 1, foodList: foodList)
    }
    
    var description: String {
        var ret = ""
        
        if self.depth >= 0 {
            (0..<self.depth).forEach{ _ in ret.write("--") }
            ret += self.food
            ret += "\n"
        }
        
        self.childRooms.keys.sorted().forEach{
            ret += self.childRooms[$0]!.description
        }
        
        return ret
    }
}

var entrance = Room(food: "", depth: -1)

let N = Int(readLine()!)!
for _ in 0..<N {
    let input = Array(readLine()!.split(separator: " ").map{ String($0) }.dropFirst())
    entrance.addFoodInfo(depth: 0, foodList: input)
}

print(entrance)
