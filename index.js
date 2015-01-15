'use strict';

var addon = require('./build/Release/addon');


module.exports = sleep;
function sleep(milliseconds) {
  var start = Date.now();
  if (milliseconds !== milliseconds | 0) {
    throw new TypeError('sleep only accepts an integer number of milliseconds');
  }
  milliseconds = milliseconds | 0;
  if (milliseconds < 0) {
    throw new TypeError('sleep only accepts a positive number of milliseconds');
  }
  var result = addon.sleep(milliseconds);
  var end = Date.now();
  return end - start;
}
