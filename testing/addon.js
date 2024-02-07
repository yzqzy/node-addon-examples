import { addon } from '../lib/binding.cjs'

console.log(addon.hello()) // prints hello world
console.log(addon.increment()) // prints 43
console.log(addon.increment()) // prints 44
console.log(addon.increment()) // prints 45
console.log(addon.decrement()) // prints 44
console.log(addon.subObject.decrement()) // prints 43
