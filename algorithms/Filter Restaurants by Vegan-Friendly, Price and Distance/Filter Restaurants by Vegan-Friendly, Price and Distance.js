var filterRestaurants = function(restaurants, veganFriendly, maxPrice, maxDistance) {
    let result = []
    // veganFriendly filter
    if(veganFriendly === 1){
       restaurants = restaurants.filter(restaurant=> restaurant[2] === 1) 
    }
    
    //max price
    restaurants = restaurants.filter(restaurant=>restaurant[3]<=maxPrice)
    
    // max distance
    restaurants = restaurants.filter(restaurant=>restaurant[4]<=maxDistance)
    
    restaurants.sort((a,b)=>b[1]-a[1])
    
    let tempArr = []
    for(let i=0; i<restaurants.length;i++){
        if(restaurants[i+1] && restaurants[i][1]===restaurants[i+1][1] ){
            tempArr.push(restaurants[i][0])
            tempArr.push(restaurants[i+1][0])
            i++
        }
        else{
            if(tempArr.length>0){
                tempArr.sort((a,b)=>b-a)
                result =[...result,...tempArr]    
                tempArr=[]
            }            
            result.push(restaurants[i][0])
        }
            
    }
        
    return result
};
