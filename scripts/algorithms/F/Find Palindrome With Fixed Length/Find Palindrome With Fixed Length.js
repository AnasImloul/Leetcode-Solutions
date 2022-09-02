// Runtime: 513 ms (Top 19.44%) | Memory: 80.3 MB (Top 30.56%)
var kthPalindrome = function(queries, intLength) {
    let output=[];
    // 1. We use FIRST 2 digits to create palindromes: Math.floor((3+1)/2)=2
    let digit=Math.floor((intLength+1)/2);

    for(let i=0; i<queries.length; i++){
        // 2A. Get Nth 2-digits numbers: 10*(2-1)-1+[5,98]=[14,107]
        let helper=10**(digit-1)-1+queries[i];
        // 2B. Digits checking: 107>=100, which is INVALID
        if(helper>=10**digit){output.push(-1)}
        else{
            let m=intLength-digit;
            // 3A. We still need m digits for REFLECTION: 14=>["1","4"]=>"41"
            let add=helper.toString().substr(0, m).split("").reverse().join("");
            // 3B. Multiply 10**m for reversed digits: 14=>1400=>1441
            helper=helper*10**m+add*1;
            output.push(helper);
        }
    }
    return output; // [1441,-1]
};