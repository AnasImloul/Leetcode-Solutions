// Runtime: 84 ms (Top 86.97%) | Memory: 44.9 MB (Top 98.14%)
// Please upvote if you like the solution. Thanks

var licenseKeyFormatting = function(s, k) {
 let str=s.replace(/[^A-Za-z0-9]/g,"").toUpperCase()
    let ans=""
    let i=str.length;
    while(i>0){
        ans="-"+str.substring(i-k,i)+ans // we are taking k characters from the end of string and adding it to answer
        i=i-k
    }
    return (ans.substring(1)) // removing the "-" which is present in the start of ans
};