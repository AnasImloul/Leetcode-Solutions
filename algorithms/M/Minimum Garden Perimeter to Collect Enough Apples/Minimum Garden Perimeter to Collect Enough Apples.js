/**
 * @param {number} neededApples
 * @return {number}
 */
var minimumPerimeter = function(neededApples) {
    
    
    let start = 2, n = 1, dp = [0];
    
    while(true){
        let cur = start, res = dp[n-1];
		
		//Add the X and Y axis apples multiplied with 4 
        res += (cur + cur - n)*4;
        
		// Add the interior apples using and AP formula of  ( n - 1 ) / 2 * (2a + ( n-1 ) * d ) & multiplying it by 8 as count is 8  
        res += ( ((n-1)/2) *  ( ( 2 * (cur - 1) ) + ( (n-2) * -1 ) )  ) * 8
        
		//Setting the result to DP
        dp[n] = res;
		
		//If current state is greater than or equal to needed then return the perimeter
        if(neededApples <= res) return 8*n;
        n++;
        start +=2;
        
    }
};
