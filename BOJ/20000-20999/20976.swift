let ABC = readLine()!.split(separator: " ").map{ Int(String($0))! }
print(ABC.sorted()[1])
