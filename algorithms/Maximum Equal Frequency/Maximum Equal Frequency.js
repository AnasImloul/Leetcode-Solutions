// *NOTE: ternary operator is to handle if key is undefined since javascript doesn't have a default object value

var maxEqualFreq = function(nums) {
  // create cache to count the frequency of each number
  const numCnt = {};
  
  // create cache to count the number of 'number of frequencies'
  // e.g. [1,2,3,2,4,4,3,1,5]
  //        {  1: 1           1 number appeared with a frequency of 1
  //           2: 3   }      3 numbers appeared with a frequency of 2
  const cntFreq = {};
  
  // holds the maximum frequency a number has appeared
  let maxFreq = 0;
  
  // holds solution
  let result = 0;
  
  // iterate through numbers
  for (let i = 0; i < nums.length; i++) {
      // get current number;
      const num = nums[i];
	  
	  // subtract one from the current frequency of the current number
      cntFreq[numCnt[num]] = cntFreq[numCnt[num]] ? cntFreq[numCnt[num]] - 1 : -1;
	  
	  // increase the count of the current number
      numCnt[num] = numCnt[num] ? numCnt[num] + 1 : 1;
	  
	  // add one to the current frequency of the current number
      cntFreq[numCnt[num]] = cntFreq[numCnt[num]] ? cntFreq[numCnt[num]] + 1 : 1;
	  
	  // if the current frequency is more than the max frequency update the max frequency
      if (maxFreq < numCnt[num]) maxFreq = numCnt[num];
	  
	  // if max frequency is 1 or
	  // if the max frequency multiplied by the number of values with that frequency equals the current index or
	  // if the result of the 1 less than the max frequency equals to the current index
	  // update result
      if (maxFreq === 1 || maxFreq * cntFreq[maxFreq] === i || (maxFreq - 1) * (cntFreq[maxFreq - 1] + 1) === i) {
          result = i + 1;
      }
  }
  return result;
};
