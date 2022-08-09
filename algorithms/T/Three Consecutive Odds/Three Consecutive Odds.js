var threeConsecutiveOdds = function(arr) {
	let c = 0;

	for(let val of arr){
		if(val % 2 === 1){
			c++;
			if(c === 3) {
				return true;
			}
		} else {
			c=0;
		}
	}

	return false;
};