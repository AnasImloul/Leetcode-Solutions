var repeatedNTimes = function(nums) {

//   loop through the array and then as we go over every num we filter that number and get the length. If the length is equal to 1 that is not the element so we continue if its not equal to one its the element we want and we just return that element. 

  for (let num of nums) {
    let len = nums.filter(element => element === num).length
    if (len == 1) continue;
    else return num
  }

};
