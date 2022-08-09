function reverse(s){
    return s.split("").reverse().join("");
}

function solve(s,index) {    
    let ans = "";   
    let j = index;
    while(j<s.length)
    {   
        if(s[j] == '(')
        {
            let store = solve(s,j+1);
            ans += store.ans;
            j = store.j;
        }
        else if(s[j] == ')')
            return {ans : reverse(ans),j};          
        else
            ans+=s[j];            
        j++;
    }    
        
    return ans;
}

var reverseParentheses = function(s) {
    return solve(s,0);
};
