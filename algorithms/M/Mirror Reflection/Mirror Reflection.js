// Time complexity: O(log (min(p,q))
// Space complexity: O(1)

var mirrorReflection = function(p, q) {
	let ext = q, ref = p;
	
	while (ext % 2 == 0 && ref % 2 == 0) {
		ext /= 2;
		ref /= 2;
	}
	
	if (ext % 2 == 0 && ref % 2 == 1) return 0;
	if (ext % 2 == 1 && ref % 2 == 1) return 1;
	if (ext % 2 == 1 && ref % 2 == 0) return 2;
	
	return -1;
};
