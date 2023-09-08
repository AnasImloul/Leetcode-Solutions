// Runtime: 84 ms (Top 91.0%) | Memory: 48.07 MB (Top 39.8%)

var addToArrayForm = function(num, k) {

    let i = num.length - 1;
    let res = [];
    while(i >= 0 || k >0 ){
		//this is the general check : taking the last elemnt and adding it with the k value then take the carry(if any to the next iteration) 
        if(i >= 0){
            res.push((num[i] + k) % 10);
            k = Math.trunc((num[i] + k) / 10);
			i--;	
        } 
		//this else block will handle the edge case when we need to increase the array length based on k value
		else {
            res.push( k % 10);
            k = Math.trunc(k / 10);
        }
    }
    return res.reverse();  
}
//  we can devide this question in two parts based on the fact that do we need extra space for the carry see e.g 2
/**
 * e.g 1: - [1,2,6,3] & k = 516 || No Extra space needed
 * let i = 3 (num.length - 1);
 * step 1: (inside first if block cz 3 >= 0)
 * 			num[3] + 516 = 519;
 * 			519 % 10 = 9;
 * 			res = [9];
 * 			k = (519/10) = 51;
 * 			i-- ==> 2;
 * step 2: (inside first if block cz 2 >= 0)
 * 			num[2] + 51 = 57;
 * 			57 % 10 = 7;
 * 			res = [9, 7];
 * 			k = (57/10) = 5;
 * 			i-- ==> 1;
 * step 3: (inside first if block cz 1 >= 0)
 * 			num[1] + 5 = 7;
 * 			7 % 10 = 7;
 * 			res = [9, 7, 7];
 * 			k = (7/10) = 0;
 * 			i-- ==> 0;
 * step 4: (inside first if block cz 0 >= 0)
 * 			num[0] + 0 = 1;
 * 			1 % 10 = 1;
 * 			res = [9, 7, 7, 1];
 * 			k = (1/10) = 0;
 * 			i-- ==> -1; (first if consition will be false it will     * never going to the 2nd if bcz k is already 0)
 * in this case we need to reverse this array to get the result 
 * Answer - [9, 7, 7, 1].reverse() => [1, 7, 7, 9]
 */

/**
 * e.g 1: - [9, 9, 9] & k = 1 || Extra space needed
 * let i = 2 (num.length - 1);
 * step 1: (inside first if block cz 2 >= 0)
 * 			num[2] + 1 = 10;
 * 			10 % 10 = 0;
 * 			res = [0];
 * 			k = (10/10) = 1;
 * 			i-- ==> 1;
 * step 2: (inside first if block cz 1 >= 0)
 * 			num[1] + 1 = 10;
 * 			10 % 10 = 0;
 * 			res = [0, 0];
 * 			k = (10/10) = 1;
 * 			i-- ==> 0;
 * step 3: (inside first if block cz 0 >= 0)
 * 			num[0] + 1 = 10;
 * 			10 % 10 = 0;
 * 			res = [0, 0, 0];
 * 			k = (10/10) = 1;
 * 			i-- ==> -1; (loop will break)
 * step 4: (inside SECOND if block cz k is still 1 >= 0 and i = -1)
 * 			(k value is 1) 1 % 10 = 1;
 * 			res = [0, 0, 0, 1];
 * 			k = (1/10) = 0; ( k value finally 0 NO MORE ELEMENTS TO *ADD)
 * Answer - res.reverse() => [1, 0, 0, 0]
 */
