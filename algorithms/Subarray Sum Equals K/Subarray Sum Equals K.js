	var subarraySum = function(nums, k) {
		const obj = {};
		let res = 0;
		let sum = 0;

		for (let i = 0; i < nums.length; i++) {

			sum += nums[i];
			if (sum == k) res++;

			if (obj[sum - k]) res += obj[sum - k];

			obj[sum] ? obj[sum] += 1 : obj[sum] = 1;
		}
		return res;
	};