// The Swift Programming Language
// https://docs.swift.org/swift-book

print("Hello, world!")


func filerNum( numbers : [Int])-> [Int]{
    return numbers.filter { $0 % 2 == 0 }
}

func sq( _ n : Int) -> Int {
    return n*n
}
print(sq(5))
print(filerNum(numbers: [1,11,2,3,4,5,6]))