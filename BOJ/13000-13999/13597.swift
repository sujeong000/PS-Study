let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
print(max(input[0], input[1]))
