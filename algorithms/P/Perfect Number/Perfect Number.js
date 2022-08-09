	/**
 * @param {number} num
 * @return {boolean}
 */
var checkPerfectNumber = function(num) {
	let total = 0

	for(let i = 1 ; i < num;i++){
		if(num % i == 0){
			total += i
		}
	}
	return total == num ? true : false
};