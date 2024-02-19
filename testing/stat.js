import { stat } from '../lib/binding.cjs'

const str =
  'Lorem, ipsum dolor sit amet consectetur adipisicing elit. Illo velit, quibusdam cupiditate deserunt tempore nisi voluptas perferendis hic exercitationem quasi voluptatibus! Nihil itaque ex aspernatur ipsam laboriosam dolorum, illum sunt.'

console.log('-------------------------')
console.log(stat.stat01(str))
console.log(stat.stat02(str))
console.log(stat.stat03(str))
console.log('-------------------------')
