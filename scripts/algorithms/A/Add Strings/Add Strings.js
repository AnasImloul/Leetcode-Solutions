/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let i = num1.length - 1;
    let j = num2.length - 1;
    let sum = 0, carry = 0, x, y;
    let result = "";
    while(i>=0 || j>=0){
        x = i < 0 ? 0 : num1.charAt(i) - "0";
        y = j < 0 ? 0 : num2.charAt(j) - "0";
        sum = (x + y + carry) % 10;
        carry = Math.floor((x + y + carry) /10);
        result =  sum + result;
        
        i--;
        j--;
    }
    
    if(carry!=0){
        result =  carry + result;
    }
    
    return result;
   
};