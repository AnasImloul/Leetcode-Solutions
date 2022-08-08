// C++ Code
class Solution {
public:
    string generateTheString(int n) {
        string res = "";
        if (n%2 == 0)
        {
            res += 'a';
            n -= 1;
        }
        for (int i=0;i < n;i++)
            res += 'k';
        return res;
    }
};


// JavaScript Code
var generateTheString = function(n) {
    let ans = [];
    let state = n % 2 === 0 ? true : false;
    
    if(!state){
        for(let i=0;i<n;i++){
            ans.push('a');
        }
    }else{
        for(let i=0;i<n-1;i++){
            ans.push('a');
        }
        ans.push('k');
    }
   
    return ans.join('');
};

