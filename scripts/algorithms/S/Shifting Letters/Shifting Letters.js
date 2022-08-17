// 848. Shifting Letters
var shiftingLetters = function(s, shifts) {
	let res = '', i = shifts.length;
	shifts.push(0);
	while (--i >= 0) {
		shifts[i] += shifts[i+1];
		res = String.fromCharCode((s.charCodeAt(i) - 97 + shifts[i]) % 26 + 97) + res;
	}
	return res;
};
