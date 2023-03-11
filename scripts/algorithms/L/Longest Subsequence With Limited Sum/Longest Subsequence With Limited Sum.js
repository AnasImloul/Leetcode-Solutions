/**
 * @param {number[]} nums
 * @param {number[]} queries
 * @return {number[]}
 */

 // optimal solution 
 // Time O(n + m * log n)
 // Space O(n)

var answerQueries = function(nums, queries) {   
  const subs = [];
  nums.sort((a, b) => a - b);
  // prefix
  for (let i = 1; i < nums.length; i++) {
    nums[i] = nums[i] + nums[i - 1];
  }
  for (const query of queries) {
    const index = binarySearch(query, nums);
    subs.push(index);
  }

  return subs;
}

function binarySearch(target, nums) {
  let left = 0;
  let right = nums.length - 1; 

  while (left < right) {
    let middle = Math.floor((left + right) / 2);
    if (nums[middle] === target) {
      return middle + 1;
    } else if (nums[middle] > target) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return nums[left] > target ? left : left + 1;
}

 // Time O(nm + n log n)
 // Space O(n)
// var answerQueries = function(nums, queries) {   
//   const subsequences = [];
//   nums.sort((a, b) => a - b);

//   for (const querie of queries) {
//     const currSubsequence = getSubsequence(querie, nums);
//     subsequences.push(currSubsequence);
//   }
//   return subsequences;
// };

// function getSubsequence(target, nums) {
//   let currSum = 0;
//   const sub = [];

//   for (const num of nums) {
//     if (currSum + num === target) {
//       sub.push(num);
//       return sub.length;
//     } else if (currSum + num < target) {
//       currSum += num;
//       sub.push(num);
//     } else if (currSum + num > target) {
//       return sub.length;
//     }
//   }
//   return sub.length;
// }