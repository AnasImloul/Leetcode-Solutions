	/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
	 let arr = []
	for (let i = 1; i <= n; i++){
		if(i % 3 == 0 && i % 5 == 0){
			arr[i-1] = "FizzBuzz"
		}else if(i % 3 == 0 && i % 5 != 0){
			arr[i-1] = "Fizz"
		}else if(i % 3 != 0 && i % 5 == 0){
			arr[i-1] = "Buzz"
		}else{
			arr[i-1] = String(i)
		}
	}
	return arr  
};