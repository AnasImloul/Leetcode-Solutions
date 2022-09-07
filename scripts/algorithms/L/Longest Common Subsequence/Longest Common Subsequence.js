// Runtime: 165 ms (Top 45.70%) | Memory: 65.3 MB (Top 23.79%)
/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
let memo
const dp=(a,b,i,j)=>{
    if(i===0||j===0)return 0;
    if(memo[i][j]!=-1)return memo[i][j];
    if(a[i-1]===b[j-1]){
        return memo[i][j]= 1+ dp(a,b,i-1,j-1);
    }else{
        return memo[i][j]=Math.max(dp(a,b,i-1,j),dp(a,b,i,j-1));
    }

}
const bottomUp=(a,b)=>{

    for(let i=1;i<=a.length;i++){
        for(let j=1;j<=b.length;j++){
            if(a[i-1]===b[j-1]){
              memo[i][j]=1+memo[i-1][j-1]
            }else{
                memo[i][j]=Math.max(memo[i-1][j],memo[i][j-1]);
            }

        }
    }

return memo[a.length][b.length]

}

var longestCommonSubsequence = function(text1, text2) {
    memo=[];
    for(let i=0;i<=text1.length;i++){
        memo[i]=[];
        for(let j=0;j<=text2.length;j++){
          if(i===0||j===0)memo[i][j]=0;
            else memo[i][j]=-1;
        }
    }
    return bottomUp(text1,text2,text1.length,text2.length);
    // return dp(text1,text2,text1.length,text2.length);
};