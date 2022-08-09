// 77 ms, faster than 97.56%
// 45 MB, less than 87.81%
var largeGroupPositions = function(s) {
	let re = /(.)\1{2,}/g;
	let ans = [];
	while ((rslt = re.exec(s)) !== null) {
		ans.push([rslt.index, rslt.index + rslt[0].length-1]);
	}
	return ans;
};
