const { hello } = require('bindings')('hello')
const callback = require('bindings')('callback')
const math = require('bindings')('math')

exports.hello = hello
exports.math = math
exports.callback = callback
