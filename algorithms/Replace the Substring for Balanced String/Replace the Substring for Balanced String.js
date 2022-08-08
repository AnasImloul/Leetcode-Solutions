var balancedString = function(s) {
    
    let output = Infinity;
    
    let map = {"Q":0, "W":0, "E":0, "R":0};
    
    for(let letter of s){
        map[letter]++;
    }
    
    let valueGoal = s.length / 4
        
    let remainder = 0;
    
    let count = 4;
    
    for(let [key, val] of Object.entries(map)){
        
        if(val > valueGoal){
            remainder = remainder + (val - valueGoal); 
        }
        
        if(val === valueGoal || val < valueGoal){
            map[key] = -Infinity;
            count--;
        }
    }
    
    if(remainder === 0){
        return 0;
    }
    
    let left = 0;
    
    let right = 0;
    
    while(right < s.length){

        if(map[s[right]] !== -Infinity){
            
            map[s[right]]--;

            if(map[s[right]] === valueGoal){
                count--;
            }
            
        }
        
        while(count === 0){

            output = Math.min(output, right - left + 1);
            
            if(map[s[left]] !== -Infinity){
                
                map[s[left]]++;
                
                if(map[s[left]] > valueGoal){
                    count++;
                }
                
            }
            left++
        }

        right++;
    }

    return output;
};
