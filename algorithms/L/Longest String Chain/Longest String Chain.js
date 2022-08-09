/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) {
    const len = words.length;
    words.sort((a, b)=> a.length - b.length );
    // dp[i] meaning: the longest string chain length ending with sorted words[i]
    let dp= new Array(words.length).fill(1);

// verify if a is a predecessor of word b
    const isValid=(a,b)=>{
        if(b.length - a.length !==1){
            return false;
        }
        let lenOfA = a.length;
        let lenOfB = b.length;
        let i=0;
        let j=0;
        while(i<lenOfA && j<lenOfB){
            if(a.charAt(i) === b.charAt(j)){
                i++;
                j++;
            }
            else{
                j++
            }
        }
		// if the last char is diff, then i = j
		// if a char is different in the middle, then i = j - 1
        if(i=== j-1 || i===j){
            return true;
        }
        else{
            return false;
        }
    }
    
    for(let i=0; i< len; i++){
        for(let j=i+1; j< len; j++){
            if(isValid(words[i],words[j])){
                dp[j] = Math.max(dp[j], dp[i]+1);
            }
        }
    }
    let max = dp[0];
    for(let i = 0;i<dp.length; i++){
        max = Math.max(max, dp[i]);
    }
    return max
    
    
};
