// Runtime: 67 ms (Top 28.57%) | Memory: 45.00 MB (Top 71.43%)

/** https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
 * @param {string} street
 * @return {number}
 */
var minimumBuckets = function(street) {
  // Greedy algorithm, walk through every index in `street` and calculate bucket needed
  // Observation, assuming we can capture rain from every houses, the maximum bucket we need is equal to the 'H' found in `street`, we then just need to find where a bucket could capture rain from 2 houses
  
  // For keep track of the bucket needed, we use `count`
  // For keep track of a space that can be shared by 2 houses, we use `allow`
  // For keep track of house in a row, we use `inARow`
  let count = 0;
  let allow = 0;
  let inARow = 0;
  
  for (let i = 0; i < street.length; i++) {
    // Handle cases where there is no space to put bucket for at least 1 house
    // There are few scenarios:
    // - there are more than 3 houses in a row, middle house doesn't have space for bucket
    // - there is only 1 house in that street and no space
    // - there are 2 houses in a row at the beginning of the street or at the end of the street
    if (inARow >= 3 ||
        (street.length === 1 && street[0] === 'H') ||
        (street.length >= 2 && street[0] === 'H' && street[1] === 'H') ||
        (street.length >= 2 && street[street.length - 1] === 'H' && street[street.length - 2] === 'H')) {
      return -1;
    }
    
    // Encounter a house
    if (street[i] === 'H') {
      // Increment the `inARow`
      inARow += 1;
      
      // There is a space that will capture rain from 2 houses, we don't count house at this index because bucket placed previously can be used
      if (allow === 1) {
        // Reset the `allow`
        allow = 0;
        continue;
      }
      
      // Count a bucket
      count += 1;
      
      // Handle the case where `i + 1` is a space and we can put the bucket which will 'allow' it to capture the house at `i + 2` if there `i + 2` is a house
      // If `i + 2` is not a house, we will reset the `allow` which is already handle
      if (i < street.length && street[i+1] === '.') {
        allow += 1;
      }
    }
    // Encounter a space to put bucket
    else {
      // We reset the `inARow` count
      inARow = 0;
      
      // If the previous index is a space, reset `allow` because placing bucket in current index will not benefits more than 2 houses
      if (i >= 0 && street[i-1] === '.') {
        allow = 0;
      }
    }
  }
  
  return count;
};
