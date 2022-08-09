/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
	var sol = [];
	var found = 0;
	for(let i = 0; i < nums.length; i ++) {
		for(let j = i + 1; j < nums.length; j ++) {
			if(nums[i] + nums[j] === target) {
				sol.push(i, j);
				found = 1;
				break;
			}
		}
		if(found == 1) return sol;
	}
	return sol;
};