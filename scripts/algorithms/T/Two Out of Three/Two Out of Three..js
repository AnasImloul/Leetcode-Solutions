// Runtime: 79 ms (Top 11.11%) | Memory: 46.80 MB (Top 14.81%)

// time O(n) Space O(n)
var twoOutOfThree = function(nums1, nums2, nums3) {
    const array = [...new Set(nums1), ...new Set(nums2), ...new Set(nums3)]
    const map = {}
    const result = []
    
    for(const number of array) {
        if(map[number]) {
            map[number] += 1
        } else {
            map[number] = 1
        }
    }
    
    for(const key in map) {
        if(map[key] >= 2) {
            result.push(key)
        }
    }
    
  return result  
};
