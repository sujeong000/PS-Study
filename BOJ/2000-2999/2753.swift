import Foundation

let year = Int(readLine() ?? "") ?? 0

if year % 4 == 0, year % 100 != 0 {
    print(1)
} else if year % 400 == 0 {
    print(1)
} else {
    print(0)
}
