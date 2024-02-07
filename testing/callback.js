import { callback } from '../lib/binding.cjs'

callback(res => {
  console.log(res)
})

callback(123)
