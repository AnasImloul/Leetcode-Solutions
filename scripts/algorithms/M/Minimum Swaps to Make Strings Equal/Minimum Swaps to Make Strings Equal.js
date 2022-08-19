// Runtime: 73 ms (Top 87.50%) | Memory: 42.7 MB (Top 43.75%)

var minimumSwap = function(s1, s2) {
   let count1 = 0;
    let count2 = 0;
   for(let i in s1) {
       if(s1[i] === "x" && s2[i] === "y") {
           count1++
       }
        if(s1[i] === "y" && s2[i] === "x") {
           count2++
       }
   }

    let ans = Math.floor(count1 / 2) + Math.floor(count2 / 2);
    if(count1 % 2 === 0 && count2 % 2 === 0){
        return ans
    }
    else if(count1 % 2 !== 0 && count2 % 2 !== 0){
        return ans + 2;
    }
    else {
        return -1;
    }
};