var maxScore = function(nums) {
    
    function gcd(a, b) {
        if(!b) return a;
        return gcd(b, a % b);
    }
    
    const memo = new Map();
    
    function recurse(arr, num1, op) {
        if(!arr.length) return 0;
        
        const key = arr.join() + num1;
        if(memo.has(key)) return memo.get(key);
        
        let max = 0;
        
        for(let i = 0; i < arr.length; i++) {
            const nextArr = [...arr.slice(0, i), ...arr.slice(i+1)];
            
            if(num1) {
                const currGCD = gcd(num1, arr[i]);
                const rest = recurse(nextArr, null, op+1);
                max = Math.max(max, ((op * currGCD) + rest));
            } else {
                const rest = recurse(nextArr, arr[i], op);
                max = Math.max(max, rest);
            }
        }
        memo.set(key, max);
        return max;
    }
    return recurse(nums, null, 1);
};
