import Foundation

let input = readLine() ?? ""
let inputArr = input.split(separator: " ")
let H = Int(inputArr[0]) ?? 0
let M = Int(inputArr[1]) ?? 0

let dayToMin = 60 * 24

let newAlarm = (dayToMin + H * 60 + M - 45) % dayToMin
let newH = newAlarm / 60
let newM = newAlarm % 60

print("\(newH) \(newM)")
