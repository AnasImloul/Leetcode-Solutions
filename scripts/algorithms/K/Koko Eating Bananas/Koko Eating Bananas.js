// Runtime: 74 ms (Top 53.9%) | Memory: 45.22 MB (Top 51.1%)

var minEatingSpeed = function(piles, h) {
    /*The range of bananas that Koko can eat is k = 1 to Max(piles)*/
    let startk = 1;
    let endk = Math.max(...piles);
    
    while(startk <= endk){
        let midk = Math.floor(startk + (endk - startk)/2);
        /*midk are the count of bananas that koko decide to eat. 
        So how many hours she will take to finish the piles?*/
        let hrs = 0;
        for(let pile of piles){
            /*pile is the num of bananas in piles*/
            hrs += Math.ceil(pile/midk);
        }
        if(hrs > h){
            /*Now if hrs > h she will not be to finish the pile so we have 
            to increase the bananas by moving start.*/
            startk = midk + 1;
        }else{
            /*If hrs <= h she will be eating too fast so we can reduce the bananas 
            so she eats slowly. So decrement end.*/
            endk = midk - 1;
        }
    }
    return startk;
};