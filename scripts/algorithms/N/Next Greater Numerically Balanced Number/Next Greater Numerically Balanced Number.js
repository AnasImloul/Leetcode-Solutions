/**
 * @param {number} n
 * @return {number}
 */
var nextBeautifulNumber = function(n) {
    //1224444 is next minimum balanced number after 10^6
    for(let i=n+1; i<=1224444;i++){//Sequency check each number from n+1 to 1224444
        if(isNumericallyBalanced(i)){
            return i;//Return the number if is a balanced number
        }
    }
    function isNumericallyBalanced(n){
        let map={},d,nStr=n.toString();
        while(n>0){//Create a map of digits with frequency
            d = n%10;
            if(d>nStr.length){//If we have found a digit greater than the lenght of the number like 227333, here when we see 7, we can return false
                return false;
            }
            if(map[d]===undefined){
                map[d]=1;
            }else{
                map[d]++;
                if(map[d]>d){//If a digit has frequency more than its value, for example 22333344, here when we see fourth 3 than we can return false
                    return false;
                }
            }
            n = Math.floor(n/10);
        }
        for(let key in map){//Check if frequency is equal to the digit
            if(map[key]!==parseInt(key)){
                return false;
            }
        }
        return true;
    }
};
