import { idle } from '../lib/binding.cjs'

idle.startIdle(100)

try {
  idle.startIdle(1)
} catch (e) {
  console.error(e)
}

let times = 100
function tick() {
  times--
  console.log(`还剩 ${times} 次 tick。`)

  if (times === 0) return

  setImmediate(tick)
}

setImmediate(tick)
