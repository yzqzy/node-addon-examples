import { math } from '../lib/binding.cjs'

// Testing with integer numbers
console.log(math.add(2, 3))
console.log(math.subtract(5, 2))
console.log(math.multiply(2, 4))
console.log(math.divide(10, 2))

// Testing with float numbers
console.log(math.add(2.5, 3.5))
console.log(math.subtract(5.5, 2.5))
console.log(math.multiply(2.5, 4.5))
console.log(math.divide(10.5, 2.5))

// Testing with negative numbers
console.log(math.add(-2, -3))
console.log(math.subtract(-5, -2))
console.log(math.multiply(-2, -4))
console.log(math.divide(-10, -2))

// Testing witn failing cases
console.log(math.add('2', 3))
console.log(math.subtract(5, '2'))
