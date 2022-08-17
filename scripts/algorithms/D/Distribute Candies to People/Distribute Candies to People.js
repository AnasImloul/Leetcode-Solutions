var distributeCandies = function(candies, num_people) {
    
    let i = 1, j=0;
    const result = new Array(num_people).fill(0);
    while(candies >0){
        result[j] += i;
        candies -= i;
        if(candies < 0){
            result[j] += candies;
            break;
        }
        j++;
        if(j === num_people)
            j=0;
        
        i++;
    }
    return result;
};