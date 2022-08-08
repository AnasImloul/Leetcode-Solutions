var totalFruit = function(fruits) {
    let myFruits = {};
    let n = fruits.length;
    let windowStart = 0;
    let ans = -Number.MAX_VALUE;
    
    for(let windowEnd = 0; windowEnd < n; windowEnd++) {
        let fruit = fruits[windowEnd];
        
        if(fruit in myFruits) {
            myFruits[fruit]++;
        }
        else {
            myFruits[fruit] = 1;
        }
        
        while(Object.keys(myFruits).length > 2) {
            let throwOut = fruits[windowStart];
            myFruits[throwOut]--;
            if(myFruits[throwOut] == 0) {
                delete myFruits[throwOut];
            }
            windowStart++;
        }
        ans = Math.max(ans, windowEnd - windowStart + 1);
    }
    return ans;
};

