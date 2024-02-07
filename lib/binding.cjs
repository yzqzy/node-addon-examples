const { hello } = require('bindings')('hello')
const callback = require('bindings')('callback')
const math = require('bindings')('math')
const addon = require('bindings')('addon')

exports.hello = hello
exports.math = math
exports.callback = callback
exports.addon = addon
