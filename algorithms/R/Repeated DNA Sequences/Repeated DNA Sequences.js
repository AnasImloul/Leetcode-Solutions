// 187. Repeated DNA Sequences
var findRepeatedDnaSequences = function(s) {
    let map = {};
	let res = [];
	for (let i = 0; i <= s.length-10; i++) {
		let s10 = s.substring(i, i+10);
		map[s10] = (map[s10] || 0) + 1;
		if (map[s10] === 2) res.push(s10);
	}
	return res;
};
