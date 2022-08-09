/**
 * @param {number[]} arr
 * @return {number}
 */
 
var findLucky = function(arr) {
	let obj = {};
	arr.map((num) => {
		obj[num] = obj[num] + 1 || 1;
	});

	let answer = -1;
	for (let key in obj) {
		if (Number(key) === obj[key]) answer = Math.max(answer, Number(key));
	}

	return answer;
};
