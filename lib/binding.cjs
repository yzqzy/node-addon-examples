const { hello } = require('bindings')('hello')
const math = require('bindings')('math')

exports.hello = hello
exports.math = math
