// Runtime: 49 ms (Top 90.74%) | Memory: 44.20 MB (Top 33.33%)

var maximumPopulation = function(logs) {
    const count = new Array(101).fill(0);
    
    for (const [birth, death] of logs) {
        count[birth - 1950]++;
        count[death - 1950]--;
    }
    
    let max = 0;
    
    for (let i = 1; i < 101; i++) {
        count[i] += count[i - 1];
        
        if (count[i] > count[max]) max = i;
     }
    
     return 1950 + max;
 };
