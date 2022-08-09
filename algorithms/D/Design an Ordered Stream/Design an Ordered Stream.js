/**
 * @param {number} n
 */
var OrderedStream = function(n) {
  // initialize array
  this.arr = [];
  // start pointer at index of 0
  this.p = 0;
  //set array to have length of n
  this.arr.length = n;
};

/** 
 * @param {number} idKey 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function(idKey, value) {
  // push the value into array at index of idKey
  this.arr[idKey - 1] = value;
  // initialize result array
  let result = [];
  
  // while the pointer has a value, push that value into the result array and advance the pointer
  while (this.arr[this.p]) {
    result.push(this.arr[this.p]);
    this.p++;
  }
  // return the result array which will either be empty if the pointer was null, or will have the chunks pushed into it
  return result;
};

/** 
 * Your OrderedStream object will be instantiated and called as such:
 * var obj = new OrderedStream(n)
 * var param_1 = obj.insert(idKey,value)
 */
