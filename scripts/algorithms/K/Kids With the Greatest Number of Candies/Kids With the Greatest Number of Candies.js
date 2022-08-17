var kidsWithCandies = function(candies, extraCandies) {
    //First find out maximum number in array:->
    let max=0, res=[]; 
    for(let i=0; i<candies.length; i++){
        if(candies[i]>max) max=candies[i];
    }
    console.log(max)
    
    /*Now add extraCandies with every element in array and checks if
	that sum is equals to or greater than max and return true and false otherwise; */
    
    for(let i=0; i<candies.length; i++){
        let temp=candies[i]+extraCandies;
        if(temp>=max) res.push(true);
        else res.push(false);
    }
    return res;
};
