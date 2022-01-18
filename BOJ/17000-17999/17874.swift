let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let n = input[0]
let h = input[1]
let v = input[2]

print(4 * max(h*v, (n-h)*v, h*(n-v), (n-h)*(n-v)))
